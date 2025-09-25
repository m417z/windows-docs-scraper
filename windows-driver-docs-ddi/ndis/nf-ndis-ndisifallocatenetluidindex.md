# NdisIfAllocateNetLuidIndex function

## Description

The
**NdisIfAllocateNetLuidIndex** function allocates a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) index for an NDIS network interface
provider.

## Parameters

### `ifType`

The Internet Assigned Numbers Authority (IANA) interface type for an index. For example,
IF_TYPE_ETHERNET_CSMACD (6) is the value for
*IfType* that is assigned to any Ethernet-like interface. For a list of interface types, see
[NDIS Interface Types](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-interface-types).

### `pNetLuidIndex` [out]

A pointer to a caller-supplied
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) index variable. If allocation is
successful,
**NdisIfAllocateNetLuidIndex** sets this variable to the allocated 24-bit NET_LUID index value.

## Return value

**NdisIfAllocateNetLuidIndex** returns one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because of insufficient resources. |

## Remarks

NDIS interface providers call the
**NdisIfAllocateNetLuidIndex** function to allocate a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) index. An interface provider must allocate
a NET_LUID index before the interface provider can register an interface.

**NdisIfAllocateNetLuidIndex** attempts to allocate a 24-bit NET_LUID index that is unique to the local
computer and is associated with the interface type that the
*IfType* parameter specifies. NDIS records the NET_LUID index in persistent storage so that the index
can remain associated with the same interface even after the computer restarts. NDIS will not allocate
the same NET_LUID index to future callers of
**NdisIfAllocateNetLuidIndex** until after the interface provider calls the
[NdisIfFreeNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiffreenetluidindex) function to
free the index.

To build a
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value from the NET_LUID index and the
interface type, an interface provider calls the
[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid) macro.

The interface provider must store the NET_LUID values that it allocates in persistent storage. For
example, if there is a loss of computer power, the provider should have stored the NET_LUID values in
persistent storage so it can call
[NdisIfFreeNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiffreenetluidindex) later to
free any indexes that are no longer in use. Also, the provider should use the same NET_LUID value
whenever it registers the same interface with the
[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function.

## See also

[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIfFreeNetLuidIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiffreenetluidindex)

[NdisIfRegisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)