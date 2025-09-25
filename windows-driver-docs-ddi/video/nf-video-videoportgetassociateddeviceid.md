# VideoPortGetAssociatedDeviceID function

## Description

The **VideoPortGetAssociatedDeviceID** function obtains the child ID for a specified device object.

## Parameters

### `DeviceObject` [in]

Pointer to the child device object, a [PDO](https://learn.microsoft.com/windows-hardware/drivers/).

## Return value

**VideoPortGetAssociatedDeviceID** returns the child ID for the given device object.

## Remarks

**VideoPortGetAssociatedDeviceID** can be used to obtain the child ID for a child device object. For example, this is useful with [I2C](https://learn.microsoft.com/windows-hardware/drivers/). See [Using I2C to Communicate with a Child Device](https://learn.microsoft.com/windows-hardware/drivers/display/using-i2c-to-communicate-with-a-child-device) for more information.