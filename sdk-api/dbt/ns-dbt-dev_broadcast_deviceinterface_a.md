# DEV_BROADCAST_DEVICEINTERFACE_A structure

## Description

Contains information about a class of devices.

## Members

### `dbcc_size`

The size of this structure, in bytes. This is the size of the members plus the actual length of the
**dbcc_name** string (the null character is accounted for by the declaration of
**dbcc_name** as a one-character array.)

### `dbcc_devicetype`

Set to **DBT_DEVTYP_DEVICEINTERFACE**.

### `dbcc_reserved`

Reserved; do not use.

### `dbcc_classguid`

The GUID for the interface device class.

### `dbcc_name`

A null-terminated string that specifies the name of the device.

When this structure is returned to a window through the
[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange) message, the
**dbcc_name** string is converted to ANSI as appropriate. Services always receive a
Unicode string, whether they call
**RegisterDeviceNotificationW**
or
**RegisterDeviceNotificationA**.

## See also

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)

## Remarks

> [!NOTE]
> The dbt.h header defines DEV_BROADCAST_DEVICEINTERFACE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).