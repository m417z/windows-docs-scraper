# IAppxEncryptionFactory::DecryptPackage

## Description

Creates an unencrypted Windows app package from an encrypted one.

## Parameters

### `inputStream` [in]

A readable stream from the app package to be decrypted.

### `outputStream` [in]

A writable stream for writing the resulting decrypted app package.

### `keyInfo` [in]

Key info containing the base encryption key and key ID for decrypting the package. The base encryption key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptionFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory)