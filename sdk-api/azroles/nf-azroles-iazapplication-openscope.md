# IAzApplication::OpenScope

## Description

The **OpenScope** method opens an [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object with the specified name.

## Parameters

### `bstrScopeName` [in]

Name of the [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppScope` [out]

A pointer to a pointer to the opened [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.