# WdsCliGetImageArchitecture function

## Description

Returns the processor architecture for the current image.

## Parameters

### `hIfh` [in]

A find handle returned by the [WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage) function. The image referenced by the find handle can be advanced using the [WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) function.

### `pdwValue` [out]

Pointer to a value that describes the processor architecture of the current image.

This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **PROCESSOR_ARCHITECTURE_AMD64**<br><br>9 | The image is an x64 image (AMD AMD64 or Intel EM64T). |
| **PROCESSOR_ARCHITECTURE_IA64**<br><br>6 | The image is an Itanium-based system image. |
| **PROCESSOR_ARCHITECTURE_INTEL**<br><br>0 | The image is a 32-bit Intel x86 image. |

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

This value
is valid until the
[WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage) or
[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function is used to change or close the
current handle.

## See also

[WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose)

[WdsCliFindFirstImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindfirstimage)

[WdsCliFindNextImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclifindnextimage)

[Windows Deployment Services Client Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-client-functions)