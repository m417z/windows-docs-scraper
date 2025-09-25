# BlurParams structure

## Description

A **BlurParams** structure contains members that specify the nature of a Gaussian blur.

 You can apply a Gaussian blur effect to a bitmap by following these steps.

1. Create and initialize a **BlurParams** structure.
2. Pass the address of the **BlurParams** structure to the [Blur::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-blur-setparameters) method of a [Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur) object.
3. Pass the address of the [Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `radius`

Type: **float**

Real number that specifies the blur radius (the radius of the Gaussian convolution kernel) in pixels. The radius must be in the range 0 through 255. As the radius increases, the resulting bitmap becomes more blurry.

### `expandEdge`

Type: **BOOL**

Boolean value that specifies whether the bitmap expands by an amount equal to the blur radius. If **TRUE**, the bitmap expands by an amount equal to the radius so that it can have soft edges. If **FALSE**, the bitmap remains the same size and the soft edges are clipped.

## Remarks

One of the two [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) methods blurs a bitmap in place. That particular [Bitmap::ApplyEffect](https://learn.microsoft.com/previous-versions/ms536321(v=vs.85)) method ignores the **expandEdge** parameter.