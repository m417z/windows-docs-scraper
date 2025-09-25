# FWPS_CALLOUT_CLASSIFY_FN1 callback function

## Description

The filter engine calls a callout's
*classifyFn1* callout function whenever there is data to be processed by the callout.

**Note** *classifyFn1* is the specific version of [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) is available. For Windows Vista, [classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) is available.

## Parameters

### `inFixedValues` [in]

A pointer to an
[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0) structure. This
structure contains the values for each of the data fields in the layer being filtered.

### `inMetaValues` [in]

A pointer to an
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure. This structure contains the values for each of the
metadata fields in the layer being filtered.

### `layerData` [in, out]

A pointer to a structure that describes the raw data in the layer being filtered. This parameter
might be **NULL**, depending on the layer being filtered and the conditions under which the
*classifyFn1* callout function is called. For the stream layer, this parameter points to an
[FWPS_STREAM_CALLOUT_IO_PACKET0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_callout_io_packet0_) structure. For all of the other layers, this parameter points to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure if it is not
**NULL**.

### `classifyContext` [in, optional]

A pointer to context data associated with the callout driver by the filter engine.

### `filter` [in]

A pointer to an
[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1) structure. This structure
describes the filter that specifies the callout for the filter's action.

### `flowContext` [in]

A UINT64-typed variable that contains the context associated with the data flow. If no context is
associated with the data flow, then this parameter is zero. If the callout is added to the filter engine
at a filtering layer that does not support data flows, the
*classifyFn1* callout function should ignore this parameter.

### `classifyOut` [in, out]

A pointer to an
[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure that
receives any data that the
*classifyFn1* callout function returns to the caller.

## Remarks

A callout driver registers a callout's callout functions with the filter engine by calling the
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) function.

The filter engine calls a callout's
*classifyFn1* callout function with data to be processed whenever all of the test conditions are true
for a filter in the filter engine that specifies the callout for the filter's action.

A callout's
*classifyFn1* callout function should clear the FWPS_RIGHT_ACTION_WRITE flag in the
**rights** member of the
[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure in any of
the following situations:

* When the
  *classifyFn1* callout function sets the
  **actionType** member of the
  [FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure to
  FWP_ACTION_BLOCK.
* When the
  *classifyFn1* callout function sets the
  **actionType** member of the
  [FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure to
  FWP_ACTION_PERMIT and the FWPS_FILTER_FLAG_CLEAR_ACTION_RIGHT flag is set in the
  **Flags** member of the
  [FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1) structure.
* When a callout has indicated that it intends to modify the clone net buffer list by setting the
  *intendToModify* parameter to **TRUE** in a call to the
  [FwpsReferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencenetbufferlist0) function.

## See also

[Associating Context with a Data Flow](https://learn.microsoft.com/windows-hardware/drivers/network/associating-context-with-a-data-flow)

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[Data Logging](https://learn.microsoft.com/windows-hardware/drivers/network/data-logging)

[FWPS_CALLOUT0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout0_)

[FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsReferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencenetbufferlist0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Packet Modification Examples](https://learn.microsoft.com/windows-hardware/drivers/network/packet-modification-examples)

[Registering Callouts with the Filter Engine](https://learn.microsoft.com/windows-hardware/drivers/network/registering-callouts-with-the-filter-engine)

[Using a Callout
for Deep Inspection of Stream Data](https://learn.microsoft.com/windows-hardware/drivers/network/using-a-callout-for-deep-inspection-of-stream-data)

[Using a Callout for Deep Inspection](https://learn.microsoft.com/windows-hardware/drivers/network/using-a-callout-for-deep-inspection)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)

[classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn2)