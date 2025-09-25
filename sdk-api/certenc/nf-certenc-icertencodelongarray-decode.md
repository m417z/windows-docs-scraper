# ICertEncodeLongArray::Decode

## Description

The **Decode** method decodes an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded **Long** array and stores the resulting array of **Long** values in the **CertEncodeLongArray** object.

## Parameters

### `strBinary` [in]

An ASN.1-encoded **Long** array.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method places the decoded contents of *strBinary* into the object's array of **Long** values. If the object's array already contains **Long** values, the existing content will be freed, and the array will be loaded with the decoded values.

#### Examples

For an example that uses the **Decode** method, see the [ICertEncodeLongArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-encode) method.

## See also

[ICertEncodeLongArray](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodelongarray)

[ICertEncodeLongArray::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodelongarray-encode)