# IAzAuthorizationStore2::OpenApplication2

## Description

The **OpenApplication2** method opens the [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object with the specified name.

## Parameters

### `bstrApplicationName` [in]

The name of the [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppApplication` [out]

A pointer to a pointer to the opened [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).