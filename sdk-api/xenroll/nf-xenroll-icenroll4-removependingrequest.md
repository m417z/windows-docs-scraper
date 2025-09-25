# ICEnroll4::removePendingRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **removePendingRequest** method removes a pending request from the client's request store. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `strThumbprint` [in]

The thumbprint, or [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly), of the certificate data.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).