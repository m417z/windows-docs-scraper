# ICertEncodeBitString::Encode

## Description

The **Encode** method performs [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding on a given bit string.

## Parameters

### `BitCount` [in]

The number of bits in *strBitString*.

### `strBitString` [in]

The bit string to encode.

### `pstrBinary` [out]

A pointer to a **BSTR** that will contain the encoded bit string. When you have finished using this **BSTR**, call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to free *pbstrBinary*.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the ASN.1-encoded bit string.

## See also

[ICertEncodeBitString](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodebitstring)

[ICertEncodeBitString::Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodebitstring-decode)