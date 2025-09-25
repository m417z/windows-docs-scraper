# _NDIS_OFFLOAD_ENCAPSULATION structure

## Description

The NDIS_OFFLOAD_ENCAPSULATION structure specifies encapsulation settings when it is used with the
[OID_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-offload-encapsulation) OID.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_OFFLOAD_ENCAPSULATION structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_OFFLOAD_ENCAPSULATION, the
**Revision** member to NDIS_OFFLOAD_ENCAPSULATION_ REVISION _1, and the
**Size** member to NDIS_SIZEOF_OFFLOAD_ENCAPSULATION_REVISION_1.

### `IPv4`

A structure within NDIS_OFFLOAD_ENCAPSULATION that specifies IPv4 encapsulation and that contains
the following members:

### `IPv4.Enabled`

A ULONG value that enables IPv4 encapsulation. A protocol driver sets
**Enabled** to NDIS_OFFLOAD_SET_ON if it is enabling IPv4 large send offload version 1 (LSOV1),
large send offload version 2 (LSOV2), or checksum offloads. If a protocol driver is deactivating all offloads, it sets **Enabled** to NDIS_OFFLOAD_SET_OFF. Otherwise, the protocol driver sets
**Enabled** to NDIS_OFFLOAD_SET_NO_CHANGE.

### `IPv4.EncapsulationType`

The IPv4 encapsulation type. If the
**Enabled** member is not set to NDIS_OFFLOAD_SET_ON, this member is zero. If the
**Enabled** member is set to NDIS_OFFLOAD_SET_ON, a protocol driver must set
**EncapsulationType** to one of the following:

| Value | Meaning |
| --- | --- |
| **NDIS_ENCAPSULATION_IEEE_802_3** | Specifies IEEE 802.3 encapsulation. When this value is specified, a miniport driver should also use NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q or NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q_IN_OOB encapsulation where applicable. See documentation for [NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) for more information. |
| **NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED** | Specifies logical link control (LLC) encapsulation for routed protocols, as described in RFC 1483. This flag is also used to indicate Ethernet LLC/SNAP encapsulation. |

### `IPv4.HeaderSize`

The Ethernet header length that is used in IPv4 packets. If the
**Enabled** member is not set to NDIS_OFFLOAD_SET_ON, this member is zero. If the
**Enabled** member is set to NDIS_OFFLOAD_SET_ON, a protocol driver must set
**HeaderSize** to the size of the Ethernet header that it uses.

### `IPv6`

A structure within NDIS_OFFLOAD_ENCAPSULATION that specifies IPv6 encapsulation and that contains
the following members:

### `IPv6.Enabled`

A ULONG value that enables IPv6 encapsulation. A protocol driver sets
**Enabled** to NDIS_OFFLOAD_SET_ON if it is enabling IPv6 LSOV1, LSOV2, or checksum offloads.
If a protocol driver is deactivating all offloads, it sets **Enabled** to NDIS_OFFLOAD_SET_OFF. Otherwise, the protocol driver sets
**Enabled** to NDIS_OFFLOAD_SET_NO_CHANGE.

### `IPv6.EncapsulationType`

The IPv6 encapsulation type. If the
**Enabled** member is not set to NDIS_OFFLOAD_SET_ON,
**EncapsulationType** is zero. If the
**Enabled** member is set to NDIS_OFFLOAD_SET_ON, a protocol driver must set
**EncapsulationType** to one of the following:

| Value | Meaning |
| --- | --- |
| **NDIS_ENCAPSULATION_IEEE_802_3** | Specifies IEEE 802.3 encapsulation. When this value is specified, a miniport driver should also use NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q or NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q_IN_OOB encapsulation where applicable. See documentation for [NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) for more information. |
| **NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED** | Specifies LLC encapsulation for routed protocols, as described in RFC 1483. This flag is also used to indicate Ethernet LLC/SNAP encapsulation. |

### `IPv6.HeaderSize`

The Ethernet header length that is used in IPv6 packets. If the
**Enabled** member is not set to NDIS_OFFLOAD_SET_ON, this member is zero. If the
**Enabled** member is set to NDIS_OFFLOAD_SET_ON, a protocol driver must set
**HeaderSize** to the size of the Ethernet header that it uses.

## Remarks

The NDIS_OFFLOAD_ENCAPSULATION structure specifies the requested encapsulation settings that a
miniport adapter should use for task offload services.

In a set of
[OID_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-offload-encapsulation), a
protocol driver specifies an NDIS_OFFLOAD_ENCAPSULATION structure in the
**InformationBuffer** member of the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[OID_OFFLOAD_ENCAPSULATION](https://learn.microsoft.com/windows-hardware/drivers/network/oid-offload-encapsulation)