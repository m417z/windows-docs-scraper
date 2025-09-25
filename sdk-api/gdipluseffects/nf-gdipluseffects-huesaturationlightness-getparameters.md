# HueSaturationLightness::GetParameters

## Description

The **HueSaturationLightness::GetParameters** method gets the current values of the parameters of this [HueSaturationLightness](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-huesaturationlightness) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size of a [HueSaturationLightnessParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-huesaturationlightnessparams) structure.

### `parameters` [out]

Type: **[HueSaturationLightnessParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-huesaturationlightnessparams)***

Pointer to a [HueSaturationLightnessParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-huesaturationlightnessparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[HueSaturationLightness](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-huesaturationlightness)

[HueSaturationLightness::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-huesaturationlightness-setparameters)