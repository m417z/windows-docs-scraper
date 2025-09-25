# Effect::GetParameterSize

## Description

The **Effect::GetParameterSize** method gets the total size, in bytes, of the parameters currently set for this [Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect). The **Effect::GetParameterSize** method is usually called on an object that is an instance of a descendant of the **Effect** class.

## Parameters

### `size` [out]

Type: **UINT***

Pointer to a UINT that receives the total size of the parameters.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Effect](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-effect)

[SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-redeyecorrection-setparameters)