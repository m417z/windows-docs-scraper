## Description

Creates a read-only bundle object that reads its contents from the specified URI, with an optional parameter for specifying the expected digest for the bundle.

## Parameters

### `uri` [in]

An LPCWSTR containing the URI of the bundle location.

### `expectedDigest` [in, optional]

An LPCWSTR containing the expected digest, a hashed representation of the bundle file.

### `bundleReader` [out]

The created [IAppxBundleReader](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxbundlereader) instance.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_INTERLEAVING_NOT_ALLOWED | The ZIP file delivered by *uri* is an interleaved OPC package. |
| APPX_E_RELATIONSHIPS_NOT_ALLOWED | The OPC package delivered by *uri* contains OPC package/part relationships. |
| APPX_E_MISSING_REQUIRED_FILE | The OPC package delivered by *uri* does not have a manifest, or a block map, or a signature file when a CI catalog is present. |
| APPX_E_INVALID_MANIFEST | The bundle manifest is not valid. |
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |
| E_POINTER | The *uri* or *bundleReader* param is NULL.|
| HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) | The URI specified in *uri* is not valid. |

## Remarks

## See also