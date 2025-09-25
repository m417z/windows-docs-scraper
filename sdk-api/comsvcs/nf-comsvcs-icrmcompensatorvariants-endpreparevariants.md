# ICrmCompensatorVariants::EndPrepareVariants

## Description

Notifies the CRM Compensator that it has had all the log records available during the prepare phase.

## Parameters

### `pbOkToPrepare` [out]

Indicates whether the prepare phase succeeded, in which case it is OK to commit this transaction.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ICrmCompensatorVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensatorvariants)