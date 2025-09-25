# ICertServerExit::GetCertificateProperty

## Description

The **GetCertificateProperty** method returns a named property from a certificate.

## Parameters

### `strPropertyName` [in]

Specifies the named property to retrieve. There is a stock set of certificate properties, referred to as the *name properties*, that are always valid and can be retrieved by calling this method. For information about these properties, see
[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties). Other properties that can be retrieved include the certificate properties.

The following properties are unique to certificates and can be read by **GetCertificateProperty**.

| Value | Meaning |
| --- | --- |
| **NotBefore**<br><br>Date/Time | Certificate start validity date |
| **NotAfter**<br><br>Date/Time | Certificate expiration date |
| **PublicKeyAlgorithm**<br><br>String | Subject key algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) |
| **RawCertificate**<br><br>Binary | Raw certificate bytes |
| **RawPublicKey**<br><br>Binary | Subject key |
| **RawPublicKeyAlgorithmParameters**<br><br>Binary | Subject key algorithm parameters |
| **RequestID**<br><br>Signed Long | Internal request ID |
| **SerialNumber**<br><br>String | Certificate serial number |

The certificate's DistinguishedName, RawName, and SerialNumber properties are accessible by **GetCertificateProperty** only after the policy module has finished processing the request and the certificate is issued.

The following properties apply to the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The context must be zero to read any of these properties. The context is set to zero when the [ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit) object is initially created. It can also be set to zero by invoking the [SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext) method.

| Value | Meaning |
| --- | --- |
| **CAType**<br><br>Long | Type of [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This can be one of the following values (defined in Certsrv.h): <br><br>ENUM_ENTERPRISE_ROOTCA<br><br>ENUM_ENTERPRISE_SUBCA<br><br>ENUM_STANDALONE_ROOTCA<br><br>ENUM_STANDALONE_SUBCA |
| **CertCount**<br><br>Long | Number of CA certificates. This value will be one plus the number of times that the CA has been renewed. For information about renewal, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CertState**<br><br>Long | CA certificate [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This can be one of the following values:<br><br>CA_DISP_ERROR: The CA certificate was never issued.<br><br>CA_DISP_REVOKED: The CA certificate has been revoked.<br><br>CA_DISP_VALID: The CA certificate is still valid.<br><br>CA_DISP_INVALID: The CA certificate has expired.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CertSuffix**<br><br>String | Suffix for the CA certificate. The suffix is an empty string for CA certificates with an index of zero; otherwise, the suffix (in the form of "(*nn*)", where *nn* is the certificate index) is applied to all URLs that point to CA certificates stored in files or directory service objects. For non-[LDAP](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) URLs, the suffix typically appears before the ".crt" text. For LDAP URLs, the suffix is typically appended to the first 'CN=' in the full distinguished name.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CRLIndex**<br><br>Long | [Certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) index. Appending a certificate index to this property name allows you to retrieve the CRL index. The CRL index does not necessarily match the certificate index. For more information, see [Certification](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal).<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CRLState**<br><br>Long | CRL [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This can be one of the following values:<br><br>CA_DISP_ERROR: The CRL is managed by another CA certificate.<br><br>CA_DISP_REVOKED: All unexpired CA certificates that use this CA certificate's CRL have been revoked.<br><br>CA_DISP_VALID: The CA certificate is still being used to publish CRLs as needed.<br><br>CA_DISP_INVALID: All CA certificates that use this CA certificate's CRL are expired.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CRLSuffix**<br><br>String | Suffix for the CA CRL. The suffix is an empty string for CRLs with an index of zero; otherwise, the suffix (in the form of "(*nn*)", where *nn* is the CRL index) is applied to all URLs pointing to CRLs stored in files or directory service objects. For non-LDAP URLs, the suffix typically appears before the ".crl" text. For LDAP URLs, the suffix typically is appended to the first 'CN=' in the full distinguished name.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **fUseDS**<br><br>Long | Indicates whether the CA uses a directory service. This can be either of the following values:<br><br>* 0=no<br>* 1=yes |
| **MachineDNSName**<br><br>String | DNS name of server hosting the CA. |
| **ModuleRegistryLocation**<br><br>String | Registry location available for use by the module. |
| **RawCACertificate**<br><br>Binary | CA certificate.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **RawCRL**<br><br>Binary | CA's [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL).<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **RequesterCAAccess**<br><br>Long | Indicates whether the requester is authorized to request the certificate. This can be either of the following values:<br><br>* 0=no<br>* 1=yes<br><br>(The Certification Authority MMC snap-in can be used to control [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) permissions.) |
| **SanitizedCAName**<br><br>String | [Sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the CA. For information about sanitized CA names, see [ICertConfig::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). |
| **SanitizedShortName**<br><br>String | [Sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the CA, shortened and containing a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) value to ensure uniqueness. |

### `PropertyType` [in]

Specifies the property type. The type can be one of the following.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time |
| **PROPTYPE_BINARY** | Binary data |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string data |

### `pvarPropertyValue` [out]

A pointer to a **VARIANT** that will contain the property value. The returned value is encoded as a **BSTR**. Use the [SysStringByteLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysstringbytelen) function to retrieve the length of the **BSTR**. The binary [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) is stored as a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) encoded X.509 certificate.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the requested property value.

## Remarks

You must call
[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext) prior to using this method.

#### Examples

```cpp
BSTR    bstrPropName = NULL;
VARIANT varProp;

VariantInit(&varProp);

// Set the property name to RequestID.
bstrPropName = SysAllocString(L"RequestID");

// Retrieve the certificate property.
// pCertServerExit has been used to call SetContext previously.
hr = pCertServerExit->GetCertificateProperty(bstrPropName,
                                             PROPTYPE_LONG,
                                             &varProp );
if (FAILED(hr))
{
    printf("Failed GetCertificateProperty [%x]\n", hr);
    goto error;
}
else
{
    // Successfully retrieved property; use varProp as needed.
    // ...
}

// Done processing.
if (NULL != bstrPropName)
    SysFreeString(bstrPropName);
VariantClear(&varProp);
```

## See also

[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit)

[ICertServerExit::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-setcontext)

[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties)