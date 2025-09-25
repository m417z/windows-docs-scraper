# IServiceTransactionConfigBase::IsolationLevel

## Description

Sets the isolation level of the transactions.

## Parameters

### `option` [in]

A value from the [COMAdminTxIsolationLevelOptions](https://learn.microsoft.com/windows/desktop/api/comadmin/ne-comadmin-comadmintxisolationleveloptions) enumeration.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

A new transaction is created if the enclosing transaction is not running at the specified isolation level. This method is ignored if the enclosed code would not otherwise run in a transaction.

## See also

[IServiceTransactionConfigBase](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetransactionconfigbase)