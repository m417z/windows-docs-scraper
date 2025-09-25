# CANDIDATEFORM structure

## Description

Contains position information for the candidate window.

## Members

### `dwIndex`

Candidate list identifier. It is 0 for the first list, 1 for the second, and so on. The maximum index is 3.

### `dwStyle`

Position style. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| CFS_CANDIDATEPOS | Display the upper left corner of the candidate list window at the position specified by **ptCurrentPos**. The coordinates are relative to the upper left corner of the window containing the list window, and are subject to adjustment by the system. |
| CFS_EXCLUDE | Exclude the candidate window from the area specified by **rcArea**. The **ptCurrentPos** member specifies the coordinates of the current point of interest, typically the caret position. |

### `ptCurrentPos`

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the coordinates of the upper left corner of the candidate window or the caret position, depending on the value of **dwStyle**.

### `rcArea`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the upper left and lower right corners of the exclusion area.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)