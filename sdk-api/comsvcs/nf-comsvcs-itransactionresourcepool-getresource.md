# ITransactionResourcePool::GetResource

## Description

Retrieves an object from the list of pooled objects.

## Parameters

### `pPool` [in]

The key to each object in the transaction resource pool. It determines the type of pooled object to retrieve from the list.

### `ppUnk` [out]

A reference to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the pooled object.

The object that is retrieved must have the same [IObjPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjpool) pointer as an object that was put on the list by using [PutResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-itransactionresourcepool-putresource).

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAILED** | The *pPool* parameter did not match any object on the list of pooled objects. |

## See also

[IObjPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjpool)

[ITransactionResourcePool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactionresourcepool)