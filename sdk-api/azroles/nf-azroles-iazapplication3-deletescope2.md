# IAzApplication3::DeleteScope2

## Description

The **DeleteScope2** method removes the specified [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object from the [IAzApplication3](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication3) object.

## Parameters

### `bstrScopeName` [in]

A string that contains the name of the [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object to remove.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If any references to an [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object have been deleted from the cache, you can no longer use that object. In C++, you must release references to deleted **IAzScope2** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. In Visual Basic, references to deleted objects are automatically released.