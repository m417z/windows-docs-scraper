# CERT_BIOMETRIC_EXT_INFO structure

## Description

The **CERT_BIOMETRIC_EXT_INFO** structure contains a set of biometric information.

## Members

### `cBiometricData`

The number of elements in the **rgBiometricData** array.

### `rgBiometricData`

An array of [CERT_BIOMETRIC_DATA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_biometric_data) structures that contain the biometric data. The **cBiometricData** member contains the number of elements in this array.

## See also

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex)