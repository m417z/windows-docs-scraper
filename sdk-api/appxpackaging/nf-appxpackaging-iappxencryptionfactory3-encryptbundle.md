# IAppxEncryptionFactory3::EncryptBundle

## Description

Creates an encrypted Windows app bundle from an unencrypted one.

## Parameters

### `inputStream` [in]

A readable stream from the app bundle to encrypt.

### `outputStream` [in]

A writable stream for writing the resulting encrypted app bundle.

### `settings` [in]

Settings for creating the bundle.

### `keyInfo` [in]

Key info containing the base encryption key and key ID for encrypting the bundle. The base encryption key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

### `exemptedFiles` [in]

Files exempted from the bundle writer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxEncryptionFactory3](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory3)