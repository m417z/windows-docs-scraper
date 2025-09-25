# ICrmCompensator::BeginPrepare

## Description

Notifies the CRM Compensator of the prepare phase of the transaction completion and that records are about to be delivered. Prepare notifications are never received during recovery, only during normal processing.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)