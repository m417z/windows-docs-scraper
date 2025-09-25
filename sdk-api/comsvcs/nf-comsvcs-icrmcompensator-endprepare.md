# ICrmCompensator::EndPrepare

## Description

Notifies the CRM Compensator that it has had all the log records available during the prepare phase. The CRM Compensator votes on the transaction outcome by using the return parameter of this method.

## Parameters

### `pfOkToPrepare` [out]

Indicates whether the prepare phase succeeded, in which case it is OK to commit this transaction.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)