## Description

The **FWPM_SERVICE_STATE_CHANGE_CALLBACK0** function is implemented by a WFP callout driver to add custom behavior to the base filtering engine (BFE) service state change notification process.

## Parameters

### `context`

The pointer that was passed in the *context* parameter when the callout driver called the **[FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0)** function.

### `newState`

The new BFE service state being changed to.

## Return value

## Remarks

The filter engine calls this function whenever there is a change in the state of the filter engine.

## See also

- **[FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0)**
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)