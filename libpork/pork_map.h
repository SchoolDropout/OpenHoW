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

#define MAP_MODE_SINGLEPLAYER   (1 << 1)
#define MAP_MODE_DEATHMATCH     (1 << 2)

#define MAP_MODE_SURVIVAL_NOVICE    (1 << 3)
#define MAP_MODE_SURVIVAL_EXPERT    (1 << 4)
#define MAP_MODE_SURVIVAL_STRATEGY  (1 << 5)

#define MAP_MODE_GENERATED  (1 << 6)

void InitMaps(void);
void ShutdownMaps(void);

void UnloadMap(void);
void ResetMap(void);
void LoadMap(const char *name, unsigned int mode);
void DrawMap(void);