# FwpmEngineClose0 function

## Description

The **FwpmEngineClose0** function closes a session to a filter engine.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The session was closed successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

After an application has completed adding or removing system objects, it may call the **FwpmEngineClose0** function to close the open session to the filter engine.

A filter engine session is also closed when a client process terminates.

If this function is called with a transaction in progress, the transaction will be aborted.

**FwpmEngineClose0** is a specific implementation of FwpmEngineClose. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0)

[Kernel-Mode FwpmEngineClose0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmengineclose0)