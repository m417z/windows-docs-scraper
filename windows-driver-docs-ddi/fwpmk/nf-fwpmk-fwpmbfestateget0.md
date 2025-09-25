# FwpmBfeStateGet0 function

## Description

The **FwpmBfeStateGet0** function retrieves the current state of the filter engine.

## Return value

The **FwpmBfeStateGet0** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **FWPM_SERVICE_STOPPED** | The filter engine is not running. |
| **FWPM_SERVICE_START_PENDING** | The filter engine is starting. |
| **FWPM_SERVICE_STOP_PENDING** | The filter engine is stopping. |
| **FWPM_SERVICE_RUNNING** | The filter engine is running. |

## Remarks

A callout driver calls the **FwpmBfeStateGet0** function to retrieve the current state of the filter engine. For a callout driver to open a session to the filter engine, the filter engine must be currently running.

Before calling **FwpmBfeStateGet0**, the callout driver must call the [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0) function to register a callback function that is called whenever the state of the filter engine changes.

**FwpmBfeStateGet0** is a specific version of **FwpmBfeStateGet**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- [FwpmBfeStateSubscribeChanges0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmbfestatesubscribechanges0)