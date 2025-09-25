# ICrmLogControl::ForgetLogRecord

## Description

Forgets the last log record written by this instance of the interface.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | There is no valid log record to forget. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **XACT_E_ABORTED** | The transaction has aborted, most likely because of a transaction time-out. |

## Remarks

This method can be used to forget only the last record because there is no concept of nesting; that is, write, forget, write, forget is valid, but write, write, forget, forget is not. A log record that has been forgotten is not delivered to the CRM Compensator during transaction outcome notifications.

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)