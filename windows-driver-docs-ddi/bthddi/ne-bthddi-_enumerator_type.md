# _ENUMERATOR_TYPE enumeration

## Description

The ENUMERATOR_TYPE enumeration type is used to determine whether the enumerated device is associated
with a service or a protocol. The ENUMERATOR_TYPE enumeration is intended for internal use only and should
not be used by profile drivers.

## Constants

### `ENUMERATOR_TYPE_PROTOCOL`

For internal use only. Do not use.

### `ENUMERATOR_TYPE_SERVICE`

This value should be specified for profile drivers. For more information about how this value is
used, see
[BTH_ENUMERATOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_bth_enumerator_info).

### `ENUMERATOR_TYPE_DEVICE`

### `ENUMERATOR_TYPE_MAX`

For internal use only. Do not use.

## Remarks

A value from this enumeration is returned as the
**EnumeratorType** member of the
[BTH_ENUMERATOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_bth_enumerator_info) structure, which the
[IOCTL_INTERNAL_BTHENUM_GET_ENUMINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bthenum_get_enuminfo) returns in its output buffer.

## See also

[BTH_ENUMERATOR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_bth_enumerator_info)

[IOCTL_INTERNAL_BTHENUM_GET_ENUMINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bthenum_get_enuminfo)