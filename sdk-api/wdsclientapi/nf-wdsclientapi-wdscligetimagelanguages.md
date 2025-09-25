# WdsCliGetImageLanguages function

## Description

Returns an array of languages supported by the current image.

## Parameters

### `hIfh` [in]

A find handle returned by the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function. The image referenced by the find handle can be advanced using the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function.

### `pppszValues` [out]

A pointer to a pointer to an array of null-terminated string values. Each element in the
array contains a language of the current
image.

### `pdwNumValues` [out]

Pointer to a value that contains the number of languages in the *pppszValues* parameter.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This value
is valid until the
[WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) or
[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function is used to change or close the
current handle.

## See also

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)