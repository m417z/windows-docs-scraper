# SharpenParams structure

## Description

The **SharpenParams** structure contains members that specify the nature of a sharpening adjustment to a bitmap.

You can adjust the sharpness of a bitmap by following these steps.

1. Create and initialize a **SharpenParams** structure.
2. Pass the address of the **SharpenParams** structure to the [Sharpen::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-sharpen-setparameters) method of a [Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen) object.
3. Pass the address of the [Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `radius`

Type: **REAL**

Real number that specifies the sharpening radius (the radius of the convolution kernel) in pixels. The radius must be in the range 0 through 255. As the radius increases, more surrounding pixels are involved in calculating the new value of a given pixel.

### `amount`

Type: **REAL**

Real number in the range 0 through 100 that specifies the amount of sharpening to be applied. A value of 0 specifies no sharpening. As the value of **amount** increases, the sharpness increases.