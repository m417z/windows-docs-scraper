# FwpsGetPacketListSecurityInformation0 function

## Description

The
**FwpsGetPacketListSecurityInformation0** function retrieves information associated with a packet
list.

**Note** **FwpsGetPacketListSecurityInformation0** is a specific version of **FwpsGetPacketListSecurityInformation**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `packetList` [in]

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for which the
associated information is being retrieved.

### `queryFlags` [in]

A UINT32 value that contains a bitwise OR of a combination of the following flags that specify the
information to be retrieved:

#### FWPS_PACKET_LIST_INFORMATION_QUERY_INBOUND

Retrieve information for an inbound packet list.

#### FWPS_PACKET_LIST_INFORMATION_QUERY_OUTBOUND

Retrieve information for an outbound packet list.

#### FWPS_PACKET_LIST_INFORMATION_QUERY_IPSEC

Retrieve the IPsec information associated with the packet list. This flag must be used in
combination with either the FWPS_PACKET_LIST_INFORMATION_QUERY_INBOUND flag or the
FWPS_PACKET_LIST_INFORMATION_QUERY_OUTBOUND flag.

#### FWPS_PACKET_LIST_INFORMATION_QUERY_FWP

Retrieve the Windows Filtering Platform information associated with the packet list.

#### FWPS_PACKET_LIST_INFORMATION_QUERY_ALL_INBOUND

Retrieve all information associated with an inbound packet list.

#### FWPS_PACKET_LIST_INFORMATION_QUERY_ALL_OUTBOUND

Retrieve all information associated with an outbound packet list.

### `packetInformation` [in, out]

A pointer to an
[FWPS_PACKET_LIST_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_information0_) structure that receives the information associated with the packet
list.

## Return value

The
**FwpsGetPacketListSecurityInformation0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The information associated with the packet list was successfully retrieved. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsGetPacketListSecurityInformation0** function from within its
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function to retrieve
information associated with the packet list. This information can be used to determine the action to be
taken on the data.

## See also

[FWPS_PACKET_LIST_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_information0_)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)