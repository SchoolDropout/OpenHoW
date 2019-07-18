/* OpenHoW
 * Copyright (C) 2017-2019 Mark Sowden <markelswo@gmail.com>
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

class TextureAtlas {
 public:
  TextureAtlas();
  ~TextureAtlas();

  size_t GetSize();

  void GetTextureCoords(const std::string &name, float *x, float *y, float *w, float *h);

  void AddImage(const std::string &path);
  void AddImages(const std::vector<std::string> &textures);

  void Finalize();

  PLTexture *GetTexture() { return texture_; }

 protected:
 private:
  struct Index {
    unsigned int x, y, w, h;
    PLImage *image;
  };

  std::map<std::string, Index> textures_;
  std::map<std::string, PLImage *> images_by_name_;
  std::multimap<unsigned int, PLImage *> images_by_height_;

  PLTexture *texture_{nullptr};
};