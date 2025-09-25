# ICertAdmin2::GetCAProperty

## Description

The **GetCAProperty** method retrieves a property value for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **GetCAProperty** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `PropId` [in]

Specifies one of the following property identifiers.

| Value | Meaning |
| --- | --- |
| **CR_PROP_ADVANCEDSERVER** | Data type of the property: Long<br><br>Specifies whether the CA is running Advanced Server. |
| **CR_PROP_BASECRL** | Data type of the property: Binary, indexed<br><br>The CA's full, or base, [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). |
| **CR_PROP_BASECRLPUBLISHSTATUS** | Data type of the property: Long, indexed<br><br>The base CRL publish status. For more details, see Remarks. |
| **CR_PROP_CABACKWARDCROSSCERT** | Data type of the property: Binary, indexed<br><br>The backward cross certificate. A backward cross certificate is the certificate issued upon renewal from the CA to itself signed with CA's new key. The backward cross certificate has the authority key identifier of the new CA certificate and the subject key identifier of the old CA certificate.<br><br> Applies to root CAs only. |
| **CR_PROP_CABACKWARDCROSSCERTSTATE** | Data type of the property: Long, indexed<br><br>Whether the backward cross certificate is valid. Valid for root CAs only. |
| **CR_PROP_CACERTSTATE** | Data type of the property: Long<br><br>State of the CA certificate. The values can be:<br><br>* CA_DISP_REVOKED<br>* CA_DISP_VALID<br>* CA_DISP_INVALID |
| **CR_PROP_CACERTSTATUSCODE** | Data type of the property: Long, indexed<br><br>Status of the CA certificate, as an **HRESULT**. |
| **CR_PROP_CACERTVERSION** | Data type of the property: Long, indexed<br><br>Version of the CA certificate, as a DWORD. The high-order word is the key index, and the low-order word is the CA certificate index. |
| **CR_PROP_CAFORWARDCROSSCERT** | Data type of the property: Binary, indexed<br><br>The forward cross certificate. A forward cross certificate is a certificate issued upon renewal from the CA to itself signed with CA's previous key. The forward cross certificate has the authority key identifier of the previous CA certificate and the subject key identifier of the new CA certificate.<br><br> Applies to root CAs only. |
| **CR_PROP_CAFORWARDCROSSCERTSTATE** | Data type of the property: Long, indexed<br><br>Whether the forward cross certificate is valid. Valid for root CAs only. |
| **CR_PROP_CANAME** | Data type of the property: String<br><br>Name of the CA. |
| **CR_PROP_CASIGCERT** | Data type of the property: Binary, indexed<br><br>CA signing certificate. |
| **CR_PROP_CASIGCERTCHAIN** | Data type of the property: Binary, indexed<br><br>CA signing certificate chain. |
| **CR_PROP_CASIGCERTCOUNT** | Data type of the property: Long<br><br>Number of signing certificates for the CA. |
| **CR_PROP_CASIGCERTCRLCHAIN** | Data type of the property: Binary, indexed<br><br>The CA's signing certificate CRL chain. |
| **CR_PROP_CATYPE** | Data type of the property: Long<br><br>Type of CA. This can be one of the following values (defined in Certsrv.h):<br><br>* ENUM_ENTERPRISE_ROOTCA<br>* ENUM_ENTERPRISE_SUBCA<br>* ENUM_STANDALONE_ROOTCA<br>* ENUM_STANDALONE_SUBCA |
| **CR_PROP_CAXCHGCERT** | Data type of the property: Binary, indexed<br><br>CA exchange certificate. |
| **CR_PROP_CAXCHGCERTCHAIN** | Data type of the property: Binary, indexed<br><br>CA exchange certificate chain. |
| **CR_PROP_CAXCHGCERTCOUNT** | Data type of the property: Long<br><br>Number of exchange certificates for the CA. |
| **CR_PROP_CAXCHGCERTCRLCHAIN** | Data type of the property: Binary, indexed<br><br>The CA's exchange certificate CRL chain. |
| **CR_PROP_CERTAIAURLS** | Data type of the property: String, indexed<br><br>Specifies Authority Information Access URLs as the type of URL requested by a client.<br><br>**Windows Server 2003:** This flag is not supported. |
| **CR_PROP_CERTCDPURLS** | Data type of the property: String, indexed<br><br>Specifies CRL Distribution Point URLs as the type of URL requested by a client.<br><br>**Windows Server 2003:** This flag is not supported. |
| **CR_PROP_CRLSTATE** | Data type of the property: Long<br><br>State of the CA's CRL. The values can be:<br><br>* CA_DISP_REVOKED<br>* CA_DISP_VALID<br>* CA_DISP_INVALID<br>* CA_DISP_ERROR |
| **CR_PROP_DELTACRL** | Data type of the property: Binary, indexed<br><br>The CA's delta CRL. |
| **CR_PROP_DELTACRLPUBLISHSTATUS** | Data type of the property: Long, indexed<br><br>The delta CRL publish status. For more details, see Remarks. |
| **CR_PROP_DNSNAME** | Data type of the property: String<br><br>The CA's DNS Name. |
| **CR_PROP_EXITCOUNT** | Data type of the property: Long<br><br>Number of exit modules in use by the CA. |
| **CR_PROP_EXITDESCRIPTION** | Data type of the property: String<br><br>Description for the exit module. |
| **CR_PROP_FILEVERSION** | Data type of the property: String<br><br>The Certificate Services file version. |
| **CR_PROP_KRACERT** | Data type of the property: Binary, indexed<br><br>The CA's key recovery agent (KRA) certificate. |
| **CR_PROP_KRACERTCOUNT** | Data type of the property: Long<br><br>Number of KRA certificates for the CA. |
| **CR_PROP_KRACERTSTATE** | Data type of the property: Long, indexed<br><br>The KRA's certificate state. The return value is one of the following:<br><br>* KRA_DISP_EXPIRED<br>* KRA_DISP_NOTFOUND<br>* KRA_DISP_REVOKED<br>* KRA_DISP_VALID<br>* KRA_DISP_UNTRUSTED<br>* KRA_DISP_NOTLOADED<br>* KRA_DISP_INVALID |
| **CR_PROP_KRACERTUSEDCOUNT** | Data type of the property: Long<br><br>Number of KRA certificates used by the CA. |
| **CR_PROP_PARENTCA** | Data type of the property: String<br><br>The name of the CA's parent CA. |
| **CR_PROP_POLICYDESCRIPTION** | Data type of the property: String<br><br>The description for the policy module. |
| **CR_PROP_PRODUCTVERSION** | Data type of the property: String<br><br>The product version in which the file shipped. |
| **CR_PROP_ROLESEPARATIONENABLED** | Data type of the property: Long<br><br>Value specifying whether role separation is enabled. |
| **CR_PROP_SANITIZEDCANAME** | Data type of the property: String<br><br>The sanitized name of the CA. For a definition of a sanitized CA name, see [ICertConfig2::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). |
| **CR_PROP_SANITIZEDCASHORTNAME** | Data type of the property: String<br><br>The sanitized short name of the CA. For a definition of a sanitized CA short name, see [ICertConfig2::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). |
| **CR_PROP_SHAREDFOLDER** | Data type of the property: String<br><br>The name of the shared folder directory. |
| **CR_PROP_TEMPLATES** | Data type of the property: String<br><br>List of templates supported by the CA. |

