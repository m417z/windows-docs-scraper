# CERT_LOGOTYPE_REFERENCE structure

## Description

The **CERT_LOGOTYPE_REFERENCE** structure contains logotype reference information.

## Members

### `cHashedUrl`

The number of elements in the **rgHashedUrl** array.

### `rgHashedUrl`

An array of [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structures that contain the hashed URL of the logotype. The **cHashedUrl** member contains the number of elements in this array.