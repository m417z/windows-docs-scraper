# DEV_BROADCAST_HANDLE structure

## Description

Contains information about a file system handle.

## Members

### `dbch_size`

The size of this structure, in bytes.

### `dbch_devicetype`

Set to DBT_DEVTYP_HANDLE.

### `dbch_reserved`

Reserved; do not use.

### `dbch_handle`

A handle to the device to be checked.

### `dbch_hdevnotify`

A handle to the device notification. This handle is returned by
[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa).

### `dbch_eventguid`

The GUID for the custom event. For more information, see
[Device Events](https://learn.microsoft.com/windows/desktop/DevIO/device-events). Valid only for [DBT_CUSTOMEVENT](https://learn.microsoft.com/windows/desktop/DevIO/dbt-customevent).

### `dbch_nameoffset`

The offset of an optional string buffer. Valid only for [DBT_CUSTOMEVENT](https://learn.microsoft.com/windows/desktop/DevIO/dbt-customevent).

### `dbch_data`

Optional binary data. This member is valid only for [DBT_CUSTOMEVENT](https://learn.microsoft.com/windows/desktop/DevIO/dbt-customevent).

## See also

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)