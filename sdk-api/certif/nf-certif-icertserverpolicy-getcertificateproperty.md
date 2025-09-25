# ICertServerPolicy::GetCertificateProperty

## Description

The **GetCertificateProperty** method returns a named property from a certificate.

You must call
[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) prior to using this method.

## Parameters

### `strPropertyName` [in]

Specifies the named property to retrieve. There is a stock set of certificate properties, referred to as the *name properties*, that are always valid and can be retrieved by calling this method. For information about these properties, see
[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties). Other properties beside name properties can also be retrieved.

The certificate's DistinguishedName and RawName properties are accessible by [ICertServerExit::GetCertificateProperty](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverexit-getcertificateproperty) only after the policy module has finished processing the request and the certificate is issued. The issued certificate's DistinguishedName and RawName properties can also be read by an exit module by using **ICertServerExit::GetCertificateProperty**.

There are additional certificate properties that cannot be accessed by **GetCertificateProperty**. These properties are not set until after the policy module returns VR_INSTANT_OK and the certificate is issued. For a complete list of all the properties in an issued certificate, see
**GetCertificateProperty**.

The following properties are unique to certificates and can be read by **GetCertificateProperty**.

| Certificate property | Meaning |
| --- | --- |
| **RequestID**<br><br>Signed long | Internal request ID |
| **NotBefore**<br><br>Date/time | Certificate start validity date |
| **NotAfter**<br><br>Date/time | Certificate expiration date |
| **RawPublicKey**<br><br>Binary | Subject key |
| **PublicKeyAlgorithm**<br><br>String | Subject key algorithm [object ID](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) |
| **RawPublicKeyAlgorithmParameters**<br><br>Binary | Subject key algorithm parameters |
| **GeneralFlags**<br><br>PROPTYPE_LONG | GeneralFlags in the enrollment request. This is a bitwise **OR** of values. The only value of interest should be the flag value of 0x00000400, which tells the CA not to persist the request in the database. If the CA is in databaseless mode (that is, for Windows Server 2008 R2 and later CAs, the CA's database has the **DBFLAGS_ENABLEVOLATILEREQUESTS** flag set), use `certutil -getreg DbFlags` and `certutil -setreg DBFlags` for configuring the CA in databaseless mode.<br><br>**Windows Vista and Windows Storage Server 2003:** This field is not supported. |
| **RequesterNameFromOldCertificate**<br><br>PROPTYPE_STRING | For renewal requests, returns the requester account name (for example, contoso\requester). |

The following properties apply to the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

| CA property | Meaning |
| --- | --- |
| **CAType**<br><br>Long | The type of certification authority. This can be one of the following values (defined in Certsrv.h):<br><br>* ENUM_ENTERPRISE_ROOTCA<br>* ENUM_ENTERPRISE_SUBCA<br>* ENUM_STANDALONE_ROOTCA<br>* ENUM_STANDALONE_SUBCA |
| **CertCount**<br><br>Long | The number of CA certificates. This value will be one plus the number of times that the CA has been renewed. For information about renewal, see [Certification](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CertState**<br><br>Long | The CA certificate [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This can be one of the following values:<br><br>* CA_DISP_ERROR: The CA certificate was never issued.<br>* CA_DISP_REVOKED: The CA certificate has been revoked.<br>* CA_DISP_VALID: The CA certificate is still valid.<br>* CA_DISP_INVALID: The CA certificate has expired.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CertSuffix**<br><br>String | The suffix for the CA certificate. The suffix is an empty string for CA certificates with an index of zero; otherwise, the suffix (in the form of "(*nn*)", where *nn* is the certificate index) is applied to all URLs that point to CA certificates stored in files or directory service objects. For non-[LDAP](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) URLs, the suffix typically appears before the ".crt" text. For LDAP URLs, the suffix is typically appended to the first 'CN=' in the full distinguished name.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CRLIndex**<br><br>Long | The [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) index. Appending a certificate index to this property name allows you to retrieve the CRL index. The CRL index does not necessarily match the certificate index. For more information, see [Certification](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal).<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CRLState**<br><br>Long | The CRL [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This can be one of the following values:<br><br>* CA_DISP_ERROR: The CRL is managed by another CA certificate.<br>* CA_DISP_REVOKED: All unexpired CA certificates using this CA certificate's CRL have been revoked.<br>* CA_DISP_VALID: The CA certificate is still being used to publish CRLs as needed.<br>* CA_DISP_INVALID: All CA certificates using this CA certificate's CRL are expired.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **CRLSuffix**<br><br>String | The suffix for the CA CRL. The suffix is an empty string for CRLs with an index of zero; otherwise, the suffix (in the form of "(*nn*)", where *nn* is the CRL index) is applied to all URLs that point to CRLs stored in files or directory service objects. For non-LDAP URLs, the suffix typically appears before the .crl text. For LDAP URLs, the suffix typically is appended to the first 'CN=' in the full distinguished name.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **fUseDS**<br><br>Long | Indicates whether the CA uses a directory service. This can be either of the following values:<br><br>* 0=no<br>* 1=yes |
| **MachineDNSName**<br><br>String | The DNS name of the server hosting the CA. |
| **ModuleRegistryLocation**<br><br>String | The registry location available for use by the module. |
| **RawCACertificate**<br><br>Binary | The CA certificate.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **RawCRL**<br><br>Binary | The [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) of the CA.<br><br>This property name may be appended with '.#', where # represents a CA certificate index (or, in the case of the CRLSuffix property, a CRL index). For information about certificate and CRL indices, see [Certification Authority Renewal](https://learn.microsoft.com/windows/desktop/SecCrypto/certification-authority-renewal). |
| **RequesterCAAccess**<br><br>Long | Indicates whether the requester is authorized to request the certificate. This can be either of the following values:<br><br>* 0=no<br>* 1=yes<br><br>(The Certification Authority MMC snap-in can be used to control [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) permissions.) |
| **SanitizedCAName**<br><br>String | The [sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the CA. For information about sanitized CA names, see [ICertConfig::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). |
| **SanitizedShortName**<br><br>String | The sanitized name for the CA, which is shortened and which contains a hash value to ensure uniqueness. |

### `PropertyType` [in]

Specifies the property type. The type can be one of the following values.

| Type | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time |
| **PROPTYPE_BINARY** | Binary data |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string data |

### `pvarPropertyValue` [out]

A pointer to **VARIANT** that will contain the property value.

## Return value

 If the method succeeds, the method returns S_OK, and **pvarPropertyValue* is set to the **VARIANT** that contains the requested property value.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)

[Name Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/name-properties)