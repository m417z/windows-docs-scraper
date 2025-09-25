# ICertEncodeCRLDistInfo::Reset

## Description

The **Reset** method resets a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution information array to a specified number of distribution point structures.

 The values of all the elements in the array of structures are set to zero.

## Parameters

### `DistPointCount` [in]

Specifies the number of CRL distribution points in the CRL distribution information array.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::GetDistPointCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-getdistpointcount)