# SspiDecryptAuthIdentity function

## Description

Decrypts the specified encrypted credential.

## Parameters

### `EncryptedAuthData` [in, out]

On input, a pointer to the encrypted credential structure to be decrypted. On output, a pointer to the decrypted credential structure.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.