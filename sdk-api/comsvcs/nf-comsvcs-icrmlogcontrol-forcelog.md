# ICrmLogControl::ForceLog

## Description

Forces all log records to be durable on disk.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **XACT_E_ABORTED** | The transaction has aborted, most likely because of a transaction time-out. |

## Remarks

The CRM Worker and CRM Compensator use this method to write log records lazily to the log, which means they are not made durable until they have been forced to the log. Calling **ForceLog** will make all log records that have been written durable on disk.

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)