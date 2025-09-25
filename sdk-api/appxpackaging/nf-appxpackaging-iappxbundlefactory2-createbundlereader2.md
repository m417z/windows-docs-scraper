## Description

Creates a read-only bundle object that reads its contents from an [IStream](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream) object, with an optional parameter for specifying the expected digest for the bundle.

## Parameters

### `inputStream` [in]

The input stream that delivers the content of the package for reading. The stream must support [ISequentialStream::Read](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-isequentialstream-read), [IStream::Seek](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-seek), and [IStream::Stat](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes may be passed to and returned by this method.

### `expectedDigest` [in,optional]

An LPCWSTR containing the expected digest, a hashed representation of the bundle file.

### `bundleReader` [out]

The created bundle reader.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_INTERLEAVING_NOT_ALLOWED | The ZIP file delivered by *inputStream8 is an interleaved OPC package. |
| APPX_E_RELATIONSHIPS_NOT_ALLOWED | The OPC package delivered by *inputStream* contains OPC package/part relationships. |
| APPX_E_MISSING_REQUIRED_FILE | The OPC package delivered by *inputStream* does not have a manifest, or a block map, or a signature file when a CI catalog is present. |
| APPX_E_INVALID_MANIFEST | The bundle manifest is not valid. |
| APPX_E_INVALID_MANIFEST | The bundle manifest is not valid. |
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |

## Remarks

Get the digest string for the *expecteDigest* parameter by calling [IAppxDigestProvider::GetDigest](https://learn.microsoft.com/windows/win32/api/appxpackaging/nf-appxpackaging-iappxdigestprovider-getdigest).

## See also