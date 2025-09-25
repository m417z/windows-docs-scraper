# NdisIfFreeNetLuidIndex function

## Description

The
**NdisIfFreeNetLuidIndex** function frees a network interface
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) index that was previously allocated by a
call to the
[NdisIfAllocateNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifallocatenetluidindex) function.

## Parameters

### `ifType`

The interface type that the index was allocated for. The caller must provide the same value that
it used when it allocated the NET_LUID index with
[NdisIfAllocateNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifallocatenetluidindex).
For a list of interface types, see
[NDIS Interface Types](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-interface-types).

### `NetLuidIndex` [in]

The NET_LUID index value that NDIS should free. This index was allocated in a previous call to
**NdisIfAllocateNetLuidIndex**.

## Return value

**NdisIfFreeNetLuidIndex** returns one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **DIS_STATUS_INVALID_PARAMETER** | **NdisIfFreeNetLuidIndex** failed because the *NetLuidIndex* parameter specified an index that was not allocated for the type that the *IfType* parameter specified. |

If the call to
**NdisIfFreeNetLuidIndex** fails, the
interface provider should remove any information that it saved in persistent storage that is related to
the index. Removing the information will ensure that the provider does not keep trying to free an index
that is already freed after the computer restarts.

## Remarks

NDIS interface providers call the
**NdisIfFreeNetLuidIndex** function to free a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) index. The interface provider should free
the NET_LUID index only if the interface will not be used anymore on the local computer.

**NdisIfFreeNetLuidIndex** returns a previously allocated NET_LUID index to NDIS for possible
reallocation to another interface. The caller must pass in the same interface type at
*IfType* that it used when it called the
[NdisIfAllocateNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifallocatenetluidindex) function to allocate the NET_LUID index.

The provider should not use the freed NET_LUID index or the associated NET_LUID value in any other
NDIS function calls after it calls
**NdisIfFreeNetLuidIndex**.

## See also

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIfAllocateNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifallocatenetluidindex)