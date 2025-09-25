## Description

Sets the size, in visual space, taken by each letterbox area.

## Parameters

### `leftLetterboxSize`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the left margin of the letterbox area.

### `topLetterboxSize`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the top margin of the letterbox area.

### `rightLetterboxSize`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the right margin of the letterbox area.

### `bottomLetterboxSize`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the bottom margin of the letterbox area.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

Margins are not affected by the scale component of the transform, but are affected by every other component. Put another way, the margins are applied with the transform applied, but compensate their own size by any scale present in that transform.

## See also