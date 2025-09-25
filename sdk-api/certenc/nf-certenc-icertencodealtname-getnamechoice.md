# ICertEncodeAltName::GetNameChoice

## Description

The **GetNameChoice** method returns the name choice at a specified index of an alternate name array.

## Parameters

### `NameIndex` [in]

Specifies the index of the alternate name entry. The first entry is at index zero.

### `pNameChoice` [out]

A pointer to a **LONG** that receives the name choice specifier.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pNameChoice* parameter points to a value that indicates the type of the alternate name. This is one of the following values.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the name choice at the specified index. The name choice indicates the type of the alternate name so that it can be used correctly. It must be one of the following values.

| Return code | Description |
| --- | --- |
| **CERT_ALT_NAME_DIRECTORY_NAME** | The name is a directory name. |
| **CERT_ALT_NAME_DNS_NAME** | The name is an IA5 string that contains a DNS (Domain Name System) name in the format *Host***.***Entity***.***Domain*. |
| **CERT_ALT_NAME_IP_ADDRESS** | The name is an octet string that represents an Internet protocol address. |
| **CERT_ALT_NAME_REGISTERED_ID** | The name is a registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). |
| **CERT_ALT_NAME_RFC822_NAME** | The name is an email address. |
| **CERT_ALT_NAME_URL** | The name is an IA5 string that contains a URL in the format *Service***://***HostName***/***Path*. |
| **CERT_ALT_NAME_OTHER_NAME** | The name consists of an OID and a binary [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). |

## See also

[ICertEncodeAltName](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodealtname)

[ICertEncodeAltName::GetName](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-getname)

[ICertEncodeAltName::SetNameEntry](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-setnameentry)