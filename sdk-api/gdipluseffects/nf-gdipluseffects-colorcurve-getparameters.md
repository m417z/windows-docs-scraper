# ColorCurve::GetParameters

## Description

The **ColorCurve::GetParameters** gets the current values of the parameters of this [ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) structure.

### `parameters` [out]

Type: **[ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams)***

Pointer to a [ColorCurveParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorcurveparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[ColorCurve](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorcurve)

[ColorCurve::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorcurve-setparameters)