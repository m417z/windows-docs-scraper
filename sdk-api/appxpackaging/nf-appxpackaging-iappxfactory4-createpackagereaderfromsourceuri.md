## Description

Creates an instance of [IAppxPackageReader](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxapppackagereader) from the specified package location URI, with an optional parameter for specifying the expected digest for the App Installer file.

## Parameters

### `uri` [in]

An LPCWSTR containing the URI of the package location.

### `expectedDigest` [in, optional]

An LPCWSTR containing the expected digest, a hashed representation of the App Installer File.

### `packageReader` [out]

Receives the created **IAppxPackageReader** instance.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |
| APPX_E_MISSING_REQUIRED_FILE | The OPC package delivered by *uri* does not have a manifest, or a block map, or a signature file when a CI catalog is present. |
| E_POINTER | The *uri* or *bundleReader* param is NULL. |
| HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) | The URI specified in *uri* is not valid. |

## Remarks

For HTTPS URIs, the server must support range requests.

## See also