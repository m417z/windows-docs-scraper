# ICertServerExit::GetCertificateExtension

## Description

The **GetCertificateExtension** method gets a specified certificate extension.

Note that certificate extensions are distinct from certificate properties. Properties are generic data attached to the request object. Some of these properties are encoded into the certificate (example: *BeginDate*), while others are just used to mark requests in the queue and log. Extensions that are not disabled are encoded into the certificate. Extensions are always marked with an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) and always have a critical/noncritical flag.

## Parameters

### `strExtensionName` [in]

A string that contains the name of the extension.

### `Type` [in]

Specifies the type of the extension. The type can be one of the following types.

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

If the method succeeds, the method returns S_OK, and **pvarValue* is set to the **VARIANT** that contains the extension value.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the requested extension value.

## Remarks

You must call
[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext) prior to using this method.

#### Examples

```cpp
VARIANT  varExt;
HRESULT  hr;

VariantInit(&varExt);
// Get the Extension value
// bstrExtName is BSTR assigned by EnumerateExtensions.
// pCertServerExit has been used to call SetContext previously.
hr = pCertServerExit->GetCertificateExtension(bstrExtName,
                                              PROPTYPE_BINARY,
                                              &varExt);

if (FAILED(hr))
{
    printf("Failed GetCertificateExtension [%x]\n", hr);
    goto error;
}
// Successful call; Use the value in varExt as needed.
// ...

// When done, clear the Variant
VariantClear(&varExt);
```

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::GetCertificateExtensionFlags](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-getcertificateextensionflags)

[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext)