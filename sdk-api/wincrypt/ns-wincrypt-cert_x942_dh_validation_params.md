# CERT_X942_DH_VALIDATION_PARAMS structure

## Description

The **CERT_X942_DH_VALIDATION_PARAMS** structure is optionally pointed to by a member of the [CERT_X942_DH_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_x942_dh_parameters) structure and contains additional seed information.

## Members

### `seed`

A [CRYPT_UINT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains an unsigned seed value.

### `pgenCounter`

A **DWORD** counter.