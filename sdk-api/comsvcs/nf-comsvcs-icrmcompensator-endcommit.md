# ICrmCompensator::EndCommit

## Description

Notifies the CRM Compensator that it has delivered all the log records available during the commit phase. All log records for this transaction can be discarded from the log after this method has completed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)