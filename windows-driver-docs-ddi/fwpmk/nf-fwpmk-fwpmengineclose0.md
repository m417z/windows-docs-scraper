# FwpmEngineClose0 function

## Description

The **FwpmEngineClose0** function closes a previously opened session to the filter engine.

## Parameters

### `engineHandle` [in, out]

A handle for an open session to the filter engine.

## Return value

The **FwpmEngineClose0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The session to the filter engine was successfully closed. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpmEngineClose0** function to close a session to the filter engine that was previously opened by a call to the [FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0) function.

**FwpmEngineClose0** is a specific version of **FwpmEngineClose**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- [FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)