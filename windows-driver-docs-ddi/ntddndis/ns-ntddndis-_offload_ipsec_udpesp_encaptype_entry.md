# _OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY structure

## Description

The OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY structure specifies the UDP-ESP encapsulation type and
destination port of a parser entry.

## Members

### `UdpEncapType`

The UDP-ESP encapsulation type for packets protected by the security associations (SAs) that are
being offloaded:

#### IPSEC_UDPESP_ENCAPTYPE_IKE

This value is reserved.

#### IPSEC_UDPESP_E\NCAPTYPE_OTHER

UDP encapsulation for packets on port 4500. For more information, see
[UDP-ESP Encapsulation
Types](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565707(v=vs.85)).

### `DstEncapPort`

For an inbound SA (Flags = OFFLOAD_INBOUND_SA), specifies the destination port that the NIC should
look for in the UDP header of inbound packets that it processes on the SAs being offloaded. The NIC
should ignore this member for an outbound SA (
**Flags** =
**OFFLOAD_OUTBOUND_SA**).
**DstEncapPort** should always specify port 4500.

## Remarks

The OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY structure is used with the
[OFFLOAD_IPSEC_ADD_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_add_udpesp_sa) structure.

## See also

[OFFLOAD_IPSEC_ADD_UDPESP_SA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_offload_ipsec_add_udpesp_sa)