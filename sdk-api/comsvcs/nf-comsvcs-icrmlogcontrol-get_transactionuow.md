# ICrmLogControl::get_TransactionUOW

## Description

Retrieves the transaction unit of work (UOW) without having to log the transaction UOW in the log record.

## Parameters

### `pVal` [out]

The UOW of the transaction.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **E_OUTOFMEMORY** | An out of memory error has occurred. |

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)