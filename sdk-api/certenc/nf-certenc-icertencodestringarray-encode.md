# ICertEncodeStringArray::Encode

## Description

The **Encode** method returns an ASN.1-encoded string of the string array stored in this object.

Use the [Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-decode) method to decode the encoded string into an **CertEncodeStringArray** object.

 Before using this method, you must call the [Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-reset) to size the array and the
[SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-setvalue) method to set each string in the array.

## Parameters

### `pstrBinary` [out]

A pointer to a **BSTR** that will contain the encoded string array. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the ASN.1-encoded string array.

## See also

[ICertEncodeStringArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodestringarray)

[ICertEncodeStringArray::Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-decode)

[ICertEncodeStringArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-reset)

[ICertEncodeStringArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-setvalue)