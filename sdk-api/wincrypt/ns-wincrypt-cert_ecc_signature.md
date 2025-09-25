# CERT_ECC_SIGNATURE structure

## Description

The **CERT_ECC_SIGNATURE** structure contains the r and s values for an Elliptic Curve Digital Signature Algorithm (ECDSA) signature.

## Members

### `r`

The r value of the ECDSA signature. This value is in [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) order.

### `s`

The s value of the ECDSA signature. This value is in little-endian order.

## Remarks

Before encoding, a leading zero byte will be inserted for the **r** and **s** members. After decoding, a leading zero byte will be removed from the **r** and **s** members if the leading zero is present.