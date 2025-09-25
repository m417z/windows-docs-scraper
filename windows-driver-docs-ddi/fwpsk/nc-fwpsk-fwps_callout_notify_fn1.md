# FWPS_CALLOUT_NOTIFY_FN1 callback function

## Description

The filter engine calls a callout's
*notifyFn1* callout function to notify the callout driver about events that are associated with the
callout.

**Note** *notifyFn1* is the specific version of [notifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 8, [notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn2) is available. For Windows Vista, [notifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn0) is available.

## Parameters

### `notifyType` [in]

A value that indicates the type of notification that the filter engine is sending to the callout.
Valid values for this parameter are:

#### FWPS_CALLOUT_NOTIFY_ADD_FILTER

A filter is being added to the filter engine that specifies the callout for the filter's
action.

#### FWPS_CALLOUT_NOTIFY_DELETE_FILTER

A filter is being deleted from the filter engine that specifies the callout for the filter's
action.

#### FWPS_CALLOUT_NOTIFY_TYPE_MAX

A maximum value for testing purposes.

### `filterKey` [in]

A pointer to the management identifier for the filter, as specified by the application or driver
that is adding or deleting the filter. Must be **NULL** if the
*notifyType* parameter is set to FWPS_CALLOUT_NOTIFY_DELETE_FILTER. For more information, see Remarks.

### `filter` [in]

A pointer to an
[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1) structure. This structure
describes the filter that is being added to or deleted from the filter engine.

A callout driver's
*notifyFn1* function can set the
**Context** member of this structure to point to a callout driver-supplied context structure when the
filter is added to the filter engine. This context structure is opaque to the filter engine, and can be
used by the callout driver's
[classifyFn1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_classify_fn1) callout function to preserve
any driver-specific data or state information between calls by the filter engine to the callout driver's
*classifyFn1* callout function.

A callout driver's
*notifyFn1* function can clean up any context associated with the filter when the filter is deleted
from the filter engine.

## Return value

A callout's
*notifyFn1* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **Other status codes** | An error occurred. If the *notifyType* parameter is FWPS_CALLOUT_NOTIFY_ADD_FILTER, the filter will not be added to the filter engine. If the *notifyType* parameter is FWPS_CALLOUT_NOTIFY_DELETE_FILTER, the filter will still be deleted from the filter engine. |

## Remarks

A callout driver registers a callout's callout functions with the filter engine by calling the
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) function.

The filter engine calls a callout driver's
*notifyFn1* function to notify the callout driver about events that are associated with the callout.
If the callout driver's
*notifyFn1* function does not recognize the type of notification that is passed in the
*notifyType* parameter, it should ignore the notification and return STATUS_SUCCESS.

If a callout driver registers a callout with the filter engine after filters that specify the callout
for the filter's action have already been added to the filter engine, the filter engine does not call the
callout driver's
*notifyFn1* function to notify the callout about any of the existing filters. The filter engine calls
the callout driver's
*notifyFn1* function to notify the callout when new filters that specify the callout for the filter's
action are added to the filter engine. In this situation, a callout's
*notifyFn1* function might not get called for every filter in the filter engine that specifies the
callout for the filter's action. If a callout driver registers a callout after the filter engine is
started and the callout needs to know about every filter in the filter engine that specifies the callout
for the filter's action, the callout driver must call the appropriate management functions to enumerate
all the filters in the filter engine and sort through the resulting list of filters to find those that
specify the callout for the filter's action. See
[Calling Other
Windows Filtering Platform Functions](https://learn.microsoft.com/windows-hardware/drivers/network/calling-other-windows-filtering-platform-functions) for more information about calling these functions.

When a filter that specifies a callout for the filter's action is deleted from the filter engine, the
filter engine calls the callout driver's
*notifyFn1* function and passes FWP_CALLOUT_NOTIFY_DELETE_FILTER in the
*notifyType* parameter and **NULL** in the
*filterKey* parameter. For more information, see
[Processing Notify Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/processing-notify-callouts).

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_CALLOUT0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout0_)

[FWPS_FILTER1](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter1)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[notifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[notifyFn0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn0)

[notifyFn2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_notify_fn2)