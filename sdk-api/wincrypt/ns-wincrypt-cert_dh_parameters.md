# CERT_DH_PARAMETERS structure

## Description

The **CERT_DH_PARAMETERS** structure contains parameters associated with a [Diffie/Hellman](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) public key algorithm.

## Members

### `p`

Prime modulus P. The most significant bit of the most significant byte must always be set to 1.

### `g`

Generator G. Must be the same length as **p** (must be padded with 0x00 bytes if it is less).