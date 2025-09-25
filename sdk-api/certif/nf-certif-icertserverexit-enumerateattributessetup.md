# ICertServerExit::EnumerateAttributesSetup

## Description

The **EnumerateAttributesSetup** method initializes the internal enumeration pointer to the first request attribute associated with the current context.

## Parameters

### `Flags` [in]

This parameter is reserved and must be set to zero.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call
[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext) prior to using this method.

#### Examples

```cpp
// Set up the enumeration.
hr = pCertServerExit->EnumerateAttributesSetup(0);
if (FAILED(hr))
{
    printf("Failed EnumerateAttributesSetup [%x]\n", hr);
    goto error;
}
```

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::EnumerateAttributes](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-enumerateattributes)