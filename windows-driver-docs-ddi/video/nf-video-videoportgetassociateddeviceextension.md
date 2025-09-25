# VideoPortGetAssociatedDeviceExtension function

## Description

The **VideoPortGetAssociatedDeviceExtension** function returns the device extension for the parent of the specified device object.

## Parameters

### `DeviceObject` [in]

Is the device object of a child device.

## Return value

**VideoPortGetAssociatedDeviceExtension** returns a pointer to the device extension of *DeviceObject*'s parent.

## Remarks

The miniport driver of a child device can call this function to obtain a description of its parent through the parent's device extension.