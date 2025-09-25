# ICertServerPolicy::EnumerateExtensionsSetup

## Description

The **EnumerateExtensionsSetup** method initializes the internal enumeration pointer to the first certificate extension associated with the current context.

## Parameters

### `Flags` [in]

This parameter is reserved and must be set to zero.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The
[SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) method must be called prior to calling this method. The call to **SetContext** specifies which request is the current context.

To retrieve the extension, call the [EnumerateExtensions](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensions) method. The call to **EnumerateExtensions** retrieves the first extension and moves the index to the next extension if one exists.

#### Examples

```cpp
// Set the context. The value nContext (long) would be the same
// as the context parameter in ICertPolicy::VerifyRequest.
// hr is defined as an HRESULT.
// pCertServerPolicy has been used to call SetContext previously.
hr = pCertServerPolicy->SetContext( nContext );
if (FAILED(hr))
{
    printf("Failed SetContext [%x]\n", hr);
    goto error;
}
// Setup the enumeration.
hr = pCertServerPolicy->EnumerateExtensionsSetup( 0 );
if (FAILED(hr))
{
    printf("Failed EnumerateExtensionsSetup [%x]\n", hr);
    goto error;
}
```

## See also

[EnumerateExtensions](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensions)

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)