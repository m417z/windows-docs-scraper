# MagGetColorEffect function

## Description

 Gets the color transformation matrix for a magnifier control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `pEffect` [out]

Type: **[PMAGCOLOREFFECT](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magcoloreffect)**

The color transformation matrix, or **NULL** if no color effect has been set.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

The magnifier control uses the color transformation matrix to apply a color effect to the entire magnifier window.

This function requires Windows Display Driver Model (WDDM)-capable video cards.

#### Examples

The following example retrieves the color transformation matrix.

```cpp
// Description:
//   Retrieves the color transformation matrix from a magnifier control.
// Parameters:
//   hwndMag - handle of the magnifier control.
//
BOOL GetMagnifierColorTransform(HWND hwndMag)
{
    MAGCOLOREFFECT effect;

    BOOL ret = MagGetColorEffect(hwndMag, &effect);

    //
    // Do something with the color data.
    //

    return ret;
}

```

## See also

[MagSetColorEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetcoloreffect)