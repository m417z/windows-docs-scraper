# IDDCX_MONITOR_DESCRIPTION_TYPE enumeration

## Description

An **IDDCX_MONITOR_DESCRIPTION_TYPE** value describes the monitor type.

## Constants

### `IDDCX_MONITOR_DESCRIPTION_TYPE_UNINITIALIZED:0`

Indicates that an **IDDCX_MONITOR_DESCRIPTION_TYPE** variable has not yet been assigned a meaningful value.

### `IDDCX_MONITOR_DESCRIPTION_TYPE_EDID:1`

The monitor description is either EDID or no monitor description is available.

### `IDDCX_MONITOR_DESCRIPTION_TYPE_DISPLAYID_AND_EDID:2`

The monitor description is both DisplayID and EDID.

### `IDDCX_MONITOR_DESCRIPTION_TYPE_DISPLAYID:` 3

The monitor description is DisplayID only. This means a pure DisplayID block, rather than one embedded inside an EDID block, and no EDID blocks preceding or following.

## See also

[**IDDCX_MONITOR_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_description)