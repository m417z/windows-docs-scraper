## Description

Defines a run-time filter in the filter engine. The [FWPS_FILTER0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter0) is available.

## Members

### `filterId`

A run-time identifier that identifies the filter in the filter engine.

### `weight`

An [FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0) structure that contains a value that specifies the filter's importance in relation to other filters in the filter engine. Filters with a higher **weight** value are invoked first. The data type specified in the **FWP_VALUE0** structure is either **FWP_UINT64** or FWP_EMPTY. If the data type specified in the **FWP_VALUE0** structure is FWP_EMPTY, the filter engine automatically assigns a weight to the filter based on how specific the filter tests the data compared to the other filters in the filter engine.

### `subLayerWeight`

A value that specifies the importance of the filter's sublayer in relation to the other sublayers in the filter engine. Filters that are located in a sublayer with a higher **subLayerWeight** value are invoked first.

### `flags`

Flags that specify actions that a callout's [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout function should take when processing network data. Possible flags are:

| Value | Meaning |
| - | - |
| FWPS_FILTER_FLAG_CLEAR_ACTION_RIGHT | This flag indicates to a callout's [classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function that it should always clear the FWPS_RIGHT_ACTION_WRITE flag when it returns either FWP_ACTION_BLOCK or FWP_ACTION_PERMIT for the suggested action. If this flag is not set, a callout's ***classifyFn0*** callout function should only clear the FWPS_RIGHT_ACTION_WRITE flag when it returns FWP_ACTION_BLOCK for the suggested action. |
| FWPS_FILTER_FLAG_PERMIT_IF_CALLOUT_UNREGISTERED | This flag indicates to a callout's [classifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function that if the callout is not registered, the callout should be treated as a permit filter. |

### `numFilterConditions`

The number of [FWPS_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter_condition0) structures in the array pointed to by the **filterCondition** member. This member can be zero.

### `filterCondition`

A pointer to an array of [FWPS_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter_condition0) structures. These structures define the run-time filtering conditions for the filter. If the **numFilterConditions** member is zero, then this pointer will be **NULL**.

### `action`

An [FWPS_ACTION0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_action0) structure that specifies the action that the filter should take if all of the filter's filtering conditions are true.

### `context`

A context value that is associated with the filter. A callout can set this member to point to a callout driver-supplied context structure from within the callout driver's [notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_notify_fn2) callout function when the filter is added to the filter engine. This context structure, which is opaque to the filter engine, can be used by the callout driver's [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout function to preserve any driver-specific data or state information between calls by the filter engine to the callout driver's ***classifyFn2*** callout function.

### `providerContext`

A pointer to the provider context, which is formatted as a [FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2) structure. If the filter uses a callout, and the callout has the FWPM_CALLOUT_FLAG_USES_PROVIDER_CONTEXT flag set, this member will contain the provider context from the corresponding [FWPM_FILTER0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0) structure. Otherwise, this parameter is **NULL**.

## Remarks

The filter engine passes a pointer to an **FWPS_FILTER2** structure to a callout's [notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_notify_fn2) and [classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn2) callout functions.

A filter's action is performed only if all of the filter's filtering conditions are true. If no filtering conditions are specified in the filter, then the specified action is always performed.

The **providerContext** member provides a mechanism for a callout driver to retrieve provider contexts without calling the base filtering engine (BFE).

This structure is essentially identical to the previous version, [FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2) structure at the **providerContext** member.

## See also

[FWPM_FILTER0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0)

[FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2)

[FWPS_ACTION0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_action0)

[FWPS_FILTER0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter0)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FWPS_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter_condition0)

[FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0)

[classifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn2)

[notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_notify_fn2)