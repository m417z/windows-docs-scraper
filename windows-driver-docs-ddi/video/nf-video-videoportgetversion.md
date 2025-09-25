# VideoPortGetVersion function

## Description

The **VideoPortGetVersion** function gets version information about the currently running operating system.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pVpOsVersionInfo` [in, out]

Pointer to a [VPOSVERSIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vposversioninfo) structure that will receive the operating system version information. The caller should set the **Size** member of the VPOSVERSIONINFO structure to the size, in bytes, of that structure.

## Return value

**VideoPortGetVersionInfo** returns NO_ERROR if it successfully obtained the operating system version information. If the **Size** member of the VPOSVERSIONINFO does not contains the correct size of this structure, the function returns ERROR_INVALID_PARAMETER

## See also

[VPOSVERSIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vposversioninfo)