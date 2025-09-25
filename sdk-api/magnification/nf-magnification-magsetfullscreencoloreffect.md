# MagSetFullscreenColorEffect function

## Description

Changes the color transformation matrix associated with the full-screen magnifier.

## Parameters

### `pEffect` [in]

Type: **[PMAGCOLOREFFECT](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magcoloreffect)**

The new color transformation matrix. This parameter must not be NULL.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns TRUE if successful, or FALSE otherwise.

## Remarks

The full-screen magnifier uses the color transformation matrix to apply a color effect to the entire desktop. If the function is called multiple times, the most recent color transform is used.

#### Examples

The following example defines two color transformation matrices for use with **MagSetFullscreenColorEffect**. The `g_MagEffectGrayscale` matrix converts the screen colors to grayscale. The `g_MagEffectIdentity` matrix is the identity matrix, which restores the original screen colors.

```cpp
// Initialize color transformation matrices used to apply grayscale and to
// restore the original screen color.
MAGCOLOREFFECT g_MagEffectGrayscale = {0.3f,  0.3f,  0.3f,  0.0f,  0.0f,
                                       0.6f,  0.6f,  0.6f,  0.0f,  0.0f,
                                       0.1f,  0.1f,  0.1f,  0.0f,  0.0f,
                                       0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                                       0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

MAGCOLOREFFECT g_MagEffectIdentity = {1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
                                      0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
                                      0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
                                      0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
                                      0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

BOOL SetColorGrayscale(__in BOOL fGrayscaleOn)
{
    // Apply the color matrix required to either apply grayscale to the screen
    // colors or to show the regular colors.
    PMAGCOLOREFFECT pEffect =
                (fGrayscaleOn ? &g_MagEffectGrayscale : &g_MagEffectIdentity);

    return MagSetFullscreenColorEffect(pEffect);
}

```

## See also

[MagGetFullscreenColorEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetfullscreencoloreffect)