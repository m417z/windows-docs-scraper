# ICrmLogControl::ForceTransactionToAbort

## Description

Performs an immediate abort call on the transaction.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **XACT_E_ABORTED** | The transaction has aborted, most likely because of a transaction time-out. |

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)