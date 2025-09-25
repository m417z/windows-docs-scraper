# FwpmCalloutAdd0 function

## Description

The **FwpmCalloutAdd0** function adds a callout to the filter engine.

## Parameters

### `engineHandle` [in]

A handle for an open session to the filter engine. A callout driver calls the [FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0) function to open a session to the filter engine.

### `callout` [in]

A pointer to a constant [FWPM_CALLOUT0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550076(v=vs.85)) structure that contains the data that is required to add the callout to the filter engine.

### `sd` [in, optional]

A pointer to a constant [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that describes the security descriptor for the callout that is being added to the filter engine. This parameter is optional and can be **NULL**.

### `id` [out, optional]

A pointer to a UINT32-typed variable that receives a run-time identifier that identifies the callout in the filter engine. This is the same identifier that is returned when a callout driver registers the callout driver's callout functions with the filter engine. The callout driver passes this identifier to the [FwpmCalloutDeleteById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutdeletebyid0) function when removing the callout from the filter engine. This parameter is optional and can be **NULL**.

## Return value

The **FwpmCalloutAdd0** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout was successfully added to the filter engine. |
| **STATUS_FWP_ALREADY_EXISTS** | The callout could not be added to the filter engine. A callout already exists in the filter engine with an identifier identical to the GUID specified in the **calloutKey** member of the [FWPM_CALLOUT0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550076(v=vs.85)) structure pointed to by the *callout* parameter. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpmCalloutAdd0** function to add a callout to the filter engine.

Callout drivers do not typically add their callouts to the filter engine. In most situations this is handled by a user-mode Windows Filtering Platform management application.

A callout and filters that specify the callout for the filter's action can be added to the filter engine before a callout driver registers the callout with the filter engine. In this situation, filters with an action type of **FWP_ACTION_CALLOUT_TERMINATING** or **FWP_ACTION_CALLOUT_UNKNOWN** are treated as **FWP_ACTION_BLOCK** and filters with an action type of **FWP_ACTION_CALLOUT_INSPECTION** are ignored until the callout is registered with the filter engine.

**FwpmCalloutAdd0** is a specific version of **FwpmCalloutAdd**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- [FWPM_CALLOUT0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550076(v=vs.85))
- [FwpmCalloutDeleteById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutdeletebyid0)
- [FwpmCalloutDeleteByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutdeletebykey0)
- [FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)
- [Types of Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-callouts)