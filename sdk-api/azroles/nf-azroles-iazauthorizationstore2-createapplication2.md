# IAzAuthorizationStore2::CreateApplication2

## Description

The **CreateApplication2** method creates an [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object by using the specified name.

## Parameters

### `bstrApplicationName` [in]

The name for the new [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppApplication` [out]

A pointer to a pointer to the created [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call the [IAzApplication::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by the returned object.

The returned [IAzApplication2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication2) object is an immediate child object of the [IAzAuthorizationStore2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore2) object.