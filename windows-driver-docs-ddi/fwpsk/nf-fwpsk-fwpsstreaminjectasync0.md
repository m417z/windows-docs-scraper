# FwpsStreamInjectAsync0 function

## Description

The
**FwpsStreamInjectAsync0** function injects TCP data segments into a TCP data stream.

**Note** **FwpsStreamInjectAsync0** is a specific version of **FwpsStreamInjectAsync**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `injectionHandle` [in]

An injection handle that was previously created by a call to the
[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0) function.

### `injectionContext` [in, optional]

An optional handle to the injection context.

### `flags` [in]

Reserved. Callout drivers should set this parameter to zero.

### `flowId` [in]

A run-time identifier that specifies the data flow into which to inject the data. The run-time
identifier for a data flow is provided to a callout driver through the FWPS_METADATA_FIELD_FLOW_HANDLE
metadata value that the filter engine provided to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

### `calloutId` [in]

The run-time identifier for the callout in the filter engine. This identifier was returned when
the callout driver called either the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) or
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) functions to
register the callout with the filter engine.

### `layerId` [in]

The run-time identifier for the filtering layer at which the data stream is being processed. This
value must be either FWPS_LAYER_STREAM_V4 or FWPS_LAYER_STREAM_V6. The run-time identifier for the layer
at which the data stream is being processed is provided to a callout in the
**layerId** member of the
[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0) structure that
the filter engine passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

### `streamFlags` [in]

Flags that specify characteristics of the data stream into which the data is to be injected.

When injecting data into an inbound data stream, a callout driver specifies one or more of the
following flags:

#### FWPS_STREAM_FLAG_RECEIVE

Specifies that the data is to be injected into the inbound data stream. This flag is required
when injecting data into an inbound data stream.

#### FWPS_STREAM_FLAG_RECEIVE_DISCONNECT

Specifies that the FIN flag is to be set in the TCP header for the data being injected into the
inbound data stream.

**Note** If this flag is set, the **FWPS_STREAM_FLAG_RECEIVE** flag must also be set, or else **STATUS_FWP_INVALID_PARAMETER** will be returned.

#### FWPS_STREAM_FLAG_RECEIVE_EXPEDITED

Specifies that the data being injected into the inbound data stream is high-priority,
out-of-band data.

#### FWPS_STREAM_FLAG_RECEIVE_PUSH

Specifies that the inbound data has arrived with the PUSH flag set in the TCP header, which
indicates that the sender requests immediate data transfer. Unwanted delays in data transfer can occur
if this flag is not set. This flag is available starting with Windows Vista with SP1.

When injecting data into an outbound data stream, a callout driver specifies one or more of the
following flags:

#### FWPS_STREAM_FLAG_SEND

Specifies that the data is to be injected into the outbound data stream. This flag is required
when injecting data into an outbound data stream.

#### FWPS_STREAM_FLAG_SEND_EXPEDITED

Specifies that the data being injected into the outbound data stream is high-priority,
out-of-band data.

#### FWPS_STREAM_FLAG_SEND_NODELAY

Specifies that the callout driver requests that there is no buffering of the data being injected
into the outbound data stream.

#### FWPS_STREAM_FLAG_SEND_DISCONNECT

Specifies that the stream is to be disconnected after the data being injected into the outbound
data stream has been sent. The network stack will set the FIN flag in the TCP header of the last
packet that is sent out.

**Note** If this flag is set, the **FWPS_STREAM_FLAG_SEND** flag must also be set, or else **STATUS_FWP_INVALID_PARAMETER** will be returned.

### `netBufferList` [in, out]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that describes
the data that is being injected into the data stream. A callout driver allocates a **NET_BUFFER_LIST**
structure to use for injecting data into a data stream by calling the
[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0),
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0), or
[FwpsCloneStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsclonestreamdata0) functions. The
**NET_BUFFER_LIST** structure can describe a chain of network buffer lists. If the
*streamFlags* parameter is **FWPS_STREAM_FLAG_RECEIVE_DISCONNECT** or **FWPS_STREAM_FLAG_SEND_DISCONNECT**,
*netBufferList* can be **NULL**.

### `dataLength` [in]

The number of bytes of data being injected into the data stream.

### `completionFn` [in]

A pointer to a
[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) callout function provided by
the callout driver. The filter engine calls this function after the packet data, described by the
*netBufferList* parameter, has been injected into the network stack.

If the
*netBufferList* parameter describes a [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) chain,
*completionFn* will be called once for each **NET_BUFFER_LIST** in the chain.

If the
*netBufferList* parameter is **NULL** and the
*streamFlags* parameter has either **FWPS_STREAM_FLAG_RECEIVE_DISCONNECT** or **FWPS_STREAM_FLAG_SEND_DISCONNECT** set, the [completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0) function will not be called.

This parameter is required and cannot be **NULL**. If it is **NULL**, **STATUS_FWP_NULL_POINTER** will be returned.

### `completionContext` [in, optional]

A pointer to a callout driver–provided context that is passed to the callout function pointed to
by the
*completionFn* parameter. This parameter is optional and can be **NULL**.

## Return value

The
**FwpsStreamInjectAsync0** function an NTSTATUS code such as one of the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The injection into the data stream was initiated successfully. The filter engine will call the completion function that was specified when the [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure was allocated after the filter engine has completed injecting the data into the data stream. |
| **STATUS_FWP_TCPIP_NOT_READY** | The TCP/IP network stack is not ready to accept injection of stream data. |
| **STATUS_FWP_INJECT_HANDLE_CLOSING** | The injection handle is being closed. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsStreamInjectAsync0** function from within a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function to inject new
or cloned data into the data stream that is currently being processed. A callout driver can call the
FwpsStreamInjectAsync0 function only if it is processing a data flow at the stream layer.

A callout driver can also call the
**FwpsStreamInjectAsync0** function from outside of a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function to inject data into a data stream that is currently deferred. A data
stream is deferred when a callout's
*classifyFn* callout function sets the
**streamAction** member of the
[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_) structure to FWPS_STREAM_ACTION_DEFER.

In addition, a callout driver can call the
**FwpsStreamInjectAsync0** function from outside of a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function to inject data into a data stream after a FIN indication has been
pended.

Alternately, a callout driver can call the
**FwpsStreamInjectAsync0** function from an arbitrary thread context outside a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function if the callout driver clones and blocks all data indicated for
out-of-band processing. A callout driver that redirects all indicated data to user mode for processing
can call the
**FwpsStreamInjectAsync0** function in this way.

A callout can pend a data segment by first cloning it with a call to the
[FwpsCloneStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsclonestreamdata0) function,
followed by blocking the data segment by setting FWP_ACTION_BLOCK in the
**actionType** member of the
[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure.

Injected stream data will not be reindicated to the callout, but it will be made available to stream
callouts from lower-weight sublayers.

If the return value is not STATUS_SUCCESS, the completion function will not be called. In this case,
the network buffer list pointed to by
*netBufferList* must be freed by a call to
[FwpsFreeNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreenetbufferlist0) or
[FwpsFreeCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsfreeclonenetbufferlist0).

## See also

[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0)

[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_)

[FwpsAllocateCloneNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocateclonenetbufferlist0)

[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsCloneStreamData0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsclonestreamdata0)

[FwpsInjectionHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandlecreate0)

[FwpsInjectionHandleDestroy0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsinjectionhandledestroy0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[completionFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_inject_complete0)