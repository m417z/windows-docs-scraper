# NdisIfDeregisterInterface function

## Description

The
**NdisIfDeregisterInterface** function deregisters an NDIS network interface that was previously
registered by a call to the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

## Parameters

### `ifIndex`

An index that identifies the network interface to deregister. The interface provider obtained this
index from a previous call to the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

## Remarks

NDIS interface providers call the
**NdisIfDeregisterInterface** function to deregister a network interface and to indicate that the
interface should be removed from the list of known interfaces on the computer.

An interface provider calls the
**NdisIfDeregisterInterface** function, for example, because the interface has been uninstalled.
Interface providers do not call
**NdisIfDeregisterInterface** to indicate that an interface has changed state.

**NdisIfDeregisterInterface** releases the interface index, so NDIS can reassign the index to another
interface that is registered later. Do not confuse the interface index with the
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) index, which persists after a computer
restarts.

## See also

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)