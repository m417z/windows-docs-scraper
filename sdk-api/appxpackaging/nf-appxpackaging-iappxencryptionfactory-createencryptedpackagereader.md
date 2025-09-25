# IAppxEncryptionFactory::CreateEncryptedPackageReader

## Description

Creates a new instance of [IAppxPackageReader](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxpackagereader) for reading encrypted packages.

## Parameters

### `inputStream` [in]

A readable stream from the app package.

### `keyInfo` [in]

Key info containing the base encryption key and key ID for encrypting the package. The base encryption key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

### `packageReader` [out, retval]

The package reader object created.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptionFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory)