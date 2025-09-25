# IAppxEncryptionFactory3::CreateEncryptedBundleWriter

## Description

Creates a write-only bundle object to which encrypted Windows app packages can be added.

## Parameters

### `outputStream` [in]

A writable stream for writing the resulting encrypted app bundle.

### `bundleVersion` [in]

The version number of the bundle. If the bundle version is 0, a default version based on the current system time will be generated.

### `settings` [in]

Settings for creating the package.

### `keyInfo` [in]

Key info containing the base encryption key and key ID for decrypting the bundle. The base key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

### `exemptedFiles` [in]

Files exempted from the bundle writer.

### `bundleWriter` [out, retval]

The bundle writer object created.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxEncryptionFactory3](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory3)