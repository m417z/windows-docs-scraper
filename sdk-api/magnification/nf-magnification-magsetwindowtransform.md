# MagSetWindowTransform function

## Description

Sets the transformation matrix for a magnifier control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `pTransform` [out]

Type: **[PMAGTRANSFORM](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magtransform)**

A transformation matrix.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

The transformation matrix specifies the magnification factor that the magnifier control applies to the contents of the source rectangle.

#### Examples

The following example shows how to set the magnification factor for a magnifier control.

```cpp
// Description:
//   Sets the magnification factor for a magnifier control.
// Parameters:
//   hwndMag - Handle of the magnifier control.
//   magFactor - New magnification factor.
//
BOOL SetMagnificationFactor(HWND hwndMag, float magFactor)
{
    MAGTRANSFORM matrix;
    memset(&matrix, 0, sizeof(matrix));
    matrix.v[0][0] = magFactor;
    matrix.v[1][1] = magFactor;
    matrix.v[2][2] = 1.0f;

    return MagSetWindowTransform(hwndMag, &matrix);
}

```

## See also

[MagGetWindowTransform](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetwindowtransform)