## Description

The **NDIS_UDP_RSC_OFFLOAD** structure contains the offload support state for [UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload).

## Members

### `Enabled`

A BOOLEAN value that specifies whether UDP RSC offload is enabled.

## Remarks

A miniport driver advertises support for URO in the **UdpRsc** member of the [**NDIS_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure that it passes to the [**NdisMSetMiniportAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function.

To determine if a miniport driver supports URO, NDIS drivers and other applications can query the [OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities) OID which returns the **NDIS_OFFLOAD** structure.

## See also

[UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload)

[**NDIS_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-connection-offload-hardware-capabilities)

[**NdisMSetMiniportAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)