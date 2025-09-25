# IOCTL_HID_DEVICERESET_NOTIFICATION IOCTL

## Description

The **IOCTL_HID_DEVICERESET_NOTIFICATION**
request is sent by the HID client driver to HID class driver to wait for a device-initiated reset event. This request can also be sent by the HID Class driver to the HID Minidriver to wait for a device-initiated reset event.

Only one device reset notification request is allowed at any one time.

A HID minidriver can enable this feature by adding a registry value in the INF file. The **DeviceResetNotificationEnabled** under the device's hardware key must be set to 1 to enable the feature. Here is an example:

`[hidi2c_Device.NT.HW]
AddReg = hidi2c_Device.Filter.AddReg, hidi2c_Device.Configuration.AddReg`

...

`[hidi2c_Device.Configuration.AddReg]`

...

`HKR,,"DeviceResetNotificationEnabled",0x00010001,1`

## Parameters

### Major code

### Input buffer

 None.

### Input buffer length

None.

### Output buffer

 None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

I**rp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, Status to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.