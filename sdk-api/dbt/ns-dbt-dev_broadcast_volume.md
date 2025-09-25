# DEV_BROADCAST_VOLUME structure

## Description

Contains information about a logical volume.

## Members

### `dbcv_size`

The size of this structure, in bytes.

### `dbcv_devicetype`

Set to **DBT_DEVTYP_VOLUME** (2).

### `dbcv_reserved`

Reserved; do not use.

### `dbcv_unitmask`

The logical unit mask identifying one or more logical units. Each bit in the mask corresponds to one
logical drive. Bit 0 represents drive A, bit 1 represents drive B, and so on.

### `dbcv_flags`

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DBTF_MEDIA**<br><br>0x0001 | Change affects media in drive. If not set, change affects physical device or drive. |
| **DBTF_NET**<br><br>0x0002 | Indicated logical volume is a network volume. |

## Remarks

Although the **dbcv_unitmask** member may specify more than one volume in any message,
this does not guarantee that only one message is generated for a specified event. Multiple system features may
independently generate messages for logical volumes at the same time.

Messages for media arrival and removal are sent only for media in devices that support a soft-eject mechanism.
For example, applications will not see media-related volume messages for floppy disks.

Messages for network drive arrival and removal are not sent whenever network commands are issued, but rather
when network connections will disappear as the result of a hardware event.

## See also

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)