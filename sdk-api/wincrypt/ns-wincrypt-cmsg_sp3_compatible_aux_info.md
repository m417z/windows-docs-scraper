# CMSG_SP3_COMPATIBLE_AUX_INFO structure

## Description

The **CMSG_SP3_COMPATIBLE_AUX_INFO** structure contains information needed for SP3 compatible encryption.

## Members

### `cbSize`

Size of this structure in bytes.

### `dwFlags`

Setting CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG enables SP3 compatible encryption. Zero [salt](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) instead of no salt and the encryption algorithm parameters are **NULL** instead of containing encoded RC2 parameters or encoded IV octet string. The encrypted [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is encoded [little-endian](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) instead of [big-endian](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) form.