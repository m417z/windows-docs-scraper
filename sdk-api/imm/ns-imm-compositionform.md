# COMPOSITIONFORM structure

## Description

Contains style and position information for a composition window.

## Members

### `dwStyle`

Position style. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| CFS_DEFAULT | Move the composition window to the default position. The IME window can display the composition window outside the client area, such as in a floating window. |
| CFS_FORCE_POSITION | Display the upper left corner of the composition window at exactly the position specified by **ptCurrentPos**. The coordinates are relative to the upper left corner of the window containing the composition window and are not subject to adjustment by the IME. |
| CFS_POINT | Display the upper left corner of the composition window at the position specified by **ptCurrentPos**. The coordinates are relative to the upper left corner of the window containing the composition window and are subject to adjustment by the IME. |
| CFS_RECT | Display the composition window at the position specified by **rcArea**. The coordinates are relative to the upper left of the window containing the composition window. |

### `ptCurrentPos`

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the coordinates of the upper left corner of the composition window.

### `rcArea`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the upper left and lower right corners of the composition window.

## Remarks

Some IME windows adjust the composition window position specified by the system or the application. The CFS_FORCE_POSITION directs the IME window to skip this adjustment.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)