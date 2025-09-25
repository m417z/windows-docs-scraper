# ITransactionStatus::GetTransactionStatus

## Description

Retrieves the transaction status.

## Parameters

### `pHrStatus` [out]

he status of the transaction. See Remarks section for more information.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

The *pHrStatus* parameter is a pointer to an **HRESULT** value that indicates the transaction status according to the following table.

| Value | Transaction status |
| --- | --- |
| S_OK | The transaction has committed. |
| XACT_S_LOCALLY_OK | The transaction has neither committed nor aborted. |
| XACT_E_NOTRANSACTION | No transactions were being used through [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain). |
| XACT_E_ABORTING | The transaction is doomed and will eventually abort. |
| XACT_E_ABORTED | The transaction was aborted. |

## See also

[ITransactionStatus](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionstatus)