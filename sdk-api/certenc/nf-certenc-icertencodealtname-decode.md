# ICertEncodeAltName::Decode

## Description

The **Decode** method decodes an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1)-encoded alternate name extension and stores the resulting array of strings in the **CertEncodeAltName** object.

## Parameters

### `strBinary` [in]

Represents an ASN.1-encoded alternate name extension.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ICertEncodeAltName](https://learn.microsoft.com/windows/desktop/api/certenc/nn-certenc-icertencodealtname)

[ICertEncodeAltName::Encode](https://learn.microsoft.com/windows/desktop/api/certenc/nf-certenc-icertencodealtname-encode)