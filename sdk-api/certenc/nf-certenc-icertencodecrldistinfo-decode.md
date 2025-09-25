# ICertEncodeCRLDistInfo::Decode

## Description

The **Decode** method decodes an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) distribution information extension and stores the resulting array in the COM object.

## Parameters

### `strBinary` [in]

An ASN.1-encoded CRL distribution information extension.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method places the decoded contents of *strBinary* into the object's array of CRL distribution information points. If the object's array already contains data, this existing content will be freed, and the array will be loaded with the decoded values.

#### Examples

For an example that uses the **Decode** method, see the [ICertEncodeCRLDistInfo::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-encode) method.

## See also

[ICertEncodeCRLDistInfo](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodecrldistinfo)

[ICertEncodeCRLDistInfo::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodecrldistinfo-encode)