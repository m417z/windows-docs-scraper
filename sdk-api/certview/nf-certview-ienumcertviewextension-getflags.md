# IEnumCERTVIEWEXTENSION::GetFlags

## Description

The **GetFlags** method retrieves the policy and origin flags of the current extension in the extension-enumeration sequence.

 Both the policy and origin flags are returned in one variable, and bitmasks are provided to retrieve the individual values.

## Parameters

### `pFlags` [out]

A pointer to a **LONG** type that contains the policy and origin flags of the extension. This method fails if the *pFlags* parameter is set to **NULL**.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value represents the policy and origin values of the extension.

## Remarks

This method is used to retrieve the policy and origin flags of the extension currently referenced by the
extension-enumeration sequence.

Policy flags provide information about the certificate extension and can be set by the policy module.

Origin flags indicate the module that set the certificate extension and are set only by the server engine.

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
| EXTENSION_ORIGIN_ADMIN | The administrator set the extension. |
| EXTENSION_ORIGIN_SERVER | The server engine set the extension. |
| EXTENSION_ORIGIN_RENEWALCERT | The extension was extracted from the certificate stored in the szOID_RENEWAL_CERTIFICATE (1.3.6.1.4.1.311.13.1) attribute of a PKCS #10 renewal request. |
| EXTENSION_ORIGIN_IMPORTEDCERT | The extension was extracted from an imported certificate (the certificate was passed to [ICertAdmin::ImportCertificate](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin-importcertificate)). |
| EXTENSION_ORIGIN_PKCS7 | The extension was extracted from an array of extensions stored in the szOID_CERT_EXTENSIONS (1.3.6.1.4.1.311.2.1.14) or szOID_RSA_certExtensions (1.2.840.113549.1.9.14) attribute of a PKCS #7 request. |

Predefined masks are provided for ease of use in determining which flags are set in the return value. The following masks are provided.

| Mask value | Explanation |
| --- | --- |
| EXTENSION_POLICY_MASK | This value (0x0000FFFF) is used to examine policy flags. |
| EXTENSION_ORIGIN_MASK | This value (0x000F0000) is used to examine origin flags. |

If the extension-enumeration sequence is not referencing a valid extension, **GetFlags** will fail. Use one of the following methods to navigate through the enumeration:

* [IEnumCERTVIEWEXTENSION::Reset](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-reset): Moves to the next extension in the enumeration sequence.
* [IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next): Moves to the next extension in the enumeration sequence.
* [IEnumCERTVIEWEXTENSION::Skip](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-skip): Skips a specified number of extensions.

#### Examples

```cpp
HRESULT  hr;
LONG     ExtFlags;

// pEnumExt is previously instantiated IEnumCERTVIEWEXTENSION object
hr = pEnumExt->GetFlags(&ExtFlags);
if (S_OK != hr)
    printf("Failed GetFlags - %x\n", hr);
else
{
    LONG ExtPol, ExtOrig;

    ExtPol = ExtFlags & EXTENSION_POLICY_MASK;
    if (ExtPol & EXTENSION_CRITICAL_FLAG)
        printf("The extension is critical\n");
    if (ExtPol & EXTENSION_DISABLE_FLAG )
        printf("The extension is disabled\n");

    ExtOrig = ExtFlags & EXTENSION_ORIGIN_MASK;
    switch (ExtOrig)
    {
        case EXTENSION_ORIGIN_REQUEST:
            printf("Extension originated by PKCS #10 Request\n");
            break;
        case EXTENSION_ORIGIN_POLICY:
            printf("Extension originated by Policy\n");
            break;
        case EXTENSION_ORIGIN_ADMIN:
            printf("Extension originated by Admin\n");
            break;
        case EXTENSION_ORIGIN_SERVER:
            printf("Extension originated by Server\n");
            break;
        case EXTENSION_ORIGIN_RENEWALCERT:
            printf("Extension originated by Renewal Request\n");
            break;
        case EXTENSION_ORIGIN_IMPORTEDCERT:
            printf("Extension originated by an imported "
                "certificate\n");
            break;
        case EXTENSION_ORIGIN_PKCS7:
            printf("Extension originated by PKCS #7 Request\n");
            break;
        default:
            printf("Unknown extension origin\n");
            break;
    }
}
```

## See also

[IEnumCERTVIEWEXTENSION](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewextension)

[IEnumCERTVIEWEXTENSION::GetName](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getname)

[IEnumCERTVIEWEXTENSION::GetValue](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-getvalue)

[IEnumCERTVIEWEXTENSION::Next](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-ienumcertviewextension-next)