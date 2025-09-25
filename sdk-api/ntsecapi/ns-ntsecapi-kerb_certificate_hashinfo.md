# KERB_CERTIFICATE_HASHINFO structure

## Description

The **KERB_CERTIFICATE_HASHINFO** structure provides the payload information of the certificate hash.

## Members

### `StoreNameLength`

Length, in bytes, of the WCHAR string specifying the certificate store name. If **StoreNameLength** is zero, the "MY" certificate store is implied; otherwise the WCHAR string must immediately follow the **KERB_CERTIFICATE_HASHINFO** structure in contiguous memory and must include a terminating null character.

### `HashLength`

Length, in bytes, of the certificate hash. The certificate hash data must follow the **KERB_CERTIFICATE_HASHINFO** structure and certificate store name (if present) in contiguous memory.