# FWPS_STREAM_DATA0_ structure

## Description

The **FWPS_STREAM_DATA0** structure describes a portion of a data stream.

**Note** **FWPS_STREAM_DATA0** is a specific version of **FWPS_STREAM_DATA**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `flags`

A variable containing flags that specify the characteristics of the data stream.

For inbound data streams, this can be one or more of the following flags:

#### FWPS_STREAM_FLAG_RECEIVE

Specifies that the stream is an inbound data stream. This flag is always set for inbound data
streams.

#### FWPS_STREAM_FLAG_RECEIVE_EXPEDITED

Specifies that the inbound data stream contains high-priority out-of-band data.

#### FWPS_STREAM_FLAG_RECEIVE_DISCONNECT

Specifies that the inbound data has arrived with the FIN flag set in the TCP header. This
indicates that the sender has disconnected the stream.

#### FWPS_STREAM_FLAG_RECEIVE_ABORT

Specifies that the inbound data has arrived with the RST flag set in the TCP header. This
indicates that the sender has reset the stream.

**Note** This flag is not implemented in Windows Vista.

For outbound data streams, this can be one or more of the following flags:

#### FWPS_STREAM_FLAG_SEND

Specifies that the stream is an outbound data stream. This flag is always set for outbound data
streams.

#### FWPS_STREAM_FLAG_SEND_EXPEDITED

Specifies that the outbound data stream contains high-priority out-of-band data.

#### FWPS_STREAM_FLAG_SEND_NODELAY

Specifies that the sending client requests that the outbound data stream is not to be buffered.
If this flag is set, a callout driver should not hold onto the stream buffer any longer than
necessary.

#### FWPS_STREAM_FLAG_SEND_DISCONNECT

Specifies that the stream is to be disconnected after the data in the outbound data stream has
been sent. The network stack will set the FIN flag in the TCP header of the last packet that is sent
out.

#### FWPS_STREAM_FLAG_SEND_ABORT

Specifies that the stream is to be reset after the data in the outbound data stream has been
sent. The network stack will set the RST flag in the TCP header of the last packet that is sent out.
Callout drivers must not call the
[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0) function
to inject data into the stream if this flag is set.

**Note** This flag is not implemented in Windows Vista.

### `dataOffset`

An
[FWPS_STREAM_DATA_OFFSET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data_offset0_) structure
that specifies the offset into the data stream where the portion of the data stream begins.

### `dataLength`

The number of bytes in the portion of the data stream.

### `netBufferListChain`

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the portion of the data stream.

## Remarks

The filter engine uses the FWPS_STREAM_DATA0 structure to describe the portion of a data stream that a
callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function can process. The
**dataStream** member of the
[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_) structure points to an FWPS_STREAM_DATA0 structure.

## See also

[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_)

[FWPS_STREAM_DATA_OFFSET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data_offset0_)

[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)