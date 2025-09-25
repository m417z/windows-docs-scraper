# FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION0_ structure

## Description

The **FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION0** structure defines IPsec information associated with
outbound packet data.

**Note** **FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION0** is a specific version of **FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `isIPsecPolicyMatch`

A value that indicates whether the packet list matched an IPsec filter at the outbound transport
layer.

### `isTransportPolicyMatch`

A value that indicates whether the packet list matched an IPsec transport mode filter at the outbound
transport layer.

### `isTunnelPolicyMatch`

A value that indicates whether the packet list matched an IPsec tunnel mode filter at the outbound
transport layer.

### `isTunnelIPinIP`

A value that indicates whether the packet list matched an IP-in-IP filter for IPsec tunnel mode.

## Remarks

An FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION0 structure is included as a member of the
[FWPS_PACKET_LIST_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_ipsec_information0_) structure.

## See also

[FWPS_PACKET_LIST_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_ipsec_information0_)