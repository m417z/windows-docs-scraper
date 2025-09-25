# ITransactionContextEx::CreateInstance

## Description

Creates a COM object that can execute within the scope of the transaction that was initiated by the transaction context object.

## Parameters

### `rclsid` [in]

A reference to the CLSID of the type of object to be instantiated.

### `riid` [in]

A reference to the interface ID of the interface through which you will communicate with the new object.

### `pObject` [out]

A reference to a new object of the type specified by the *rclsid* parameter, through the interface specified by the *riid* parameter.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **REGDB_E_CLASSNOTREG** | The component specified by *rclsid* is not registered as a COM component. |

## Remarks

If the Microsoft Distributed Transaction Coordinator is not running and the object is transactional, the object is successfully created. However, method calls to that object will fail with CONTEXT_E_TMNOTAVAILABLE. Objects cannot recover from this condition and should be released.

#### Examples

```cpp
ITransactionContextEx* pTransactionContext = NULL;
IMyObject* pMyObject = NULL;
HRESULT hr;

// Get TransactionContextEx.
hr = CoCreateInstance(CLSID_TransactionContextEx,
  NULL, CLSCTX_INPROC, IID_ITransactionContextEx,
  (void**)&pTransactionContext);
if (FAILED(hr)) throw(hr);

// Create an instance of MyObject.
hr = pTransactionContext->CreateInstance(CLSID_CMyObject,
  IID_IMyObject, (void**)&pMyObject);
if (FAILED(hr)) throw(hr);

```

## See also

[ITransactionContextEx](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactioncontextex)