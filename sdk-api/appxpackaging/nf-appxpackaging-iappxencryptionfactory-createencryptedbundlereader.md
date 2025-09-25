# IAppxEncryptionFactory::CreateEncryptedBundleReader

## Description

Creates a read-only bundle object to which encrypted Windows app packages can be added.

## Parameters

### `inputStream` [in]

A stream for reading the encrypted bundle.

### `keyInfo` [in]

 Key info containing the base encryption key and key ID for decrypting the bundle. The base key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

### `bundleReader` [out, retval]

The bundle reader object created.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptionFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptionfactory)