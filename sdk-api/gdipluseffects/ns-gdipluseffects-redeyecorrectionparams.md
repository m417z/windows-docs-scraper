# RedEyeCorrectionParams structure

## Description

A **RedEyeCorrectionParams** structure contains members that specify the areas of a bitmap to which a red-eye correction is applied.

You can correct red eyes in a bitmap by following these steps.

1. Create and initialize a **RedEyeCorrectionParams** structure.
2. Pass the address of the **RedEyeCorrectionParams** structure to the [RedEyeCorrection::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-redeyecorrection-setparameters) method of a [RedEyeCorrection](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-redeyecorrection) object.
3. Pass the address of the [RedEyeCorrection](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-redeyecorrection) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `numberOfAreas`

Type: **UINT**

Integer that specifies the number of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures in the **areas** array.

### `areas`

Type: **RECT***

Pointer to an array of [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structures, each of which specifies an area of the bitmap to which red eye correction should be applied.