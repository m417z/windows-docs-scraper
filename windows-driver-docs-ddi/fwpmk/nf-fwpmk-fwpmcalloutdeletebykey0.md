# FwpmCalloutDeleteByKey0 function

## Description

The **FwpmCalloutDeleteByKey0** function deletes a callout from the filter engine.

## Parameters

### `engineHandle` [in]

A handle for an open session to the filter engine. A "callout" driver calls the **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** function to open a session to the filter engine.

### `key` [in]

A pointer to a GUID that uniquely identifies the callout that is being deleted from the filter engine. This must be a pointer to the same GUID that was specified when the callout driver called the **[FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0)** function to add the callout to the filter engine.

## Return value

The **FwpmCalloutDeleteByKey0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout was successfully deleted from the filter engine. |
| **STATUS_FWP_IN_USE** | One or more filters in the filter engine specify the callout for the filter's action. |
| **STATUS_FWP_CALLOUT_NOT_FOUND** | There is not a callout in the filter engine that matches the GUID specified in the *key* parameter. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpmCalloutDeleteByKey0** function to delete a callout from the filter engine, using the GUID key to identify the callout to be deleted.

Callout drivers do not typically delete their callouts from the filter engine. In most situations, this is handled by a user-mode [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page) management application.

A callout can be deleted from the filter engine only if there are no filters in the filter engine that specify the callout for the filter's action.

**FwpmCalloutDeleteByKey0** is a specific version of **FwpmCalloutDeleteByKey**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmCalloutAdd0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutadd0)**
- **[FwpmCalloutDeleteById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmcalloutdeletebyid0)**
- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- [Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/windows-filtering-platform-start-page)