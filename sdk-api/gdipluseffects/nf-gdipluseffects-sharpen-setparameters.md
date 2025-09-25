# Sharpen::SetParameters

## Description

The **Sharpen::SetParameters** method sets the parameters of this [Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen) object.

## Parameters

### `parameters` [in]

Type: **const [SharpenParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-sharpenparams)***

Pointer to a [SharpenParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-sharpenparams) structure that specifies the parameters.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen)

[Sharpen::GetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-sharpen-getparameters)