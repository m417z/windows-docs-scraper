# ColorBalance::GetParameters

## Description

The **ColorBalance::GetParameters** method gets the current values of the parameters of this [ColorBalance](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorbalance) object.

## Parameters

### `size` [in]

Type: **UINT***

Pointer to a **UINT** that specifies the size, in bytes, of a [ColorBalanceParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorbalanceparams) structure.

### `parameters` [out]

Type: **[ColorBalanceParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorbalanceparams)***

Pointer to a [ColorBalanceParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-colorbalanceparams) structure that receives the parameter values.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[ColorBalance](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-colorbalance)

[ColorBalance::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-colorbalance-setparameters)