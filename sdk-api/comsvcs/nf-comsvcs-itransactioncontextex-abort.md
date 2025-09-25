# ITransactionContextEx::Abort

## Description

Aborts the work of all COM objects participating in the current transaction. The transaction ends on return from this method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The transaction was aborted. |
| **E_FAIL** | The [TransactionContextEx](https://learn.microsoft.com/windows/desktop/cossdk/transactioncontextex) object is not running under a COM+ process, possibly indicating a corrupted registry entry for the **TransactionContextEx** component. |

## Remarks

Calling **Abort** ends the transaction on return of the method and automatically deactivates all participating objects. Each resource manager enlisted in the transaction rolls back the operations performed on behalf of those objects.

#### Examples

```cpp
ITransactionContextEx* pTransactionContext = NULL;
IMyObject* pMyObject = NULL;
boolean bUserCanceled = FALSE;
HRESULT hr;

// Get TransactionContextEx.
hr = CoCreateInstance(CLSID_ITransactionContextEx,
  NULL, CLSCTX_INPROC, IID_ITransactionContextEx,
  (void**)&pTransactionContext);
if (FAILED(hr)) throw(hr);

// Create an instance of MyObject.
hr = pTransactionContext->CreateInstance(CLSID_CMyObject,
  IID_IMyObject, (void**)&pMyObject);
if (FAILED(hr)) throw(hr);

// Do some work here.

// If something goes wrong, abort the transaction.
if (bUserCanceled) {
    hr = pTransactionContext->Abort();
    if (FAILED(hr)) throw(hr);

// Otherwise, commit it.
} else {
    hr = pTransactionContext->Commit();
    if (FAILED(hr)) throw(hr);
}

```

## See also

[ITransactionContextEx](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactioncontextex)