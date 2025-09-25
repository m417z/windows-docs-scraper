## Description

The **FwpmTransactionBegin0** function begins an explicit transaction within the current session.

## Parameters

### `engineHandle` [in]

Handle for an open session to the filter engine. Call **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)** to open a session to the filter engine.

### `flags` [in]

Possible values:

| Transaction flag | Meaning |
|--|--|
| 0 | Begin read/write transaction. |
| **FWPM_TXN_READ_ONLY** | Begin read-only transaction. |

## Return value

| Return code/value | Description |
|---|---|
| **ERROR_SUCCESS**<br>0 | The transaction was started successfully. |
| **FWP_E_\* error code**<br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes) for details. |
| **RPC_\* error code**<br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |
| **Other NTSTATUS codes** | An error occurred. |

## Remarks

This function cannot be called from within a transaction. It will fail with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

For a read-only transaction, the caller needs [FWPM_ACTRL_BEGIN_READ_TXN](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the filter engine. For a read/write transaction, the caller needs **FWPM_ACTRL_BEGIN_WRITE_TXN** access to the filter engine. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmTransactionBegin0** is a specific implementation of **FwpmTransactionBegin**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

- **[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0)**
- **[FwpmTransactionBegin0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmtransactionbegin0)** (user mode version)
- [FWPM_ACTRL_BEGIN_READ_TXN](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers)
- [WFP Error Codes](https://learn.microsoft.com/windows/win32/fwp/wfp-error-codes)
- [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management)
- [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control)
- [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows)