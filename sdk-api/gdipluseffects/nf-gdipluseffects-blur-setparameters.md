# Blur::SetParameters

## Description

The **Blur::SetParameters** method sets the parameters of this [Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur) object.

## Parameters

### `parameters` [in]

Type: **const [BlurParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-blurparams)***

Pointer to a [BlurParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-blurparams) structure that specifies the parameters.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Blur](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-blur)

[Blur::GetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-blur-getparameters)

[Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen)