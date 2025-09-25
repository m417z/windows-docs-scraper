# ICertAdmin::SetCertificateExtension

## Description

The **SetCertificateExtension** method adds a new extension to the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) issued in response to a [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first defined by the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

For this method to succeed, the certificate request must be pending.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) server in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **SetCertificateExtension** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `RequestId` [in]

Specifies the ID of the certificate request.

### `strExtensionName` [in]

Specifies the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for the extension to set. The string must be 31 or fewer non-NULL characters in length.

### `Type` [in]

Specifies the type of extension being set. The *Type* parameter must agree with the data type of the *pvarValue* parameter. This data type is set in the **vt** field of the **VARIANT** structure.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PROPTYPE_LONG** | Signed long data |
| **PROPTYPE_DATE** | Date/time |
| **PROPTYPE_BINARY** | The extension value is set as is and is assumed to be ASN.1 encoded if necessary. |
| **PROPTYPE_STRING** | The extension value will be ASN.1 encoded as an IA5 string before it is placed in the new certificate.<br><br>**Note** You should use **PROPTYPE_STRING** for an extension value that consists of a single URL only if you want the URL to be automatically encoded as an IA5 string. Otherwise, encode the URL as an IA5 string yourself and pass the encoded value as **PROPTYPE_BINARY**. |

### `Flags` [in]

Specifies the flags for the extension being set. If no flag is to be set, use a value of zero. You can combine these flags with a bitwise-**OR** operation and also with policy private extension flags (the high 8 bits of the EXTENSION_POLICY_MASK field).

**Note** When the *Flags* parameter is set to EXTENSION_DISABLE_FLAG, the extension will be disabled in the server log and will not be added to the certificate.

| Value | Meaning |
| --- | --- |
| **EXTENSION_CRITICAL_FLAG** | This is a critical extension. |
| **EXTENSION_DISABLE_FLAG** | The extension will not be used. |

### `pvarValue` [in]

Specifies the value associated with the extension.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)