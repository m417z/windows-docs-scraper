# GetDevicePowerState function

## Description

Retrieves the current power state of the specified device. This function cannot be used to query the power state of a display device.

## Parameters

### `hDevice` [in]

A handle to an object on the device, such as a file or socket, or a handle to the device itself.

### `pfOn` [out]

A pointer to the variable that receives the
[power state](https://learn.microsoft.com/windows/desktop/Power/system-power-states). This value is **TRUE** if the device is in the working state. Otherwise, it is **FALSE**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application can use
**GetDevicePowerState** to determine whether a device is in the working state or a low-power state. If the device is in a low-power state, accessing the device may cause it to either queue or fail any I/O requests, or transition the device into the working state. The exact behavior depends on the implementation of the device.

To ensure maximum battery life on a laptop computer, use
**GetDevicePowerState** to reduce power consumption. For example, if a disk is currently powered down, accessing the disk will cause it to spin up, resulting in increased power consumption and reduced battery life.

Applications should defer or limit access to devices wherever possible while the system is running on battery power. To determine whether the system is running on battery power, and the remaining battery life, use the
[GetSystemPowerStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystempowerstatus) function.

## See also

[GetSystemPowerStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystempowerstatus)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[System Power Status](https://learn.microsoft.com/windows/desktop/Power/system-power-status)