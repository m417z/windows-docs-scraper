# IAzApplication3::CreateScope2

## Description

The **CreateScope2** method creates a new [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object with the specified name.

## Parameters

### `bstrScopeName` [in]

A string that contains the name of the new [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object.

### `ppScope2` [out]

The address of a pointer to the [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object that this method creates.

When you have finished using this [IAzScope2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope2) object, release it by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).