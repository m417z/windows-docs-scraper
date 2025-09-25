# ICertServerExit::EnumerateExtensionsSetup

## Description

The **EnumerateExtensionsSetup** method initializes the internal enumeration pointer to the first certificate extension associated with the current context.

The enumeration process enumerates certificate extensions recorded in the database, even those that are disabled and do not appear in the certificate.

## Parameters

### `Flags` [in]

This parameter is reserved and must be set to zero.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call
[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext) before using this method.

#### Examples

```cpp
// Set the context. The value nContext (long) would be the same
// as the context parameter in ICertExit::Notify.
// hr is defined as an HRESULT.
hr = pCertServerExit->SetContext( nContext );
if (FAILED(hr))
{
    printf("Failed SetContext [%x]\n", hr);
    goto error;
}

// Setup the enumeration.
hr = pCertServerExit->EnumerateExtensionsSetup( 0 );
if (FAILED(hr))
{
    printf("Failed EnumerateExtensionsSetup [%x]\n", hr);
    goto error;
}
```

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::EnumerateExtensions](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateextensions)

[ICertServerExit::EnumerateExtensionsClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateextensionsclose)