# BrightnessContrastParams structure

## Description

A **BrightnessContrastParams** structure contains members that specify the nature of a brightness or contrast adjustment.

You can change the brightness or contrast (or both) of a bitmap by following these steps.

1. Create and initialize a **BrightnessContrastParams** structure.
2. Pass the address of the **BrightnessContrastParams** structure to the [BrightnessContrast::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-brightnesscontrast-setparameters) method of a [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object.
3. Pass the address of the [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `brightnessLevel`

Type: **INT**

Integer in the range -255 through 255 that specifies the brightness level. If the value is 0, the brightness remains the same. As the value moves from 0 to 255, the brightness of the image increases. As the value moves from 0 to -255, the brightness of the image decreases.

### `contrastLevel`

Type: **INT**

Integer in the range -100 through 100 that specifies the contrast level. If the value is 0, the contrast remains the same. As the value moves from 0 to 100, the contrast of the image increases. As the value moves from 0 to -100, the contrast of the image decreases.