# FwpmCalloutDeleteById0 function

## Description

The **FwpmCalloutDeleteById0** function deletes a callout from the filter engine.

## Parameters

### `engineHandle` [in]

A handle for an open session to the filter engine. A callout driver calls the **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** function to open a session to the filter engine.

### `id` [in]

The run-time identifier for the callout that is being deleted from the filter engine. This must be the run-time identifier that was returned when the callout driver called the [FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0) function to add the callout to the filter engine.

## Return value

The **FwpmCalloutDeleteById0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout was successfully deleted from the filter engine. |
| **STATUS_FWP_IN_USE** | One or more filters in the filter engine specify the callout for the filter's action. |
| **STATUS_FWP_CALLOUT_NOT_FOUND** | There is not a callout in the filter engine that matches the run-time identifier specified in the *id* parameter. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpmCalloutDeleteById0** function to delete a callout from the filter engine, using the run-time identifier to identify the callout to be deleted.

Callout drivers do not typically delete their callouts from the filter engine. In most situations, this is handled by a user-mode [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page) management application.

A callout can be deleted from the filter engine only if there are no filters in the filter engine that specify the callout for the filter's action.

**FwpmCalloutDeleteById0** is a specific version of **FwpmCalloutDeleteById**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- [FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0)
- [FwpmCalloutDeleteByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutdeletebykey0)
- [FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)