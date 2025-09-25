# ICertServerPolicy::SetContext

## Description

The **SetContext** method specifies the request to be used as the [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for subsequent calls to Certificate Services.

## Parameters

### `Context` [in]

Specifies the request. This parameter must be set to the identical value returned in the *Context* parameter of the
[ICertPolicy::VerifyRequest](https://learn.microsoft.com/windows/desktop/api/certpol/nf-certpol-icertpolicy-verifyrequest) method.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The policy module must call the **SetContext** method first, before calls to any other [ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy) method, so that the interface references a valid request.

#### Examples

```cpp
// Set the context. The value nContext (long) would be the same
// as the context parameter in ICertPolicy::VerifyRequest.
// hr is defined as an HRESULT.
hr = pCertServerPolicy->SetContext( nContext );
if (FAILED(hr))
{
    printf("Failed SetContext [%x]\n", hr);
    goto error;
}
```

## See also

[ICertPolicy::VerifyRequest](https://learn.microsoft.com/windows/desktop/api/certpol/nf-certpol-icertpolicy-verifyrequest)

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)