# ICertRequest2::GetCAProperty

## Description

The **GetCAProperty** method retrieves a property value for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). This method's functionality is identical to [ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty). For information about this method, see **ICertAdmin2::GetCAProperty**.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

### `PropId` [in]

Specifies the property identifier. For information about this parameter, see the table in
[ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty).

### `PropIndex` [in]

If *PropId* is indexed, the zero-based index to use when retrieving the property value. If *PropId* is not indexed, this value is ignored.

### `PropType` [in]

Specifies the type of the property, which corresponds to the Type column in the *PropId* table. The type can be one of the following types.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time (reserved for future use) |
| **PROPTYPE_BINARY** | Binary data |
| **PROPTYPE_STRING** | [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string data |

### `Flags` [in]

The following flags can be used to specify the format of the returned property value; these flags have meaning only for binary data (such as certificates, certificate chains, or [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)) and is ignored otherwise.

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

### `pvarPropertyValue` [out, retval]

A pointer to a **VARIANT** that receives the requested property value.

When you have finished using the **VARIANT**, free it by calling the [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Variant** that receives the requested property value.

## See also

**CCertRequest**

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)