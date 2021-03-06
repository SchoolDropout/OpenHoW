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

#ifdef __cplusplus

#include <imgui.h>

#endif

/************************************************************/

PL_EXTERN_C

void ImGuiImpl_SetupCamera(void);
void ImGuiImpl_SetupFrame(void);
void ImGuiImpl_Draw(void);
void ImGuiImpl_UpdateViewport(int w, int h);

void UI_DisplayDebugMenu(void);

PL_EXTERN_C_END
