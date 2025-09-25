# ICertServerPolicy::EnumerateExtensionsClose

## Description

The **EnumerateExtensionsClose** method frees the resources connected with extension enumeration.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

All policy modules should call the **EnumerateExtensionsClose** method after calling the [EnumerateExtensionsSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensionssetup) and
[ICertServerPolicy::EnumerateExtensions](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensions) methods.

#### Examples

```cpp
// Close the enumeration.
// hr is defined as an HRESULT.
hr = pCertServerPolicy->EnumerateExtensionsClose();
if (FAILED(hr))
{
    printf("Failed EnumerateExtensionsClose [%x]\n", hr);
    goto error;
}
```

## See also

[ICertServerExit::EnumerateExtensionsSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateextensionssetup)

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::EnumerateExtensions](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateextensions)