# ICertEncodeCRLDistInfo::GetNameCount

## Description

The **GetNameCount** method returns the number of names in a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution point.

## Parameters

### `DistPointIndex` [in]

Specifies the index of the distribution point for which to get the name count.

### `pNameCount` [out]

A pointer to a **Long** that will represent the number of name values contained in the CRL distribution point.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the number of names in the CRL distribution point.

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::GetDistPointCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getdistpointcount)

[ICertEncodeCRLDistInfo::GetName](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getname)

[ICertEncodeCRLDistInfo::SetNameCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-setnamecount)