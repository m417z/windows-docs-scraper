# ICEnroll4::addNameValuePairToRequest

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addNameValuePairToRequest** method adds an unauthenticated name-value string pair to the request. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `Flags` [in]

This parameter is reserved for future use and must be set to zero.

### `strName` [in]

The name portion of the name-value pair.

### `strValue` [in]

The value portion of the name-value pair.

## Return value

### VB

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).