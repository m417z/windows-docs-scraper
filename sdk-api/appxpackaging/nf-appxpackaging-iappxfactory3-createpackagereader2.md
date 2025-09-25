## Description

Creates a read-only package reader from the contents provided by an [IStream](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream), with an optional parameter for specifying the expected digest for the package. This method does not validate the digital signature.

## Parameters

### `inputStream` [in]

The input stream that delivers the package for reading. The stream must support [ISequentialStream::Read](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-isequentialstream-read), [IStream::Seek](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-seek), and [IStream::Stat](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes may be passed to and returned by this method.

### `expectedDigest` [in,optional]

An LPCWSTR containing the expected digest, a hashed representation of the package file.

### `packageReader` [out]

The created package reader.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_INTERLEAVING_NOT_ALLOWED | The ZIP file delivered by *inputStream* is an interleaved OPC package.
| APPX_E_RELATIONSHIPS_NOT_ALLOWED | The OPC package delivered by *inputStream* contains OPC package/part relationships. |
| APPX_E_MISSING_REQUIRED_FILE | The OPC package delivered by *inputStream* does not have a manifest, or a block map, or a signature file when a CI catalog is present. |
| APPX_E_INVALID_MANIFEST | The package manifest is not valid. |
| APPX_E_INVALID_BLOCKMAP | The package block map is not valid, the list of files in the ZIP central directory does not match the list of files in the block map, or the size of files listed in the ZIP central directory does not match the file and block sizes listed in the block map. |
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |

## Remarks

The **CreatePackageReader2** method immediately retrieves footprint elements of the app package through the stream and validates their content. This method succeeds only if the OPC package and all footprint elements (including ZIP central directory, manifest, [Content_Types].xml, and block map) are valid.

Get the digest string for the *expecteDigest* parameter by calling [IAppxDigestProvider::GetDigest](https://learn.microsoft.com/windows/win32/api/appxpackaging/nf-appxpackaging-iappxdigestprovider-getdigest).

#### Examples

For an example, see [Quickstart: Extract app package contents](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-extract-content-from-a-package) and [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also