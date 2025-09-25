# _NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO structure

## Description

[The IPsec Task Offload feature is deprecated and should not be used.]

The NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO structure specifies IPsec header information in
the OOB data of a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Transmit`

A structure that contains the following members:

### `Transmit.NextHeader`

The next header value that is carried in the ESP trailer.

### `Transmit.PadLength`

The amount of padding, in bytes, that is added to the end of the payload for ESP only.
**PadLength** is specified for IPsec offload packets with and without large send offload (LSO).

### `Transmit.AhHeaderOffset`

The offset count from the beginning of the IP header to the AH header. The
**AhHeaderOffset** value is this offset, in bytes, divided by 4 to reduce the number of bits that
are required to represent the offset. Note that the AH header is, at minimum, aligned on 4-byte
boundaries.

### `Transmit.EspHeaderOffset`

The offset count from the beginning of the IP header to the ESP header. The
**EspHeaderOffset** value is this offset, in bytes, divided by 4 to reduce the number of bits that
are required to represent the offset. Note that the ESP header is, at minimum, aligned on 4-byte
boundaries.

### `Receive`

A structure that contains the following members:

### `Receive.NextHeader`

The next header value that is carried in the ESP trailer.

### `Receive.PadLength`

The amount of padding, in bytes, that is added to the end of the payload for ESP only.
**PadLength** is specified for IPsec offload packets with and without large send offload (LSO).

### `Receive.HeaderInfoSet`

A ULONG value that, when set, indicates the members of the
**Receive** structure are valid. If this member is not set, the
**Receive** structure is ignored.

## Remarks

The information in the NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO structure makes it easy for
the miniport driver to parse an outbound packet. NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO
specifies the header offsets for IPsec headers in the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure as well as the
location of the next header and the padding length.

To set and get the IPsec tunnel information, use the
**IPsecOffloadV2HeaderNetBufferListInfo** index with the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro.
NET_BUFFER_LIST_INFO returns an NDIS_IPSEC_OFFLOAD_V2_HEADER_NET_BUFFER_LIST_INFO structure.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)