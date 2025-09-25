# ICertEncodeAltName::Encode

## Description

The **Encode** method returns an ASN.1-encoded string of the alternate name array stored in this object. The names in the object are not encoded.

Use the [Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-decode) method to decode the encoded string into an **CertEncodeAltName** object.

Before using this method, you must call both the
[Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-reset) method to size the array and the
[SetNameEntry](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-setnameentry) method to set each array element.

## Parameters

### `pstrBinary` [out]

A pointer to a **BSTR** that receives the ASN.1-encoded alternate name extension. When done, call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free *pbstrBinary*.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the ASN.1-encoded alternate name array.

## See also

[ICertEncodeAltName](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodealtname)

[ICertEncodeAltName::Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-decode)

[ICertEncodeAltName::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-reset)

[ICertEncodeAltName::SetNameEntry](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-setnameentry)