# NdisIfAddIfStackEntry function

## Description

The
**NdisIfAddIfStackEntry** function specifies the ordering of two network interfaces in the NDIS network
interface stack.

## Parameters

### `HigherLayerIfIndex` [in]

The network interface index for the interface that should be higher in the interface stack
table.

### `LowerLayerIfIndex` [in]

The network interface index for the interface that should be lower in the interface stack
table.

## Return value

**NdisIfAddIfStackEntry** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **NDIS_STATUS_INTERFACE_NOT_FOUND** | **NdisIfAddIfStackEntry** failed because the index at *HigherLayerIfIndex* or *LowerLayerIfIndex* is not the index of a registered interface. |

## Remarks

NDIS drivers can call the
**NdisIfAddIfStackEntry** function to specify the ordering of two network interfaces in the NDIS
interface stack. The NDIS proxy provider specifies the order for filter modules and miniport adapters.
NDIS also specifies the relationship between the virtual miniport and the underlying miniport adapter for
filter intermediate drivers. However, NDIS does not specify the stack order for MUX intermediate
drivers.

NDIS maintains an interface stack table (*ifStackTable* from
[RFC 2863](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-ndis-network-interfaces)). NDIS provides
the
**NdisIfAddIfStackEntry** and
[NdisIfDeleteIfStackEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifdeleteifstackentry) functions to add and delete entries in this table.

Any driver that can provide the information about the stack order relationship between two interfaces
should call
**NdisIfAddIfStackEntry** to populate the interface stack table. NDIS deletes the corresponding stack
entries for an interface when the interface is deregistered.

## See also

[NdisIfDeleteIfStackEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifdeleteifstackentry)