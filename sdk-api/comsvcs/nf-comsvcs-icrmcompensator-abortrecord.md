# ICrmCompensator::AbortRecord

## Description

Delivers a log record to the CRM Compensator during the abort phase.

## Parameters

### `crmLogRec` [in]

The log record, as a [CrmLogRecordRead](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-crmlogrecordread) structure.

### `pfForget` [out]

Indicates whether the delivered record should be forgotten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Log records are delivered in the reverse order in which they were written. This method can be received by the CRM Compensator multiple times, once for each log record that was written. If no log records are written, the [BeginAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensator-beginabort) and [EndAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensator-endabort) methods are received but there are no **AbortRecord** method calls.

The CRM Compensator can choose to forget the record that is delivered to it during this phase by setting the forget flag on return from this method.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)