# _NDIS_TCP_RECV_SEG_COALESCE_OFFLOAD structure

## Description

The **NDIS_TCP_RECV_SEG_COALESCE_OFFLOAD** structure contains the offload support state for receive segment coalescing (RSC).

## Members

### `IPv4`

### `IPv4.Enabled`

A BOOLEAN value that is set to TRUE if RSC processing on IPv4 traffic is supported. Otherwise, this member is FALSE.

### `IPv6`

### `IPv6.Enabled`

A BOOLEAN value that is set to TRUE if RSC processing on IPv6 traffic is supported. Otherwise, this member is FALSE.

## Remarks

A miniport driver advertises support for receive segment coalescing (RSC) in the Rsc member of the [NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure that it passes to the [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function.

The miniport driver can set the **IPv4.Enabled** member or the **IPv6.Enabled** member or both in the **NDIS_TCP_RECV_SEG_COALESCE_OFFLOAD** structure to TRUE if it supports RSC for these protocols. The miniport driver must support RSC for 802.3 encapsulation or greater, and can support any other encapsulations. If the miniport driver does not support RSC for some encapsulation, the received packets of that encapsulation type must be indicated up the stack normally.

To determine if a miniport driver supports RSC, NDIS drivers and other applications can query the [OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities) OID which returns the NDIS_OFFLOAD structure.

## See also

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities)