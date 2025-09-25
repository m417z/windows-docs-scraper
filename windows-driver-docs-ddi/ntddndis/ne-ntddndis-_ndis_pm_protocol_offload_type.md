# _NDIS_PM_PROTOCOL_OFFLOAD_TYPE enumeration

## Description

The **NDIS_PM_PROTOCOL_OFFLOAD_TYPE** enumeration identifies the type of a protocol offload for NDIS
network adapter power management.

## Constants

### `NdisPMProtocolOffloadIdUnspecified`

The offloaded protocol is not specified.

### `NdisPMProtocolOffloadIdIPv4ARP`

An IPv4 ARP protocol offload. The parameters for this protocol offload type are specified in the
**IPv4ARPParameters** member of the
[NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload) structure.

### `NdisPMProtocolOffloadIdIPv6NS`

An IPv6 Neighbor Solicitation (NS) protocol offload. The parameters for this protocol offload type
are specified in the
**IPv6NSParameters** member of the [NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload) structure.

### `NdisPMProtocolOffload80211RSNRekey`

An IEEE 802.11i Robust Security Network (RSN) 4-way and 2-way handshake protocol offload. This
protocol offload type is specified in the
**Dot11RSNRekeyParameters** member of the [NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload) structure.

### `NdisPMProtocolOffload80211RSNRekeyV2`

### `NdisPMProtocolOffloadIdMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_PM_PROTOCOL_OFFLOAD_TYPE** enumeration is used in the
**ProtocolOffloadType** member of the
[NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload) structure.

## See also

[NDIS_PM_PROTOCOL_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_protocol_offload)