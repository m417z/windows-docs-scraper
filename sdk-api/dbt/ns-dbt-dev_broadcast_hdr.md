# DEV_BROADCAST_HDR structure

## Description

Serves as a standard header for information related to a device event reported through the
[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange) message.

The members of the
**DEV_BROADCAST_HDR** structure are contained in each device management structure. To determine which structure you have received through
[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange), treat the structure as a
**DEV_BROADCAST_HDR** structure and check its **dbch_devicetype** member.

## Members

### `dbch_size`

The size of this structure, in bytes.

If this is a user-defined event, this member must be the size of this header, plus the size of the variable-length data in the
[_DEV_BROADCAST_USERDEFINED](https://learn.microsoft.com/windows/win32/api/dbt/ns-dbt-_dev_broadcast_userdefined) structure.

### `dbch_devicetype`

The device type, which determines the event-specific information that follows the first three members. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DBT_DEVTYP_DEVICEINTERFACE**<br><br>0x00000005 | Class of devices. This structure is a [DEV_BROADCAST_DEVICEINTERFACE](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_deviceinterface_a) structure. |
| **DBT_DEVTYP_HANDLE**<br><br>0x00000006 | File system handle. This structure is a [DEV_BROADCAST_HANDLE](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_handle) structure. |
| **DBT_DEVTYP_OEM**<br><br>0x00000000 | OEM- or IHV-defined device type. This structure is a [DEV_BROADCAST_OEM](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_oem) structure. |
| **DBT_DEVTYP_PORT**<br><br>0x00000003 | Port device (serial or parallel). This structure is a [DEV_BROADCAST_PORT](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_port_a) structure. |
| **DBT_DEVTYP_VOLUME**<br><br>0x00000002 | Logical volume. This structure is a [DEV_BROADCAST_VOLUME](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_volume) structure. |

### `dbch_reserved`

Reserved; do not use.

## See also

[DEV_BROADCAST_DEVICEINTERFACE](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_deviceinterface_a)

[DEV_BROADCAST_HANDLE](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_handle)

[DEV_BROADCAST_OEM](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_oem)

[DEV_BROADCAST_PORT](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_port_a)

[DEV_BROADCAST_VOLUME](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_volume)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)