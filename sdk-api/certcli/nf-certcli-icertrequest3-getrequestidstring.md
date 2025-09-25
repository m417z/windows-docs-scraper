# ICertRequest3::GetRequestIdString

## Description

The **GetRequestIdString** method gets the current internal request number, formatted as a string, for the request and subsequent certificate.

This can be used to reference a request unambiguously to a server administrator or other interface.

## Parameters

### `pstrRequestId` [out, retval]

A pointer to **BSTR** variable to receive the request ID string.

## Return value

### C++

If the method succeeds, the method returns **S_OK**.

Upon successful completion of this function, the string pointed to by the *pstrRequestId* parameter is set to the request ID string.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the current internal request number, as a string, for the request and subsequent certificate.

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)