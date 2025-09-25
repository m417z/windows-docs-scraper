# FwpmBfeStateUnsubscribeChanges0 function

## Description

The **FwpmBfeStateUnsubscribeChanges0** function deregisters a base filtering engine (BFE) callback function that was previously registered by calling the [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0) function.

> [!WARNING]
> Do not call **FwpmBfeStateUnsubscribeChanges0** from a callback function that your driver previously registered by calling [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0). Doing so can cause a deadlock.

## Parameters

### `changeHandle` [in, out]

A handle associated with the registration of the callback function that is being deregistered. This handle was returned to the callout driver when it called the [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0) function to register the callback function.

## Return value

The **FwpmBfeStateUnsubscribeChanges0** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callback function was successfully deregistered. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpmBfeStateUnsubscribeChanges0** function to deregister a callback function that was previously registered by calling the [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0) function.

If a callout driver registers a callback function by calling the [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0) function, it must deregister the callback function before the callout driver can be unloaded.

**FwpmBfeStateUnsubscribeChanges0** is a specific version of **FwpmBfeStateUnsubscribeChanges**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0)