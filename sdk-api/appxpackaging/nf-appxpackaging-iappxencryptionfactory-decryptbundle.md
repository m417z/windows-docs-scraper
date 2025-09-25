# IAppxEncryptionFactory::DecryptBundle

## Description

Creates an unencrypted Windows app bundle from an encrypted one.

## Parameters

### `inputStream` [in]

A readable stream from the app bundle to be decrypted.

### `outputStream` [in]

A validation stream for writing the resulting decrypted app bundle.

### `keyInfo` [in]

Key info containing the base encryption key and key ID for decrypting the bundle. The base key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptionFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory)