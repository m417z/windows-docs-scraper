# ICertEncodeCRLDistInfo::GetNameChoice

## Description

The **GetNameChoice** method returns the name choice at a specified index of a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution information point.

## Parameters

### `DistPointIndex` [in]

Specifies the index of the distribution point for which to get a name choice. The first value is at index zero.

### `NameIndex` [in]

Specifies the index of the name choice entry to get. The first value is at index zero.

### `pNameChoice` [out]

A pointer to a **Long** that represents the name choice.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the name choice at the specified index. The name choice indicates the type of the name so that it can be used correctly. The name choice must be one of the following values.

| Return code | Description |
| --- | --- |
| **CERT_ALT_NAME_RFC822_NAME** | The name is an email address. |
| **CERT_ALT_NAME_DNS_NAME** | The name is an IA5 string that contains a DNS (Domain Name System) name in the format *Host***.***Entity***.***Domain*. |
| **CERT_ALT_NAME_URL** | The name is an IA5 string that contains a URL in the format *Service***://***HostName***/***Path*. |
| **CERT_ALT_NAME_REGISTERED_ID** | The name is a registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). |

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::SetNameEntry](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-setnameentry)