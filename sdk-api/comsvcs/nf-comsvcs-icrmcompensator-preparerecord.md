# ICrmCompensator::PrepareRecord

## Description

Delivers a log record in forward order during the prepare phase. This method can be received by the CRM Compensator multiple times, once for each log record that is written.

## Parameters

### `crmLogRec` [in]

The log record, as a [CrmLogRecordRead](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-crmlogrecordread) structure.

### `pfForget` [out]

Indicates whether the delivered record should be forgotten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Unstructured log records are delivered as a [CrmLogRecordRead](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-crmlogrecordread) structure. In addition to the user data (as a single BLOB), this structure contains a couple of additional fields that might be useful for debugging or fault-finding if human compensation is necessary. The **dwCrmFlags** member is a bitfield that provides further information about whether this record was forgotten at some point and when it was written. The **dwSequenceNumber** member provides the sequence number of the log record. In most cases, sequence numbers are sequential but are not necessarily contiguous due to internal log records that are not delivered to the CRM Compensator.

If no log records are written by the CRM Worker, the [BeginPrepare](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensator-beginprepare) and [EndPrepare](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmcompensator-endprepare) methods are received but there are no **PrepareRecord** method calls. This is to allow for CRM Compensators that write log records at prepare time only.

The CRM Compensator can choose to forget the record that is delivered to it during this phase by setting the forget flag on return from this method.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)