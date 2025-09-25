# FwpmTransactionBegin0 function

## Description

The **FwpmTransactionBegin0** function begins an explicit transaction within the current session.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `flags` [in]

Type: **UINT32**

Possible values:

| Transaction flag | Meaning |
| --- | --- |
| 0 | Begin read/write transaction. |
| **FWPM_TXN_READ_ONLY** | Begin read-only transaction. |

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The transaction was started successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

This function cannot be called from within a transaction. It will fail
with **FWP_E_TXN_IN_PROGRESS**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

For a read-only transaction, the caller needs [FWPM_ACTRL_BEGIN_READ_TXN](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the filter engine. For a read/write transaction, the caller needs **FWPM_ACTRL_BEGIN_WRITE_TXN** access to the filter engine. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmTransactionBegin0** is a specific implementation of FwpmTransactionBegin. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example illustrates wrapping the [FwpmFilterAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfilteradd0) function in an FWP transaction.

```cpp
#include <windows.h>
#include <fwpmu.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")

void main()
{
    HANDLE engineHandle = NULL;

    FWPM_FILTER0      fwpFilter;

    RtlZeroMemory(&fwpFilter, sizeof(FWPM_FILTER0));
    fwpFilter.layerKey = FWPM_LAYER_ALE_AUTH_RECV_ACCEPT_V4;
    fwpFilter.action.type = FWP_ACTION_BLOCK;
    fwpFilter.weight.type = FWP_EMPTY;
    fwpFilter.numFilterConditions = 0;

    DWORD  result = ERROR_SUCCESS;
    DWORD fwpTxStatus = ERROR_SUCCESS;

    printf("Opening filter engine.\n");
    result = FwpmEngineOpen0(NULL, RPC_C_AUTHN_WINNT, NULL, NULL, &engineHandle);
      if (result != ERROR_SUCCESS)
      {
        printf("FwpmEngineOpen0 failed (%d).\n", result);
        return;
    }

      printf("Adding filter to permit traffic for Application 1.\n");
      fwpTxStatus = FwpmTransactionBegin0(engineHandle, NULL);
      if (fwpTxStatus != ERROR_SUCCESS)
      {
        printf("FwpmTransactionBegin0 failed (%d).\n", fwpTxStatus);
        return;
    }

    result = FwpmFilterAdd0(engineHandle, &fwpFilter, NULL, NULL);
      if (result != ERROR_SUCCESS)
      {
        printf("FwpmFilterAdd0 failed (%d).\n", result);
        return;
    }

    result = FwpmTransactionCommit0(engineHandle);
    if (result != ERROR_SUCCESS)
    {
        printf("FwpmTransactionCommit0 failed (%d).\n", result);
        return;
    }
    else
    {
        printf("Filter transaction (adding a filter) committed successfully.\n");
    }

    return;
}
// ----------------------------------------------------------------------

```

## See also

[FwpmTransactionAbort0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmtransactionabort0)

[FwpmTransactionCommit0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmtransactioncommit0)