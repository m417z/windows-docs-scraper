# WdsCliGetEnumerationFlags function

## Description

Returns the image enumeration flag for the current image handle.

## Parameters

### `Handle` [in]

A find handle returned by the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function. The image referenced by the find handle can be advanced using the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function.

### `pdwFlags` [out]

A pointer to a value that receives the enumeration flag value.

This parameter can have the following values

| Value | Meaning |
| --- | --- |
| **WdsCliFlagEnumFilterVersion**<br><br>1 | The WDS client only shows images that have the same version as the boot image. |

## Return value

If the function succeeds, the return is **S_OK**.

## See also

[WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)