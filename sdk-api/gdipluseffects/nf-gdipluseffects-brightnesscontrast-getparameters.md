# BrightnessContrast::GetParameters

## Description

The **BrightnessContrast::GetParameters** method gets the current values of the parameters of this [BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [BrightnessContrastParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-brightnesscontrastparams) structure.

### `parameters` [out]

Type: **[BrightnessContrastParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-brightnesscontrastparams)***

Pointer to a [BrightnessContrastParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-brightnesscontrastparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[BrightnessContrast](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-brightnesscontrast)

[BrightnessContrast::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-brightnesscontrast-setparameters)