# Blur::GetParameters

## Description

The **Blur::GetParameters** method gets the current values of the parameters of this [Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [BlurParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-blurparams) structure.

### `parameters` [out]

Type: **[BlurParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-blurparams)***

Pointer to a [BlurParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-blurparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur)

[Blur::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-blur-setparameters)

[Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen)