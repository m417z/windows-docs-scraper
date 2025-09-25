# MagGetFullscreenColorEffect function

## Description

Retrieves the color transformation matrix associated with the full-screen magnifier.

## Parameters

### `pEffect` [out]

Type: **[PMAGCOLOREFFECT](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magcoloreffect)**

The color transformation matrix, or the identity matrix if no color effect has been set.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns TRUE if successful, or FALSE otherwise.

## Remarks

The full-screen magnifier uses the color transformation matrix to apply a color effect to the entire screen.

#### Examples

The following example retrieves the color transformation matrix associated with the full-screen magnifier.

```cpp
        // Get the current color effect.
        MAGCOLOREFFECT magEffect;

        if (!MagGetFullscreenColorEffect(&magEffect))
            return E_FAIL;

```

## See also

[MagSetFullscreenColorEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetfullscreencoloreffect)