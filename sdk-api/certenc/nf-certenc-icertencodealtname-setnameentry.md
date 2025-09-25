# ICertEncodeAltName::SetNameEntry

## Description

The **SetNameEntry** method sets a name at a specified index of the alternate name array.

Before using this method, you must call
[ICertEncodeAltName::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-reset) so that the object knows how many elements are in the array.

## Parameters

### `NameIndex` [in]

Zero-based index that specifies the index of the alternate name entry to set.

If the *NameChoice* parameter is CERT_ALT_NAME_OTHER_NAME, OR (|) the index value with EAN_NAMEOBJECTID (defined as 0x80000000) to set the OID. Otherwise, the binary value is set.

### `NameChoice` [in]

Specifies the name choice. The name choice indicates the type of the alternate name so that it can be used correctly. It must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_ALT_NAME_DIRECTORY_NAME** | The name is a directory name. |
| **CERT_ALT_NAME_DNS_NAME** | The name is an IA5 string specifying a DNS (Domain Name System) name in the format host.entity.domain. |
| **CERT_ALT_NAME_IP_ADDRESS** | The name is an octet string that represents an Internet Protocol address. |
| **CERT_ALT_NAME_REGISTERED_ID** | The name is a registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). |
| **CERT_ALT_NAME_RFC822_NAME** | The name is an email address. |
| **CERT_ALT_NAME_URL** | The name is an IA5 string that contains a URL in the format *Service***://***HostName***/***Path*. |
| **CERT_ALT_NAME_OTHER_NAME** | The name consists of an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and a binary [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). |

### `strName` [in]

Specifies the alternate name.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeAltName](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodealtname)