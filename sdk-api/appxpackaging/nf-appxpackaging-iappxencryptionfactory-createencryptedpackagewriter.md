# IAppxEncryptionFactory::CreateEncryptedPackageWriter

## Description

Creates a new instance of an [IAppxEncryptedPackageWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptedpackagewriter).

## Parameters

### `outputStream` [in]

A writable stream for sending bytes produced by the app package.

### `manifestStream` [in]

A readable stream that defines the package for the AppxManifest.xml.

### `settings` [in]

Settings for creating the package.

### `keyInfo` [in]

Key info containing the base encryption key and key ID for encrypting the package. The base encryption key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

### `exemptedFiles`

The list of files to be exempted from encryption.

### `packageWriter` [out, retval]

The package writer object created.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptionFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory)