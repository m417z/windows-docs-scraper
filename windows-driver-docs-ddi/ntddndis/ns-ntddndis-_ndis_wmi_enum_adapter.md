# _NDIS_WMI_ENUM_ADAPTER structure

## Description

The NDIS_WMI_ENUM_ADAPTER structure is returned when NDIS responds to the
[GUID_NDIS_ENUMERATE_ADAPTERS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-enumerate-adapters-ex) GUID.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for this
NDIS_WMI_ENUM_ADAPTER structure. Set the
**Type** member of NDIS_OBJECT_HEADER to NDIS_WMI_OBJECT_TYPE_ENUM_ADAPTER, the
**Revision** member to NDIS_WMI_ENUM_ADAPTER_REVISION_1, and the
**Size** member to
sizeof(NDIS_WMI_ENUM_ADAPTER).

### `IfIndex`

The NDIS interface index of the NDIS miniport adapter interface that is associated with the
GUID.

### `NetLuid`

The NDIS network interface name of the miniport adapter.

### `DeviceNameLength`

The length, in bytes, of the device name of the NDIS miniport adapter interface that is associated
with the GUID.

### `DeviceName`

The device name of the NDIS miniport adapter interface that is associated with the GUID. The
device name is a null-terminated wide character string.

## Remarks

NDIS returns the NDIS_WMI_ENUM_ADAPTER structure when it enumerates miniport adapters for WMI clients.
For more information about enumerating miniport adapters for WMI clients, see
[GUID_NDIS_ENUMERATE_ADAPTERS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-enumerate-adapters-ex).

## See also

[GUID_NDIS_ENUMERATE_ADAPTERS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/guid-ndis-enumerate-adapters-ex)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)