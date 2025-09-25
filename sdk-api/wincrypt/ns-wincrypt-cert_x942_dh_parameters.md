# CERT_X942_DH_PARAMETERS structure

## Description

The **CERT_X942_DH_PARAMETERS** structure contains parameters associated with a Diffie-Hellman [public key algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Members

### `p`

Prime modulus P. The most significant bit of the most significant byte must always be set to 1.

### `g`

Generator G. Must be the same length as **p** (must be padded with 0x00 bytes if it is less).

### `q`

Prime Q.

A factor of p–1. The most significant bit of the most significant byte must be set to 1.

### `j`

Optional subgroup factor.

### `pValidationParams`

Optional pointer to a [CERT_X942_DH_VALIDATION_PARAMS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_x942_dh_validation_params) structure. If the **cbData** member of the q BLOB is zero, all of the members of **pValidationParams** must be zero.