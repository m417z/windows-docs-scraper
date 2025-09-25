# ICertEncodeLongArray::Encode

## Description

The **Encode** method returns an ASN.1-encoded string of the **LONG** array stored in this object.

Use the [Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-decode) method to decode the encoded string into an **CertEncodeLongArray** object.

Before calling the **Encode** method, you must call the
[Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-reset) method to size the array and the
[SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-setvalue) method to set each **LONG** value in the array.

## Parameters

### `pstrBinary` [out]

A pointer to a **BSTR** that will contain the encoded **LONG** array. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the ASN.1-encoded **LONG** array.

## See also

[ICertEncodeLongArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodelongarray)

[ICertEncodeLongArray::Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-decode)

[ICertEncodeLongArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-reset)

[ICertEncodeLongArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-setvalue)