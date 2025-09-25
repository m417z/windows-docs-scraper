# MagGetWindowTransform function

## Description

Retrieves the transformation matrix associated with a magnifier control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `pTransform` [out]

Type: **[PMAGTRANSFORM](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magtransform)**

The transformation matrix.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

The transformation matrix specifies the magnification factor that the magnifier control applies to the contents of the source rectangle.

## See also

[MagSetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowtransform)