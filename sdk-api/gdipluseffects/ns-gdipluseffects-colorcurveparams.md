# ColorCurveParams structure

## Description

A **ColorCurveParams** structure contains members that specify an adjustment to the colors of a bitmap.

The [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) class encompasses eight separate adjustments: exposure, density, contrast, highlight, shadow, midtone, white saturation, and black saturation. You can apply one of those adjustments to a bitmap by following these steps.

1. Create and initialize a **ColorCurveParams** structure.
2. Pass the address of the **ColorCurveParams** structure to the [ColorCurve::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorcurve-setparameters) method of a [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) object.
3. Pass the address of the [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `adjustment`

Type: **[CurveAdjustments](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments)**

Element of the [CurveAdjustments](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments) enumeration that specifies the adjustment to be applied.

### `channel`

Type: **[CurveChannel](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curvechannel)**

Element of the [CurveChannel](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curvechannel) enumeration that specifies the color channel to which the adjustment applies.

### `adjustValue`

Type: **INT**

Integer that specifies the intensity of the adjustment. The range of acceptable values depends on which adjustment is being applied. To see the range of acceptable values for a particular adjustment, see the [CurveAdjustments](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments) enumeration.