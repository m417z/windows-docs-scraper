# FWPS_PACKET_LIST_IPSEC_INFORMATION0_ structure

## Description

The **FWPS_PACKET_LIST_IPSEC_INFORMATION0** structure defines IPsec information associated with a packet
list.

**Note** **FWPS_PACKET_LIST_IPSEC_INFORMATION0** is a specific version of **FWPS_PACKET_LIST_IPSEC_INFORMATION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `inbound`

An
[FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_inbound_ipsec_information0_) structure that contains IPsec information associated
with inbound packet data.

### `outbound`

An
[FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_outbound_ipsec_information0_) structure that contains IPsec information associated
with outbound packet data.

### `flags`

A value that contains a generic representation of the IPsec information associated with the
packet list.

## Remarks

A FWPS_PACKET_LIST_IPSEC_INFORMATION0 structure is included as a member of the
[FWPS_PACKET_LIST_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_information0_) structure.

## See also

[FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_inbound_ipsec_information0_)

[FWPS_PACKET_LIST_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_information0_)

[FWPS_PACKET_LIST_OUTBOUND_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_outbound_ipsec_information0_)