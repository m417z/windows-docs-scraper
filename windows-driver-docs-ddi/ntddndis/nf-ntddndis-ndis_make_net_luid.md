# NDIS_MAKE_NET_LUID macro

## Description

The NDIS_MAKE_NET_LUID macro builds a [**NET_LUID**](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value from an interface type and a NET_LUID index.

## Parameters

### `_pNetLuid`

A pointer to a caller-supplied [**NET_LUID**](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) union. **NDIS_MAKE_NET_LUID** returns the newly created NET_LUID value in this variable.

### `_IfType`

The Internet Assigned Numbers Authority (IANA) interface type. **NDIS_MAKE_NET_LUID** writes the value at *\_IfType* to the **IfType** member of the NET_LUID union that the caller provided at *\_pNetLuid* . For a list of interface types, see [NDIS Interface Types](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-interface-types).

### `_NetLuidIndex`

A NET_LUID index that the caller allocated with the [**NdisIfAllocateNetLuidIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifallocatenetluidindex) function. **NDIS_MAKE_NET_LUID** writes the value at *\_NetLuidIndex* to the **NetLuidIndex** member of the **NET_LUID** union that the caller provided at *\_pNetLuid* .

## Remarks

NDIS network interface providers should use the **NDIS_MAKE_NET_LUID** macro to build a [**NET_LUID**](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value. The provider passes the resulting **NET_LUID** value to the [**NdisIfRegisterInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface) function to register the interface with NDIS.

## See also

[**NdisIfAllocateNetLuidIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifallocatenetluidindex)

[**NdisIfRegisterInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterinterface)

[**NET_LUID**](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)