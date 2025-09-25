# HueSaturationLightnessParams structure

## Description

The **HueSaturationLightnessParams** structure contains members that specify hue, saturation and lightness adjustments to a bitmap.

You can adjust the hue, saturation, and lightness of a bitmap by following these steps.

1. Create and initialize a **HueSaturationLightnessParams** structure.
2. Pass the address of the **HueSaturationLightnessParams** structure to the [HueSaturationLightness::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-huesaturationlightness-setparameters) method of a [HueSaturationLightness](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-huesaturationlightness) object.
3. Pass the address of the [HueSaturationLightness](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-huesaturationlightness) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Members

### `hueLevel`

Type: **INT**

Integer in the range -180 through 180 that specifies the change in hue. A value of 0 specifies no change. Positive values specify counterclockwise rotation on the color wheel. Negative values specify clockwise rotation on the color wheel.

### `saturationLevel`

Type: **INT**

Integer in the range -100 through 100 that specifies the change in saturation. A value of 0 specifies no change. Positive values specify increased saturation and negative values specify decreased saturation.

### `lightnessLevel`

Type: **INT**

Integer in the range -100 through 100 that specifies the change in lightness. A value of 0 specifies no change. Positive values specify increased lightness and negative values specify decreased lightness.