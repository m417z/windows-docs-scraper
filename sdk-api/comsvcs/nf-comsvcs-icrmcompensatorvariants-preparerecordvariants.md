# ICrmCompensatorVariants::PrepareRecordVariants

## Description

Delivers a log record to the CRM Compensator during the prepare phase. Log records are delivered in the order in which they were written.

## Parameters

### `pLogRecord` [in]

The log record (as a **Variant** array of **Variants**).

### `pbForget` [out]

Indicates whether the delivered record should be forgotten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be received by the CRM Compensator multiple times, once for each log record that is written.

For the [ICrmCompensatorVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensatorvariants) interface, log records are delivered in the same way that they were written. The CRM flags and sequence number are appended as the last two elements in the array. (See **ICrmCompensator::PrepareRecord**.)

If no log records are written by the CRM Worker, the [BeginPrepareVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensatorvariants-beginpreparevariants) and [EndPrepareVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensatorvariants-endpreparevariants) methods are received by the CRM Compensator but there are no **PrepareRecordVariants** method calls. This is to allow for CRM Compensators that write log records at prepare time only.

The CRM Compensator can choose to forget the record that is delivered to it during this phase by setting the forget flag on return from this method.

## See also

[ICrmCompensatorVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensatorvariants)