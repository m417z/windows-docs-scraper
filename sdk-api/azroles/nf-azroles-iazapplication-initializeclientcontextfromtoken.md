# IAzApplication::InitializeClientContextFromToken

## Description

The **InitializeClientContextFromToken** method gets an [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object pointer from the specified client token.

## Parameters

### `ullTokenHandle` [in]

A handle to a Windows token that specifies the client. If this parameter is **NULL**, the impersonation token of the caller's thread is used. If the thread does not have an impersonation token, the process token is used. The token must have been opened for TOKEN_QUERY, TOKEN_IMPERSONATE, and TOKEN_DUPLICATE access.

### `varReserved` [in, optional]

Reserved for future use.

### `ppClientContext` [out]

A pointer to a pointer to the returned [IAzClientContext](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.