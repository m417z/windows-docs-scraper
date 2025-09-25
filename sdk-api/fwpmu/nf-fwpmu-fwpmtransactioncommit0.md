# FwpmTransactionCommit0 function

## Description

The **FwpmTransactionCommit0** function commits the current transaction within the current session.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The transaction was committed successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function can only be called from within a transaction. Otherwise, it will fail
with **FWP_E_NO_TXN_IN_PROGRESS**.

**FwpmTransactionCommit0** is a specific implementation of FwpmTransactionCommit. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FwpmTransactionAbort0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmtransactionabort0)

[FwpmTransactionBegin0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmtransactionbegin0)