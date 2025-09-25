# ICertEncodeCRLDistInfo::GetDistPointCount

## Description

The **GetDistPointCount** method returns the number of [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution points in a CRL distribution information array.

## Parameters

### `pDistPointCount` [out]

A pointer to a **LONG** that will represent the number of CRL distribution points in the array.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the number of CRL distribution points in the array.

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::GetNameCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getnamecount)

[ICertEncodeCRLDistInfo::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-reset)