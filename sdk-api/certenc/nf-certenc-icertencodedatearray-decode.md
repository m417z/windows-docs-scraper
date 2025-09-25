# ICertEncodeDateArray::Decode

## Description

The **Decode** method decodes an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded date array and stores the resulting array of date values in the **CertEncodeDateArray** object.

## Parameters

### `strBinary` [in]

An ASN.1-encoded **DATE** array.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method places the decoded contents of *strBinary* into the object's array of date values. If the object's array already contains date values, this existing content will be freed, and the array will be loaded with the decoded values.

#### Examples

For an example that uses the **Decode** method, see the [ICertEncodeDateArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-encode) method.

## See also

[ICertEncodeDateArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodedatearray)

[ICertEncodeDateArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodedatearray-encode)