# NdisIfGetInterfaceIndexFromNetLuid function

## Description

The
**NdisIfGetInterfaceIndexFromNetLuid** function gets the network interface index that is associated with
a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value.

## Parameters

### `NetLuid` [in]

A
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that identifies a network
interface.

### `pIfIndex` [out]

A pointer to a caller-supplied interface index variable. If
**NdisIfGetInterfaceIndexFromNetLuid** succeeds, NDIS writes the network interface index that is
associated with the specified NET_LUID to this variable.

## Return value

**NdisIfGetInterfaceIndexFromNetLuid** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_INTERFACE_NOT_FOUND** | **NdisIfGetInterfaceIndexFromNetLuid** failed because the specified NET_LUID was not present in the list of registered interfaces. |

## Remarks

NDIS drivers can call the
**NdisIfGetInterfaceIndexFromNetLuid** function to get the network interface index that is associated
with a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value.

For the interfaces that the NDIS proxy provider service manages, NDIS provides the interface index and
NET_LUID in various driver initialization structures:

* Miniport drivers can obtain the interface index and NET_LUID for a miniport adapter in the
  [NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure.
* Filter drivers can obtain the interface index and NET_LUID for a filter module in the
  [NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure.
* Protocol drivers can obtain the interface index and NET_LUID of the highest and the lowest
  interfaces on a driver stack in the
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
[NdisIfGetNetLuidFromInterfaceIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifgetnetluidfrominterfaceindex) function to get the NET_LUID value that is associated with a
specified interface index.

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIfGetNetLuidFromInterfaceIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifgetnetluidfrominterfaceindex)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)