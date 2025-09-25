# ICertServerPolicy::GetCertificateExtensionFlags

## Description

The **GetCertificateExtensionFlags** method retrieves the flags associated with the extension acquired by the most recent call to
[GetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextension).

## Parameters

### `pExtFlags` [out]

A pointer to a **LONG** variable that contains the extension flags.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pExtFlags* parameter contains the flags from the extension acquired by the most recent call to [GetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextension).

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the flags from the extension acquired by the most recent call to [GetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextension).

## Remarks

The [SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) and [GetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextension) methods must be called before **GetCertificateExtensionFlags**. The **SetContext** method specifies which request is used as the current context, and the **GetCertificateExtension** method retrieves the extensions for the request.

Extensions can contain policy and origin flags. Policy flags provide information about the certificate extension. Policy flags can be set by the policy module. Origin flags indicate the module that set the certificate extension. Origin flags are only set by the server engine.

One or more policy flags can be returned from an extension. The following are predefined policy flags.

| Policy flag value | Explanation |
| --- | --- |
| EXTENSION_CRITICAL_FLAG | This is a critical extension. |
| EXTENSION_DISABLE_FLAG | Extension will not be used. |

One of the following origin flags can also be returned.

| Origin flag value | Explanation |
| --- | --- |
| EXTENSION_ORIGIN_REQUEST | The extension was extracted from an array of extensions stored in the szOID_CERT_EXTENSIONS (1.3.6.1.4.1.311.2.1.14) or szOID_RSA_certExtensions (1.2.840.113549.1.9.14) attribute of a PKCS #10 request. |
| EXTENSION_ORIGIN_POLICY | The policy module set the extension. |
| EXTENSION_ORIGIN_ADMIN | The administrator set the extension. For more information, see [ICertAdmin::SetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-setcertificateextension). |
| EXTENSION_ORIGIN_SERVER | The server engine set the extension. |
| EXTENSION_ORIGIN_RENEWALCERT | The extension was extracted from the certificate stored in the szOID_RENEWAL_CERTIFICATE (1.3.6.1.4.1.311.13.1) attribute of a PKCS #10 renewal request. |
| EXTENSION_ORIGIN_IMPORTEDCERT | The extension was extracted from an imported certificate (the certificate was passed to [ICertAdmin::ImportCertificate](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-importcertificate)). |
| EXTENSION_ORIGIN_PKCS7 | The extension was extracted from an array of extensions stored in the szOID_CERT_EXTENSIONS (1.3.6.1.4.1.311.2.1.14) or szOID_RSA_certExtensions (1.2.840.113549.1.9.14) attribute of a PKCS #7 request. |

Predefined masks are provided for ease of use in determining which flags are set in the return value. The following masks are provided.

| Mask value | Explanation |
| --- | --- |
| EXTENSION_POLICY_MASK | This value (0x0000FFFF) is used to examine policy flags. |
| EXTENSION_ORIGIN_MASK | This value (0x000F0000) is used to examine origin flags. |

It is safe to use the high 8 bits of EXTENSION_POLICY_MASK for custom data. These bits will be saved persistently in the database, but will not be written to the certificate extensions.

#### Examples

```cpp
HRESULT  hr;
LONG     ExtFlags;
// pCertServerPolicy has been used to call SetContext previously.
hr = pCertServerPolicy->GetCertificateExtensionFlags( &ExtFlags);

// More than one policy flag might be set.
LONG ExtPolicyFlags = ExtFlags & EXTENSION_POLICY_MASK;

if (ExtPolicyFlags & EXTENSION_CRITICAL_FLAG)
{
    // Do something.
}

if (ExtPolicyFlags & EXTENSION_DISABLE_FLAG)
{
    // Do something.
}

// only one origin flag can be set
switch (ExtFlags & EXTENSION_ORIGIN_MASK)
{
    case EXTENSION_ORIGIN_REQUEST:
        // Extension was set in certificate request.
        break;
    case EXTENSION_ORIGIN_POLICY:
        // Extension was set by policy module.
        break;
    case EXTENSION_ORIGIN_ADMIN:
        // Extension was set by administrator.
        break;
    case EXTENSION_ORIGIN_SERVER:
        // Extension was set by server engine.
        break;
    default:
        break;
}
```

## See also

[ICertAdmin::SetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-setcertificateextension)

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::GetCertificateExtension](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-getcertificateextension)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)

[IEnumCERTVIEWEXTENSION::GetFlags](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getflags)