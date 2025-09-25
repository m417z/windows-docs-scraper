# NdisIfDeleteIfStackEntry function

## Description

The
**NdisIfDeleteIfStackEntry** function deletes information about the ordering of two network interfaces in
the NDIS interface stack.

## Parameters

### `HigherLayerIfIndex` [in]

The network interface index for the interface that was higher in the stack table.

### `LowerLayerIfIndex` [in]

The network interface index for the interface that was lower in the stack table.

## Remarks

NDIS drivers call
**NdisIfDeleteIfStackEntry** to delete a stack entry that was previously added by calling the
[NdisIfAddIfStackEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifaddifstackentry) function. NDIS
deletes the stack entry from its interface stack table if it finds a matching entry.

NDIS maintains an interface stack table (*ifStackTable* from
[RFC 2863](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-network-interfaces)). NDIS provides
the
**NdisIfAddIfStackEntry** and
**NdisIfDeleteIfStackEntry** functions to add and delete entries in this table.

## See also

[NdisIfAddIfStackEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifaddifstackentry)