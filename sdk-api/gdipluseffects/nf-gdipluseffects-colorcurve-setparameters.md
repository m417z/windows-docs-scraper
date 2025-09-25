# ColorCurve::SetParameters

## Description

The **ColorCurve::SetParameters** method sets the parameters of this [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) object.

## Parameters

### `parameters` [in]

Type: **const [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams)***

Pointer to a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) structure that specifies the parameters.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve)

[ColorCurve::GetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorcurve-getparameters)