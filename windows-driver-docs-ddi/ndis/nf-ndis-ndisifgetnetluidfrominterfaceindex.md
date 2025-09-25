# NdisIfGetNetLuidFromInterfaceIndex function

## Description

The
**NdisIfGetNetLuidFromInterfaceIndex** function gets the
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that is associated with a network
interface index.

## Parameters

### `ifIndex`

A network interface index that NDIS assigned to a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value in the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

### `pNetLuid` [out]

A pointer to a caller-supplied NET_LUID variable. If
**NdisIfGetNetLuidFromInterfaceIndex** succeeds, NDIS writes the NET_LUID value that is associated
with the specified network interface index to this variable.

## Return value

**NdisIfGetNetLuidFromInterfaceIndex** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_INTERFACE_NOT_FOUND** | **NdisIfGetNetLuidFromInterfaceIndex** failed because the specified network interface index is not assigned to a registered interface. |

## Remarks

NDIS drivers can call the
**NdisIfGetNetLuidFromInterfaceIndex** function to get the
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that is associated with a network
interface index.

For the interfaces that the NDIS proxy provider service manages, NDIS provides the interface index and
NET_LUID in various driver initialization structures:

* Miniport drivers can obtain the interface index and NET_LUID for a miniport adapter in the
  [NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure.
* Filter drivers can obtain the interface index and NET_LUID for a filter module in the
  [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure.
* Protocol drivers can obtain the interface index and NET_LUID of the highest and the lower interfaces
  on a driver stack in the
  [NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure.

NDIS assigns an interface index to a network interface when the interface provider calls the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.
An interface provider calls the
[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid) macro to create the
NET_LUID value before it registers an interface.

The interface index value can change without a computer restart. Deregistering and re-registering an
interface that is associated with a NET_LUID value might result in different interface index values. Do
not confuse the interface index with the NET_LUID index that persists after a computer restarts.

NDIS provides the
[NdisIfGetInterfaceIndexFromNetLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifgetinterfaceindexfromnetluid) function to obtain the interface index for a specified
NET_LUID.

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIfGetInterfaceIndexFromNetLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifgetinterfaceindexfromnetluid)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)