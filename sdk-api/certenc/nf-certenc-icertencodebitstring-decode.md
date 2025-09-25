# ICertEncodeBitString::Decode

## Description

The **Decode** method decodes an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded bit string and stores the resulting bit string in this object. You can then call the
[ICertEncodeBitString::GetBitCount](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodebitstring-getbitcount) and
[ICertEncodeBitString::GetBitString](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodebitstring-getbitstring) methods to retrieve the bit string and its size.

## Parameters

### `strBinary` [in]

An ASN.1-encoded bit string.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Use this method to decode an encoded bit string.

#### Examples

For an example that calls the **Decode** method, see the [ICertEncodeBitString::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodebitstring-encode) method.

## See also

[ICertEncodeBitString](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodebitstring)

[ICertEncodeBitString::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodebitstring-encode)