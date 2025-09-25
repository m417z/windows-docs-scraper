# FwpsConstructIpHeaderForTransportPacket0 function

## Description

The
**FwpsConstructIpHeaderForTransportPacket0** function is called by a callout to construct a new IP header
or to rebuild a preexisting IP packet header for only one net buffer.

**Note** **FwpsConstructIpHeaderForTransportPacket0** is a specific version of **FwpsConstructIpHeaderForTransportPacket**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferList` [in, out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the cloned transport layer packet data for which a new IP header is to be constructed or rebuilt. To
construct a new IP header, locate the offset of the cloned NET_BUFFER_LIST structure at the beginning of
the transport header. To rebuild a preexisting IP packet header, locate the offset at the beginning of
the IP header.

### `headerIncludeHeaderLength`

If the NET_BUFFER_LIST structure pointed to by
*NetBufferList* already contains an IP header, indicates the total size, in bytes, of the existing
IP header (if it exists). If
*NetBufferList* does not contain an IP header,
*headerIncludeHeaderSize* is zero. Otherwise, the value of this parameter is equal to the
**ipHeaderSize** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. Note that
extension headers for an existing IPv6 header will be removed when this function is called, although
IPv4 options will be preserved. For more information, see Remarks.

### `addressFamily` [in]

One of the following address families:

#### AF_INET

The IPv4 address family.

#### AF_INET6

The IPv6 address family.

### `sourceAddress` [in]

A pointer to the source IP address that will be part of the IP header to be constructed. For IPv4,
the address is 4 bytes. For IPv6, the address is 16 bytes. The source address bytes are always in
network byte order.

### `remoteAddress` [in]

A pointer to a buffer that specifies the remote IP address that will be part of the IP header to
be constructed.

The buffer can contain an IPv4 address (4 bytes) or an IPv6 address (16 bytes), and the address must
be specified in network byte order. The IP version must match the
*addressFamily* parameter.

### `nextProtocol` [in]

Specifies the IPPROTO protocol type of the new IP header to be constructed. For more information
on the IPPROTO enumeration, see
[AF_INET](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet) or
[AF_INET6](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet6).

### `endpointHandle` [in, optional]

An optional handle that indicates the stack transport endpoint in the send data path into which
the packet is to be injected. This endpoint handle is provided to a callout through the
**transportEndpointHandle** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

### `controlData` [in, optional]

An optional pointer to a buffer that contains socket control data specified by the
**WSASendMsg** function, which is described in the Microsoft Windows SDK documentation. For
information about the WSACMSGHDR type, see
[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr).

If present, socket control data is provided to a callout with the
**controlData** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

If socket control data is not **NULL**, it must be deep-copied in the callout driver's implementation of
the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function, and the
**controlData** buffer must be kept valid until the injection completion function is
called.

### `controlDataLength` [in]

The length, in bytes, of the
*controlData* parameter.

### `flags` [in]

Flags that specify whether the NBL is intended for the send or receive path. The **flags** parameter can have the following values:

|Value|Meaning|
|--- |--- |
|**FWPS_CONSTRUCT_IPHEADER_FOR_SEND**|When set, this flag specifies that the NBL is intended for send path.|
|**FWPS_CONSTRUCT_IPHEADER_FOR_RECEIVE**|When set, this flag specifies that the NBL is intended for receive path.|

For callout drivers that support USO or URO, it is mandatory to set this parameter to one of these values. Other callout drivers can set this parameter to **zero**. These flags are only supported on Windows Server 2022 23H2 and later. On prior releases of Windows, callout drivers must always set this parameter to **zero**.

### `reserved`

Reserved. Callout drivers must set this parameter to **NULL**.

### `interfaceIndex` [in, optional]

The index of the interface on which the original packet data was received. A callout driver should use the value of the interface index that is passed as one of the incoming data values to its [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for this parameter. This parameter is optional and can be zero.

### `subInterfaceIndex` [in, optional]

The index of the subinterface on which the original packet data was received. A callout driver
should use the value of the subinterface index that is passed as one of the incoming data values to its
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for this
parameter if the packet is to be injected into the same subinterface where the original packet was
indicated. This parameter is optional and can be zero.

## Return value

The
**FwpsConstructIpHeaderForTransportPacket0** function returns one of the following NTSTATUS
codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A new IP header was successfully constructed. |
| **Other status codes** | An error occurred. |

## Remarks

From a net buffer list cloned at a WFP outbound transport layer (FWPS_LAYER_OUTBOUND_TRANSPORT_Xxx),
**FwpsConstructIpHeaderForTransportPacket0** constructs a new header for each net buffer that is part
of the net buffer list chain. This function can also be used to rebuild the preexisting IP header of a
packet, in which case the net buffer list must contain only one net buffer.

This function is useful when the IP header has not yet been created, but the source IP address or the
source port must be modified from the transport layer. Although it would ordinarily be possible to
wait to perform such modifications until the packet reaches the Network layer, this cannot be done in an
IPsec environment in which IP packets are encrypted or digitally signed before they reach the Network
layer.

The source IP address can be modified to be another locally defined IP address or another address that
does not exist on the local computer. Packets so modified can then be sent or injected into the receive
or forwarding data path.

If a nonzero
*endpointHandle* parameter is specified, session states (socket options), if any, associated with the
socket will be used to construct each new IP header. Similarly, if additional socket options are
specified with the
*controlData* and
*controlDataLength* parameters, those options will be used to construct each new IP header.

If the input net buffer list was cloned from an inbound WFP transport layer, or if it was created as a
result of a raw send operation, the net buffers will already contain an IP header. In this case, when
this function is called, IPv4 options will be preserved in the new IP header, but AH/ESP headers and IPv6
extension headers will be removed. Because the TCP/IP stack retains AH/ESP headers after IPsec
processing, packets that have been indicated by WFP and cloned by callouts cannot readily be injected
into the receive data path. Consequently this function is useful for rebuilding IPsec-processed packets
that are to be injected into the receive data path with the
[FwpsInjectTransportReceiveAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportreceiveasync0) function.

For a header-include session; for example, to filter Generic Routing Encapsulation (GRE) traffic (IP
protocol 47) sent on a raw socket from outbound transport layers, use the following procedure before you
call
**FwpsConstructIpHeaderForTransportPacket0**:

1. Clone the net buffer list by calling the
   [FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0) function.
2. If the
   **headerIncludeHeaderLength** member of the FWPS_INCOMING_METADATA_VALUES0 structure that is pointed
   to by the
   [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function's
   *inMetaValues* parameter is greater than zero, retreat the cloned net buffer list by that amount; for example, by a call to
   [NdisRetreatNetBufferListDataStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretreatnetbufferlistdatastart).
3. Copy the buffer that is pointed to by the
   **headerIncludeHeader** member of FWPS_INCOMING_METADATA_VALUES0 into the newly retreated region of
   the cloned net buffer list. The size of the buffer must be equal to the value of
   *headerIncludeHeaderLength*.
4. Call
   **FwpsConstructIpHeaderForTransportPacket0** that has the
   *NetBufferList* parameter pointing to the cloned net buffer list and the
   *headerIncludeHeaderSize* parameter set to the value of
   *headerIncludeHeaderLength*.

**FwpsConstructIpHeaderForTransportPacket0** disables large send offload (LSO) and checksum offload
support for the resulting net buffer list. Full checksums are calculated for upper-level protocols (TCP,
UDP, and ICMP). The IP checksum is recalculated when the IP header is reconstructed.

## See also

[AF_INET](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet)

[AF_INET6](https://learn.microsoft.com/windows-hardware/drivers/network/af-inet6)

[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FwpsInjectTransportReceiveAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjecttransportreceiveasync0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)