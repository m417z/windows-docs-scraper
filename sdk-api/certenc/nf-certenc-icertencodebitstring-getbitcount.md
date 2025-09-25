# ICertEncodeBitString::GetBitCount

## Description

The **GetBitCount** method returns the number of bits in a bit string that belongs to the
[CertEncodeBitString](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodebitstring) object and has been initialized by an earlier call to
[ICertEncodeBitString::Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodebitstring-decode).

## Parameters

### `pBitCount` [out]

A pointer to a **Long** that will receive the number of bits in the bit string.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the number of bits in the bit string.

## See also

[ICertEncodeBitString](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodebitstring)