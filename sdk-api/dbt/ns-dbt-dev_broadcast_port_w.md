# DEV_BROADCAST_PORT_W structure

## Description

Contains information about a modem, serial, or parallel port.

## Members

### `dbcp_size`

The size of this structure, in bytes. This is the size of the members plus the actual length of the
**dbcp_name** string (the null character is accounted for by the declaration of
**dbcp_name** as a one-character array.)

### `dbcp_devicetype`

Set to **DBT_DEVTYP_PORT**.

### `dbcp_reserved`

Reserved; do not use.

### `dbcp_name`

A null-terminated string specifying the friendly name of the port or the device connected to the port.
Friendly names are intended to help the user quickly and accurately identify the device—for example,
"COM1" and "Standard 28800 bps Modem" are considered friendly names.

## See also

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)

## Remarks

> [!NOTE]
> The dbt.h header defines DEV_BROADCAST_PORT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).