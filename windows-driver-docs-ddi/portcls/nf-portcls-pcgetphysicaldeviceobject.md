# PcGetPhysicalDeviceObject function

## Description

The **PcGetPhysicalDeviceObject** function enables audio miniport drivers to retrieve the underlying physical device object of the audio device.

## Parameters

### `pDeviceObject` [in]

Pointer to the device object for the device.

### `ppPhysicalObject` [out]

Pointer to the physical object for the device.

## Return value

The **PcGetPhysicalDeviceObject** function returns STATUS_SUCCESS if the function call was successful. Otherwise, it returns the appropriate error code.

## See also

[Audio Port Class Functions](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-port-class-functions)