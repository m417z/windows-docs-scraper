# IServicePoolConfig::put_TransactionAffinity

## Description

Sets whether objects involved in transactions are held until the transaction completes.

## Parameters

### `fTxAffinity` [in]

**TRUE** if the objects are to be held and **FALSE** otherwise.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IServicePoolConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicepoolconfig)