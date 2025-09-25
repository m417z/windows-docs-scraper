# ICertServerExit::SetContext

## Description

The **SetContext** method causes the current instantiation of the interface to operate on the request referenced by *Context*.

This must be identical to a value given by the *Context* parameter in
[ICertExit::Notify](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-notify). This method must be called before calling any of the other
[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit) methods, in order that the interface reference a valid request.

## Parameters

### `Context` [in]

Specifies the request and associated certificate under construction.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertExit::Notify](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-notify)

[ICertPolicy::VerifyRequest](https://learn.microsoft.com/windows/desktop/api/certpol/nf-certpol-icertpolicy-verifyrequest)

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)