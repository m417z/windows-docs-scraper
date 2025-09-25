# ICertServerPolicy::GetCertificateExtension

## Description

The **GetCertificateExtension** method retrieves a specific certificate extension.

## Parameters

### `strExtensionName` [in]

A string that contains the name of the extension.

### `Type` [in]

Specifies the type of the extension. The type can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time |
| **PROPTYPE_BINARY** | The extension value is retrieved as is and is ASN.1 encoded if necessary. |
| **PROPTYPE_STRING** | The extension value is ASN.1 encoded as an IA5 string. |

### `pvarValue` [out]

A pointer to a **VARIANT** that receives the requested extension value.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pvarValue* parameter contains the extension value.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the requested extension value.

## Remarks

The
[SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) method must be called prior to calling this method. The call to **SetContext** specifies which request is used as the current context.

Certificate extensions are distinct from certificate properties. Properties are generic data that is attached to the request. Some of these properties are encoded into the certificate (for example: *BeginDate*), while others are just used to mark requests in the queue and log. Extensions that are not disabled are encoded into the certificate. Extensions are always marked with an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly), and always have a critical/noncritical flag.

#### Examples

```cpp
VARIANT    varExt;
HRESULT    hr;

VariantInit(&varExt);
// Get the Extension value.
// bstrExtName is BSTR assigned by EnumerateExtensions.
// pCertServerPolicy has been used to call SetContext previously.
hr = pCertServerPolicy->GetCertificateExtension(bstrExtName,
                                                PROPTYPE_BINARY,
                                                &varExt);

if (FAILED(hr))
{
    printf("Failed GetCertificateExtension [%x]\n", hr);
    goto error;
}
// Successful call; use the value in varExt as needed.
// ...

// When done, clear the Variant
VariantClear(&varExt);
```

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::GetCertificateExtensionFlags](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextensionflags)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)