# ICrmCompensatorVariants::CommitRecordVariants

## Description

Delivers a log record to the CRM Compensator during the commit phase. Log records are delivered in the order in which they were written.

## Parameters

### `pLogRecord` [in]

The log record (as a Variant array of Variants).

### `pbForget` [out]

Indicates whether the delivered record should be forgotten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be received by the CRM Compensator multiple times, once for each log record that is written. If no log records are written, the [BeginCommitVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensatorvariants-begincommitvariants) and [EndCommitVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensatorvariants-endcommitvariants) methods are received but there are no **CommitRecordVariants** method calls.

The CRM Compensator can choose to forget the record that is delivered to it during this method by setting the forget flag on return from this method.

## See also

[ICrmCompensatorVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensatorvariants)