# ICertRequest::GetRequestId

## Description

The **GetRequestId** method gets the current internal request number for the request and subsequent certificate.

This can be used to reference a request unambiguously to a server administrator or other interface.

## Parameters

### `pRequestId` [out]

A pointer to the request ID value.

## Return value

### C++

If the method succeeds, the method returns S_OK.

Upon successful completion of this function, **pRequestId* is set to the value of the request ID.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the current internal request number for the request and subsequent certificate.

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)