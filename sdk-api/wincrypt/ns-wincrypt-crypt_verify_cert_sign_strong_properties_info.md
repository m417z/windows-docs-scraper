# CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO structure

## Description

Contains the length, in bits, of the public key and the names of the signing and hashing algorithms used for strong signing.

## Members

### `CertSignHashCNGAlgPropData`

The buffer contains a Unicode string that denotes the signing algorithm / hashing algorithm pair used, for example "RSA/SHA256".

### `CertIssuerPubKeyBitLengthPropData`

The buffer contains the length, in bits, of the asymmetric key used for signing.

## Remarks

This structure is returned by the [CryptVerifyCertificateSignatureEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifycertificatesignatureex) function when the *dwFlags* parameter is set to **CRYPT_VERIFY_CERT_SIGN_RETURN_STRONG_PROPERTIES_FLAG**.

## See also

[CryptVerifyCertificateSignatureEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptverifycertificatesignatureex)