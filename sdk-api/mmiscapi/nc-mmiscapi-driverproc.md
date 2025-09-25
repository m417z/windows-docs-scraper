# DRIVERPROC callback function

## Description

Processes driver messages for the installable driver. **DriverProc** is a driver-supplied function.

## Parameters

### `unnamedParam1`

Identifier of the installable driver.

### `unnamedParam2`

Handle of the installable driver instance. Each instance of the installable driver has a unique handle.

### `unnamedParam3`

Driver message value. It can be a custom value or one of these standard values:

| Value | Meaning |
| --- | --- |
| **[DRV_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-close)** | Notifies the driver that it should decrement its usage count and unload the driver if the count is zero. |
| **[DRV_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-configure)** | Notifies the driver that it should display a configuration dialog box. This message is sent only if the driver returns a nonzero value when processing the [DRV_QUERYCONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-queryconfigure) message. |
| **[DRV_DISABLE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-disable)** | Notifies the driver that its allocated memory is about to be freed. |
| **[DRV_ENABLE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-enable)** | Notifies the driver that it has been loaded or reloaded or that Windows has been enabled. |
| **[DRV_FREE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-free)** | Notifies the driver that it will be discarded. |
| **[DRV_INSTALL](https://learn.microsoft.com/windows/desktop/Multimedia/drv-install)** | Notifies the driver that it has been successfully installed. |
| **[DRV_LOAD](https://learn.microsoft.com/windows/desktop/Multimedia/drv-load)** | Notifies the driver that it has been successfully loaded. |
| **[DRV_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/drv-open)** | Notifies the driver that it is about to be opened. |
| **[DRV_POWER](https://learn.microsoft.com/windows/desktop/Multimedia/drv-power)** | Notifies the driver that the device's power source is about to be turned on or off. |
| **[DRV_QUERYCONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-queryconfigure)** | Directs the driver to specify whether it supports the [DRV_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-configure) message. |
| **[DRV_REMOVE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-remove)** | Notifies the driver that it is about to be removed from the system. |

### `unnamedParam4`

32-bit message-specific value.

### `unnamedParam5`

32-bit message-specific value.

## Return value

Returns nonzero if successful or zero otherwise.

## Remarks

When *msg* is [DRV_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/drv-open), *lParam1* is the string following the driver filename from the SYSTEM.INI file and *lParam2* is the value given as the *lParam* parameter in a call to the [OpenDriver](https://learn.microsoft.com/previous-versions/dd743639(v=vs.85)) function.

When *msg* is [DRV_CLOSE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-close), *lParam1* and *lParam2* are the same values as the *lParam1* and *lParam2* parameters in a call to the [CloseDriver](https://learn.microsoft.com/previous-versions/dd797785(v=vs.85)) function.

## See also

[Driver Functions](https://learn.microsoft.com/windows/desktop/Multimedia/driver-functions)

[Installable Drivers](https://learn.microsoft.com/windows/desktop/Multimedia/installable-drivers)