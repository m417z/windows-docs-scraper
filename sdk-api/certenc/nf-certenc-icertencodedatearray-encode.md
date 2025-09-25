# ICertEncodeDateArray::Encode

## Description

The **Encode** method returns an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded string of the date array stored in this object.

Use the [Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-decode) method to decode the encoded string into an **CertEncodeDateArray** object.

Before using this method, you must call both the
[Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-reset) method to size the array and the
[SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-setvalue) method to set each array element.

## Parameters

### `pstrBinary` [out]

A pointer to a **BSTR** that will contain the encoded **Date** array. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the ASN.1-encoded string that represents the **DATE** array.

## See also

[ICertEncodeDateArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodedatearray)

[ICertEncodeDateArray::Decode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-decode)

[ICertEncodeDateArray::Reset](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-reset)

[ICertEncodeDateArray::SetValue](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-setvalue)