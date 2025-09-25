# ITransactionContext::CreateInstance

## Description

Creates a COM object that can execute within the scope of the transaction that was initiated by the transaction context object.

## Parameters

### `pszProgId` [in]

A reference to the ProgID of the type of object to be instantiated.

### `pObject` [out]

A reference to the new object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

If the Microsoft Distributed Transaction Coordinator is not running and the object is transactional, the object is successfully created. However, method calls to that object will fail with CONTEXT_E_TMNOTAVAILABLE. Objects cannot recover from this condition and should be released.

## See also

[ITransactionContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-itransactioncontext)