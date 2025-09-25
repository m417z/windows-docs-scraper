# ICertEncodeStringArray::Decode

## Description

The **Decode** method decodes an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded string array and stores the resulting array of strings in the **CertEncodeStringArray** object.

## Parameters

### `strBinary` [in]

An ASN.1-encoded string array.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method will place the decoded contents of *strBinary* into the object's array of strings. If the object's array already contains strings, this existing content will be freed, and the array will be loaded with the decoded values.

#### Examples

For an example that uses the **Decode** method, see the [ICertEncodeStringArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-encode) method.

## See also

[ICertEncodeStringArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodestringarray)

[ICertEncodeStringArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodestringarray-encode)