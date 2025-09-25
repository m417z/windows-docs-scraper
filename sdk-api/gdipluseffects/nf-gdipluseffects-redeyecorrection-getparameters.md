# RedEyeCorrection::GetParameters

## Description

The **RedEyeCorrection::GetParameters** method gets the current values of the parameters of this [RedEyeCorrection](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-redeyecorrection) object.

## Parameters

### `size` [in]

Type: **UINT***

The size, in bytes, of the buffer pointed to by the *parameters* parameter.

### `parameters` [out]

Type: **[RedEyeCorrectionParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-redeyecorrectionparams)***

Pointer to a buffer that is large enough to receive a [RedEyeCorrectionParams](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/ns-gdipluseffects-redeyecorrectionparams) structure followed by an array of RECT structures. To determine the total size of the required buffer, call the GetParameterSize method of the [RedEyeCorrection](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-redeyecorrection) object whose parameters you want to retrieve.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[RedEyeCorrection](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nl-gdipluseffects-redeyecorrection)

[RedEyeCorrection::SetParameters](https://learn.microsoft.com/windows/desktop/api/gdipluseffects/nf-gdipluseffects-redeyecorrection-setparameters)