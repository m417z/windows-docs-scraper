# ICertServerPolicy::EnumerateAttributesClose

## Description

The **EnumerateAttributesClose** method frees the resources connected with attribute enumeration.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

All policy modules should call the **EnumerateAttributesClose** method after calling the [EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributessetup) and
[EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributes) methods.

#### Examples

```cpp
// Close the enumeration.
// hr is defined as an HRESULT.
hr = pCertServerPolicy->EnumerateAttributesClose();
if (FAILED(hr))
{
    printf("Failed EnumerateAttributesClose [%x]\n", hr);
    goto error;
}
```

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributes)

[ICertServerPolicy::EnumerateAttributesSetup](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributessetup)