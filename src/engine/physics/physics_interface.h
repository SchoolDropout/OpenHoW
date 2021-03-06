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

#pragma once

enum class PhysicsPrimitiveType {
  SPHERE,
  BOX,
  CAPSULE,
  CYLINDER,
  CONE,
  CHAMFER_CYLINDER,
  RANDOM_CONVEX_HULL,
  REGULAR_CONVEX_HULL,
  COMPOUND_CONVEX_CRUZ,
};

class IPhysicsBody {
 public:
 protected:
  IPhysicsBody() = default;
  virtual ~IPhysicsBody() = default;

 private:
};

class IPhysicsInterface {
 public:
  static IPhysicsInterface* CreateInstance();
  static void DestroyInstance(IPhysicsInterface* instance);

  virtual void Tick() = 0;

  virtual IPhysicsBody* CreatePhysicsBody() = 0;
  virtual void DestroyPhysicsBody(IPhysicsBody* body) = 0;

  virtual void GenerateTerrainCollision(std::vector<float> vertices) = 0;
  virtual void DestroyTerrainCollision() = 0;

 protected:
  IPhysicsInterface() = default;
  virtual ~IPhysicsInterface() = default;

 private:
};