### `PropIndex` [in]

If the *PropId* parameter is indexed, the zero-based index to use when retrieving the property value. If *PropId* is not indexed, this value is ignored.

### `PropType` [in]

Specifies the type of the property, indicated in the Meaning column of the *PropId* table. The type can be one of the following types.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time (reserved for future use) |
| **PROPTYPE_BINARY** | Binary data |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string data |

### `Flags` [in]

The following flags can be used to specify the format of the returned property value; these flags have meaning only for binary data (such as certificates, certificate chains or [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)) and is ignored otherwise.

| Value | Meaning |
| --- | --- |
| **CV_OUT_BASE64** | BASE64 without BEGIN/END |
| **CV_OUT_BASE64HEADER** | BASE64 with BEGIN CERTIFICATE and END CERTIFICATE |
| **CV_OUT_BASE64REQUESTHEADER** | BASE64 with BEGIN NEW CERTIFICATE REQUEST and END NEW CERTIFICATE REQUEST |
| **CV_OUT_BASE64X509CRLHEADER** | BASE64 with BEGIN X509 CRL and END X509 CRL |
| **CV_OUT_BINARY** | Binary |
| **CV_OUT_HEX** | Hexadecimal string |
| **CV_OUT_HEXADDR** | Hexadecimal string with address/offset |
| **CV_OUT_HEXASCII** | Hexadecimal string with ASCII |
| **CV_OUT_HEXASCIIADDR** | Hexadecimal string with ASCII and address/offset |

### `pvarPropertyValue` [out]

A pointer to a buffer that receives the requested property value. It is a caller's responsibility to free this resource when done by calling [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear).

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates the method was successful.

### VB

The requested property value.

## Remarks

The following values are returned when the property identifier is CR_PROP_BASECRLPUBLISHSTATUS or CR_PROP_DELTACRLPUBLISHSTATUS. These values can be combined.

| Value | Description |
| --- | --- |
| CPF_BADURL_ERROR | A URL is not valid. |
| CPF_BASE | A base CRL was published. |
| CPF_CASTORE_ERROR | A CA store error prevented publication. |
| CPF_COMPLETE | A complete CRL was published. |
| CPF_DELTA | A delta CRL was published. |
| CPF_FILE_ERROR | A file error prevented publication. |
| CPF_FTP_ERROR | An FTP error prevented publication. |
| CPF_HTTP_ERROR | An HTTP error prevented publication. |
| CPF_LDAP_ERROR | An LDAP error prevented publication. |
| CPF_MANUAL | A CRL was published manually. |
| CPF_SHADOW | An empty delta CRL was published, along with a new BASE CRL. |
| CPF_SIGNATURE_ERROR | A signature error prevented publication. |

For an example of retrieving a CRL, see [Retrieving a Certificate Revocation List](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-a-certificate-revocation-list).

#### Examples

The following example shows retrieving the signature certificate of the CA. The example assumes the [ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) interface pointer is valid.

```cpp
BSTR bstrCA = NULL;
VARIANT var1;
HRESULT hr;

bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
if (NULL == bstrCA)
{
    printf("Failed to allocate memory for bstrCA\n");
    exit(1);
}

VariantInit(&var1);
// Retrieve the CA signature certificate at index 0.
hr = pAdmin2->GetCAProperty(bstrCA,
                                CR_PROP_CASIGCERT,
                                0,
                                PROPTYPE_BINARY,
                                CV_OUT_BASE64HEADER,
                                &var1);
if (FAILED(hr))
{
    printf("Failed GetCAProperty\n");
    SysFreeString(bstrCA);
    exit(1);  // Or other error action.
}

// Use the property as needed.
// ...

// Clear the variant when finished.
VariantClear(&var1);
SysFreeString(bstrCA);
```