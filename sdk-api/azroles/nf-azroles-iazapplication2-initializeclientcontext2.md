# IAzApplication2::InitializeClientContext2

## Description

The **InitializeClientContext2** method retrieves an [IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2) object pointer.

## Parameters

### `IdentifyingString` [in]

A string that identifies the client context in the audit trail for client connection and object access audit entries.

### `varReserved` [in, optional]

Reserved for future use.

### `ppClientContext` [out]

A pointer to a pointer to the returned [IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2) object.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).