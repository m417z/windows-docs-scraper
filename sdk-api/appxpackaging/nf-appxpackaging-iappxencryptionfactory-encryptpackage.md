# IAppxEncryptionFactory::EncryptPackage

## Description

Creates an encrypted Windows app package from an unencrypted one.

## Parameters

### `inputStream` [in]

A readable stream from the app package to be encrypted.

### `outputStream` [in]

A writable stream for writing the resulting encrypted app package.

### `settings` [in]

Settings for creating the package.

### `keyInfo` [in]

Key information containing the base encryption key and key ID. The base key is used to derive the per file encryption keys. If the base key is null, the global test key and key Id are used.

### `exemptedFiles`

The list of files to be exempted from encryption.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptionFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory)