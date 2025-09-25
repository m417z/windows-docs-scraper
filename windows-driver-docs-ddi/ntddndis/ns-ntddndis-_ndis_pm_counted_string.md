# _NDIS_PM_COUNTED_STRING structure

## Description

The NDIS_PM_COUNTED_STRING structure specifies a limited size string that is used in power management
structures.

## Members

### `Length`

The length, in bytes, of the string.

### `String`

A WCHAR array that contains a NULL-terminated string that is limited to a maximum size of
NDIS_PM_MAX_STRING_SIZE.

## Remarks

The NDIS_PM_COUNTED_STRING structure specifies a limited size string that is used in the
[NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload) and
[NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) power management
structures to define name strings.

## See also

[NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload)

[NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern)