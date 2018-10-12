/* OpenHoW
 * Copyright (C) 2017-2018 Mark Sowden <markelswo@gmail.com>
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

#pragma once

#include <PL/platform_graphics_camera.h>

enum {
    TEXTURE_INDEX_BRITISH,
    TEXTURE_INDEX_AMERICAN,
    TEXTURE_INDEX_FRENCH,
    TEXTURE_INDEX_GERMAN,
    TEXTURE_INDEX_RUSSIAN,
    TEXTURE_INDEX_JAPANESE,
    TEXTURE_INDEX_TEAMLARD,

    TEXTURE_INDEX_GOBS,

    TEXTURE_INDEX_WEAPONS,
    TEXTURE_INDEX_MAP,

    MAX_TEXTURE_INDEX
};

PL_EXTERN_C

void InitDisplay(void);
void ShutdownDisplay(void);
void UpdateDisplay(void);

void UpdateViewport(int x, int y, int width, int height);

int GetViewportWidth(const PLViewport *viewport);
int GetViewportHeight(const PLViewport *viewport);

void ClearTextureIndex(unsigned int id);
void CacheTextureIndex(const char *path, const char *index_name, unsigned int id);
void GetCachedTextureCoords(unsigned int id, unsigned int tex_id, int *x, int *y, unsigned int *w, unsigned int *h);
const PLTexture *GetCachedTexture(unsigned int id);

PLTexture *LoadTexture(const char *path, PLTextureFilter filter);

PL_EXTERN_C_END