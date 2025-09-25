# DevicePowerSetDeviceState function

## Description

Modifies the specified data on the specified device.

## Parameters

### `DeviceDescription` [in]

The name or hardware identifier string of the device to be modified.

### `SetFlags` [in]

The properties of the device that are to be modified.

| Value | Meaning |
| --- | --- |
| **DEVICEPOWER_SET_WAKEENABLED**<br><br>0x00000001 | Enables the specified device to wake the system. |
| **DEVICEPOWER_CLEAR_WAKEENABLED**<br><br>0x00000002 | Stops the specified device from being able to wake the system. |

### `SetData` [in]

Reserved, must be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Device Power Management](https://learn.microsoft.com/windows/desktop/Power/device-power-management)