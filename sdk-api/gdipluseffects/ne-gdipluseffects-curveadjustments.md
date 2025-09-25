# CurveAdjustments enumeration

## Description

The [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) class encompasses the eight bitmap adjustments listed in the **CurveAdjustments** enumeration.

To apply one of the eight adjustments to a bitmap, follow these steps.

1. Create a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) structure, and set its **adjustment** member to one of the elements of the **CurveAdjustments** enumeration.
2. Set the other two members (**adjustValue** and **channel**) of the [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) structure.
3. Pass the address of the [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) structure to the [ColorCurve::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorcurve-setparameters) method of a [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) object.
4. Pass the address of the [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) object to the [Graphics::DrawImage](https://learn.microsoft.com/previous-versions/ms536058(v=vs.85)) method or to the [Bitmap::ApplyEffect](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-applyeffect(inbitmap_inint_ineffect_inrect_outrect_outbitmap)) method.

## Constants

### `AdjustExposure`

Simulates increasing or decreasing the exposure of a photograph. When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustExposure](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range -255 through 255. A value of 0 specifies no change in exposure. Positive values specify increased exposure and negative values specify decreased exposure.

### `AdjustDensity`

Simulates increasing or decreasing the film density of a photograph. When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustDensity](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range -255 through 255. A value of 0 specifies no change in density. Positive values specify increased density (lighter picture) and negative values specify decreased density (darker picture).

### `AdjustContrast`

Increases or decreases the contrast of a bitmap. When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range -100 through 100. A value of 0 specifies no change in contrast. Positive values specify increased contrast and negative values specify decreased contrast.

### `AdjustHighlight`

Increases or decreases the value of a color channel if that channel already has a value that is above half intensity. You can use this adjustment to get more definition in the light areas of an image without affecting the dark areas. When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustHighlight](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range -100 through 100. A value of 0 specifies no change. Positive values specify that the light areas are made lighter, and negative values specify that the light areas are made darker.

### `AdjustShadow`

Increases or decreases the value of a color channel if that channel already has a value that is below half intensity. You can use this adjustment to get more definition in the dark areas of an image without affecting the light areas. When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustShadow](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range -100 through 100. A value of 0 specifies no change. Positive values specify that the dark areas are made lighter, and negative values specify that the dark areas are made darker.

### `AdjustMidtone`

Lightens or darkens an image. Color channel values in the middle of the intensity range are altered more than color channel values near the minimum or maximum intensity. You can use this adjustment to lighten (or darken) an image without loosing the contrast between the darkest and lightest portions of the image. When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustMidtone](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range -100 through 100. A value of 0 specifies no change. Positive values specify that the midtones are made lighter, and negative values specify that the midtones are made darker.

### `AdjustWhiteSaturation`

When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustWhiteSaturation](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range 0 through 255. A value of t specifies that the interval [0, t] is mapped linearly to the interval [0, 255]. For example, if **adjustValue** is equal to 240, then color channel values in the interval [0, 240] are adjusted so that they spread out over the interval [0, 255]. Color channel values greater than 240 are set to 255.

### `AdjustBlackSaturation`

When you set the **adjustment** member of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) object to [AdjustBlackSaturation](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ne-gdipluseffects-curveadjustments), you should set the **adjustValue** member to an integer in the range 0 through 255. A value of t specifies that the interval [t, 255] is mapped linearly to the interval [0, 255]. For example, if **adjustValue** is equal to 15, then color channel values in the interval [15, 255] are adjusted so that they spread out over the interval [0, 255]. Color channel values less than 15 are set to 0.