# VideoPortGetVgaStatus function

## Description

The **VideoPortGetVgaStatus** function detects whether the calling device is decoding a VGA I/O address.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `VgaStatus` [out]

Pointer to the resulting VGA status. A value of zero (0) indicates that VGA is not enabled; a value of one (1) indicates that VGA is enabled.

## Return value

**VideoPortGetVgaStatus** returns one of the following values:

|Return code|Description|
|--- |--- |
|NO_ERROR|The function completed successfully.|
|ERROR_INVALID_FUNCTION|The device was not a PCI device.|

## Remarks

The **VideoPortGetVgaStatus** function is mainly used to determine whether a device is the sole VGA-enabled device in a [multiple monitor](https://learn.microsoft.com/windows-hardware/drivers/display/multiple-monitor-support-in-the-display-driver) system.