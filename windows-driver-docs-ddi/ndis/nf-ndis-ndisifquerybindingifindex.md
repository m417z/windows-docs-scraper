# NdisIfQueryBindingIfIndex function

## Description

The
**NdisIfQueryBindingIfIndex** function retrieves the network interface indexes and
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) values for the highest and lowest layered
network interfaces that are associated with a specified protocol binding.

## Parameters

### `NdisBindingHandle` [in]

A handle that identifies the binding for which NDIS should obtain the
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) values and network interface indexes.
NDIS provided this handle at the
*NdisBindingHandle* parameter of the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `pBoundIfIndex` [out]

A pointer to a caller-supplied interface index variable. If
**NdisIfQueryBindingIfIndex** succeeds, NDIS writes to this variable the network interface index of
the network interface that is associated with the specified binding and is highest in the driver
stack.

### `pBoundIfNetLuid` [out]

A pointer to a caller-supplied NET_LUID variable. If
**NdisIfQueryBindingIfIndex** succeeds, NDIS writes to this variable the NET_LUID value of the network
interface that is associated with the specified binding and is highest in the driver stack.

### `pLowestIfIndex` [out]

A pointer to a caller-supplied interface index variable. If
**NdisIfQueryBindingIfIndex** succeeds, NDIS writes to this variable the network interface index of
the network interface that is associated with the specified binding and is lowest in the driver
stack.

### `pLowestIfNetLuid` [out]

A pointer to a caller-supplied NET_LUID variable. If
**NdisIfQueryBindingIfIndex** succeeds, NDIS writes to this variable the NET_LUID value of the network
interface that is associated with the specified binding and is lowest in the driver stack.

## Return value

**NdisIfQueryBindingIfIndex** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_INTERFACE_NOT_FOUND** | **NdisIfQueryBindingIfIndex** failed because the specified binding is not associated with a registered interface. |

## Remarks

NDIS protocol drivers can call the
**NdisIfQueryBindingIfIndex** function to retrieve the network interface indexes and
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) values that are associated with a
binding.

**NdisIfQueryBindingIfIndex** provides the NET_LUID value and the interface index for the highest
interface and lowest interface that are associated with the binding. These values are different, for
example, if the miniport adapter that is directly associated with the specified binding is the virtual
miniport of a filter intermediate driver or if there is a filter module that is configured over the
miniport adapter.

Protocol drivers can also obtain the interface index and NET_LUID of the highest and the lowest
interfaces in a driver stack in the
[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters) structure.

## See also

[NDIS_BIND_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_parameters)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)