# CERT_DSS_PARAMETERS structure

## Description

The **CERT_DSS_PARAMETERS** structure contains parameters associated with a [Digital Signature Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSS) [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) algorithm.

## Members

### `p`

Prime modulus P. The most significant bit of the most significant byte must always be set to 1.

### `q`

Prime Q. It is 20 bytes in length. The most significant bit of the most significant byte must be set to 1.

### `g`

Generator G. Must be the same length as **p** (must be padded with 0x00 bytes if it is less).