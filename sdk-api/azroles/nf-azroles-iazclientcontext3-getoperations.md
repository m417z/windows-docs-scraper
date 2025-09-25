# IAzClientContext3::GetOperations

## Description

The **GetOperations** method returns a collection of the operations, within the specified scope, that the principal represented by the current client context has permission to perform.

## Parameters

### `bstrScopeName` [in]

The name of the scope to check.

### `ppOperationCollection` [out]

The address of a pointer to the collection of operations that the principal represented by the current client context has permission to perform.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).