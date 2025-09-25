## Description

The filter engine calls a callout's **classifyFn2** callout function whenever there is data to be processed by the callout.

> [!NOTE]
> **classifyFn2** is the specific version of **classifyFn** used in Windows 8 and later. For more info, see [WFP version-independent names and targeting specific versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows). For Windows 7, **classifyFn1** is available. For Windows Vista, **classifyFn0** is available.

## Parameters

### `inFixedValues`

A pointer to an [FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0) structure. This structure contains the values for each of the data fields at the layer being filtered.

### `inMetaValues`

A pointer to an [FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows/win32/api/fwpsu/ns-fwpsu-fwps_incoming_metadata_values0) structure. This structure contains the values for each of the metadata fields at the layer being filtered.

### `layerData`

A pointer to a structure that describes the raw data at the layer being filtered. This parameter might be **NULL**, depending on the layer being filtered and the conditions under which the **classifyFn2** callout function is called. For the stream layer, this parameter points to an **FWPS_STREAM_CALLOUT_IO_PACKET0** structure. For all of the other layers, this parameter points to a **NET_BUFFER_LIST** structure if it is not **NULL**.

### `classifyContext`

A pointer to context data associated with the callout driver by the filter engine.

### `filter`

A pointer to an [FWPS_FILTER2](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter2) structure. This structure describes the filter that specifies the callout for the filter's action.

### `flowContext`

A UINT64-typed variable that contains the context associated with the data flow. If no context is associated with the data flow, then this parameter is zero. If the callout is added to the filter engine at a filtering layer that does not support data flows, the **classifyFn2** callout function should ignore this parameter.

### `classifyOut`

A pointer to an [FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure that receives any data that the **classifyFn2** callout function returns to the caller.

## Remarks

A callout driver registers a callout's callout functions with the filter engine by calling the **FwpsCalloutRegister2** function.

The filter engine calls a callout's **classifyFn2** callout function with data to be processed whenever all of the test conditions are true for a filter in the filter engine that specifies the callout for the filter's action.

A callout's **classifyFn1** callout function should clear the **FWPS_RIGHT_ACTION_WRITE** flag in the *rights* member of the [FWPS_CLASSIFY_OUT0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_classify_out0) structure in any of the following situations:

* When the **classifyFn1** callout function sets the *actionType* member of the **FWPS_CLASSIFY_OUT0** structure to **FWP_ACTION_BLOCK**.
* When the **classifyFn1** callout function sets the *actionType* member of the **FWPS_CLASSIFY_OUT0** structure to **FWP_ACTION_PERMIT** and the **FWPS_FILTER_FLAG_CLEAR_ACTION_RIGHT** flag is set in the *flags* member of the [FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1) structure.
* When a callout has indicated that it intends to modify the clone net buffer list by setting the *intendToModify* parameter to **TRUE** in a call to the **FwpsReferenceNetBufferList0** function.

## See also