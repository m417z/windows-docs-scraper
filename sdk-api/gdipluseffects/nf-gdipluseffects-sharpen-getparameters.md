# Sharpen::GetParameters

## Description

The **Sharpen::GetParameters** method gets the current values of the parameters of this [Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [SharpenParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-sharpenparams) structure.

### `parameters` [out]

Type: **[SharpenParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-sharpenparams)***

Pointer to a [SharpenParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-sharpenparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Sharpen](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-sharpen)

[Sharpen::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-sharpen-setparameters)