# CRYPT_TIMESTAMP_CONTEXT structure

## Description

The **CRYPT_TIMESTAMP_CONTEXT** structure contains both the encoded and decoded representations of a time stamp token.

## Members

### `cbEncoded`

The size, in bytes, of the buffer pointed to by the **pbEncoded** member.

### `pbEncoded`

A pointer to a buffer that contains an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded content information sequence. This value should be stored for future time stamp validations on the signature. Applications can use the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function with the **CERT_STORE_PROV_PKCS7** flag to find additional certificates or [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) related to the TSA time stamp signature.

### `pTimeStamp`

A pointer to a [CRYPT_TIMESTAMP_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_info) structure that contains a signed data content type in Cryptographic Message Syntax (CMS) format.