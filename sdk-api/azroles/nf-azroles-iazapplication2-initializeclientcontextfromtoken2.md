# IAzApplication2::InitializeClientContextFromToken2

## Description

The **InitializeClientContextFromToken2** method retrieves an [IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2) object pointer from the specified client token.

## Parameters

### `ulTokenHandleLowPart` [in]

Low byte of a handle to a token that specifies the client. If the values of both this parameter and the *ulTokenHandleHighPart* parameter are zero, the impersonation token of the caller's thread is used. If the thread does not have an impersonation token, the process token is used. The token must have been opened for TOKEN_QUERY, TOKEN_IMPERSONATE, or TOKEN_DUPLICATE access.

### `ulTokenHandleHighPart` [in]

High byte of a handle to a token that specifies the client. If the values of both this parameter and the *ulTokenHandleHighPart* parameter are zero, the impersonation token of the caller's thread is used. If the thread does not have an impersonation token, the process token is used. The token must have been opened for TOKEN_QUERY, TOKEN_IMPERSONATE, or TOKEN_DUPLICATE access.

### `varReserved` [in, optional]

Reserved for future use.

### `ppClientContext` [out]

A pointer to a pointer to the returned [IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2) object.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).