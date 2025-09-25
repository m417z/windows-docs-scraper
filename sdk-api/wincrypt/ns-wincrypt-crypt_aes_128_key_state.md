# CRYPT_AES_128_KEY_STATE structure

## Description

The **CRYPT_AES_128_KEY_STATE** structure specifies the 128-bit [symmetric key](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) information for an [Advanced Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (AES) cipher.

## Members

### `Key`

An array of hexadecimal values that specify a 128-bit [cipher](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) key.

### `IV`

An array of hexadecimal values that specify an [initialization vector](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) (IV) for the [cipher](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `EncryptionState`

An array of hexadecimal values that specify an 11-round encryption key schedule.

### `DecryptionState`

An array of hexadecimal values that specify an 11-round decryption key schedule.

### `Feedback`

An array of hexadecimal values that specify the feedback vector for a stage in the encryption or decryption process.

## Remarks

The **CRYPT_AES_128_KEY_STATE** structure is used by the [CPImportKey](https://learn.microsoft.com/previous-versions/aa379853(v=vs.85)) and [CPExportKey](https://learn.microsoft.com/previous-versions/aa378203(v=vs.85)) functions when the [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) was created by using the *dwBlobType* parameter set to the **KEYSTATEBLOB** value.

 The Microsoft AES Cryptographic Provider only supports this structure in the context of the [Secure Sockets Layer protocol](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL), where the caller specified **PROV_DH_SCHANNEL** as the value for the *dwProvType* parameter of the [CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta) function.