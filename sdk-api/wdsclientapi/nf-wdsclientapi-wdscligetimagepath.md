# WdsCliGetImagePath function

## Description

Returns the path to the file that contains the current image.

## Parameters

### `hIfh` [in]

A find handle returned by the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function. The image referenced by the find handle can be advanced using the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function.

### `ppwszValue` [out]

A pointer to a pointer to a null-terminated string that contains the relative path of the image file for the current image.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This value
is valid until the
[WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) or
[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function is used to change or close the
current handle.

To obtain the full path to the
image file, prefix the relative path returned in *ppWszValue* with "\\*Server*\\RemInst\".

## See also

[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose)

[WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage)

[WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)