# MagSetColorEffect function

## Description

Sets the color transformation matrix for a magnifier control.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `pEffect` [in]

Type: **[PMAGCOLOREFFECT](https://learn.microsoft.com/windows/desktop/api/magnification/ns-magnification-magcoloreffect)**

The color transformation matrix, or **NULL** to remove the current color effect, if any.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

The magnifier control uses the color transformation matrix to apply a color effect to the entire magnifier window. If the function is called multiple times, the most recent color transform is used.

This function requires Windows Display Driver Model (WDDM)-capable video cards.

#### Examples

The following example sets a color transformation matrix that converts the colors displayed in the magnifier to grayscale.

```cpp
// Description:
//   Converts the colors displayed in the magnifier window to grayscale, or
//   returns the colors to normal.
// Parameters:
//   hwndMag - Handle of the magnifier control.
//   fInvert - TRUE to convert to grayscale, or FALSE for normal colors.
//
BOOL ConvertToGrayscale(HWND hwndMag, BOOL fConvert)
{
    // Convert the screen colors in the magnifier window.
    if (fConvert)
    {
        MAGCOLOREFFECT magEffectGrayscale =
            {{ // MagEffectGrayscale
                {  0.3f,  0.3f,  0.3f,  0.0f,  0.0f },
                {  0.6f,  0.6f,  0.6f,  0.0f,  0.0f },
                {  0.1f,  0.1f,  0.1f,  0.0f,  0.0f },
                {  0.0f,  0.0f,  0.0f,  1.0f,  0.0f },
                {  0.0f,  0.0f,  0.0f,  0.0f,  1.0f }
            }};

        return MagSetColorEffect(hwndMag, &magEffectGrayscale);
    }

    // Return the colors to normal.
    else
    {
        return MagSetColorEffect(hwndMag, NULL);
    }
}

```

## See also

[MagGetColorEffect](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-maggetcoloreffect)