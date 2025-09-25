# FwpsStreamContinue0 function

## Description

The
**FwpsStreamContinue0** function resumes the processing of an inbound data stream that was previously
deferred.

**Note** **FwpsStreamContinue0** is a specific version of **FwpsStreamContinue**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `flowId` [in]

A run-time identifier that specifies the data flow that is being resumed. The run-time identifier
for a data flow is provided to a callout driver through the FWPS_METADATA_FIELD_FLOW_HANDLE metadata
value that the filter engine provided to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function.

### `calloutId` [in]

The run-time identifier for the callout that deferred the inbound data stream. This identifier was
returned when the callout driver called either the
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

Flags that specify characteristics of the inbound data stream that is being resumed. A callout
driver should specify the same stream flags that were set in the
**streamFlags** member of the
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure that the
filter engine passed to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function when the
callout deferred the data stream.

## Return value

The
**FwpsStreamContinue0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Processing of the data stream was successfully resumed. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsStreamContinue0** function to resume processing an inbound data stream that was previously
deferred. A data stream is deferred when a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function sets the
**streamAction** member of the
[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_) structure to FWPS_STREAM_ACTION_DEFER. The **FwpsStreamContinue0** function cannot be called from within a callout's *classifyFn* context.

## See also

[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0)

[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)