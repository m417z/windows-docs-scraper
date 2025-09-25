# CERT_NAME_INFO structure

## Description

The **CERT_NAME_INFO** structure contains subject or issuer names. The information is represented as an array of
[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structures.

## Members

### `cRDN`

Number of elements in the **rgRDN** array.

### `rgRDN`

Array of pointers to
[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structures.

## See also

[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn)

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)