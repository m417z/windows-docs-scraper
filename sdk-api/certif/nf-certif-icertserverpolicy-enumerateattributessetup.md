# ICertServerPolicy::EnumerateAttributesSetup

## Description

The **EnumerateAttributesSetup** method initializes the internal enumeration pointer to the first request [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) associated with the current [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `Flags` [in]

This parameter is reserved and must be set to zero.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The
[SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) method must be called prior to calling this method. The call to **SetContext** specifies which request to use as the current context.

To retrieve the attribute, call the [EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributes) method. The call to **EnumerateAttributes** retrieves the first attribute and moves the index to the next attribute if one exists.

#### Examples

```cpp
// Set the context. The value nContext (long) would be the same
// as the context parameter in ICertPolicy::VerifyRequest.
// hr is defined as an HRESULT.
// pCertServerPolicy has been used to call SetContext previously.
hr = pCertServerPolicy->SetContext(nContext);
if (FAILED(hr))
{
    printf("Failed SetContext [%x]\n", hr);
    goto error;
}

// Setup the enumeration.
hr = pCertServerPolicy->EnumerateAttributesSetup(0);
if (FAILED(hr))
{
    printf("Failed EnumerateAttributesSetup [%x]\n", hr);
    goto error;
}
```

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributes)

[ICertServerPolicy::EnumerateAttributesClose](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-enumerateattributesclose)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)