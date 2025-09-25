# Tint::GetParameters

## Description

The **Tint::GetParameters** method gets the current values of the parameters of this [Tint](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-tint) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [TintParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-tintparams) structure.

### `parameters` [out]

Type: **[TintParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-tintparams)***

Pointer to a [TintParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-tintparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Tint](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-tint)

[Tint::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-tint-setparameters)