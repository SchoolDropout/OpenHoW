/* OpenHoW
 * Copyright (C) 2017-2020 Mark Sowden <markelswo@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <PL/platform_filesystem.h>
#include <PL/platform_mesh.h>

#include "util.h"
#include "vtx.h"
#include "no2.h"

/************************************************************/
/* No2 Normals Format */

/**
 * @brief Loads in vertex normal data
 * @param path Path to the NO2 file
 * @param vertex_data Pointer to an existing VtxHandle which will be filled with normal data
 * @return Returns vertex_data on success, null on fail
 */
VtxHandle *No2_LoadFile(const char *path, VtxHandle *vertex_data) {
  PLFile *fp = plOpenFile(path, false);
  if (fp == NULL) {
    LogWarn("Failed to load no2 \"%s\"!\n", path);
    return NULL;
  }

  typedef struct __attribute__((packed)) No2Coord {
    float v[3];
    float bone_index;
  } No2Coord;
  unsigned int num_normals = (unsigned int) (plGetFileSize(fp) / sizeof(No2Coord));
  if (num_normals != vertex_data->num_vertices || num_normals == 0) {
    LogWarn("Invalid number of normals in \"%s\" (%d/%d)!\n", path, num_normals, vertex_data->num_vertices);
    plCloseFile(fp);
    return NULL;
  }

  No2Coord normals[num_normals];
  unsigned int rnum_normals = plReadFile(fp, normals, sizeof(No2Coord), num_normals);
  plCloseFile(fp);
  if (rnum_normals != num_normals) {
    LogWarn("Failed to read in all normals from \"%s\"!\n", path);
    return NULL;
  }

  for (unsigned int i = 0; i < vertex_data->num_vertices; ++i) {
    vertex_data->vertices[i].normal.x = normals[i].v[0];
    vertex_data->vertices[i].normal.y = normals[i].v[1];
    vertex_data->vertices[i].normal.z = normals[i].v[2];
  }

  return vertex_data;
}
