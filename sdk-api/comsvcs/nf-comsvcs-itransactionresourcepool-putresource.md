# ITransactionResourcePool::PutResource

## Description

Adds an object to the list of pooled objects.

## Parameters

### `pPool` [in]

The key to each object in the transaction resource pool. It determines the type of pooled object to add to the list.

### `pUnk` [in]

A reference to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the pooled object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IObjPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjpool)

[ITransactionResourcePool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionresourcepool)