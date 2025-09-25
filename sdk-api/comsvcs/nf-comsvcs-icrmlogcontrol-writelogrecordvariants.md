# ICrmLogControl::WriteLogRecordVariants

## Description

The CRM Worker and CRM Compensator use this method to write structured log records to the log.

## Parameters

### `pLogRecord` [in]

A pointer to a **Variant** array of **Variants**. This must be a single-dimension array whose lower bound is zero.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the arguments is incorrect. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **XACT_E_ABORTED** | The transaction has aborted, most likely because of a transaction time-out. |

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)