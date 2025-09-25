# ICertEncodeCRLDistInfo::SetNameEntry

## Description

The **SetNameEntry** method sets a name at a specified index of a distribution point in a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution information array.

## Parameters

### `DistPointIndex` [in]

Specifies the index of the CRL distribution point for which to set the name. The first value is at index zero.

### `NameIndex` [in]

Specifies the index of the name entry to set. The first value is at index zero.

### `NameChoice` [in]

Specifies the name choice of the name being set. The name choice indicates the type of the name so that it can be used correctly. The name choice must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_ALT_NAME_RFC822_NAME** | The name is an email address. |
| **CERT_ALT_NAME_DNS_NAME** | The name is an IA5 string specifying a DNS (Domain Name System) name in the format host.entity.domain. |
| **CERT_ALT_NAME_URL** | The name is an IA5 string specifying a URL in the format *Service***://***HostName***/***Path*. |
| **CERT_ALT_NAME_REGISTERED_ID** | The name is a registered [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). |

### `strName` [in]

Specifies the name.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::GetName](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getname)

[ICertEncodeCRLDistInfo::GetNameChoice](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getnamechoice)

[ICertEncodeCRLDistInfo::SetNameCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-setnamecount)