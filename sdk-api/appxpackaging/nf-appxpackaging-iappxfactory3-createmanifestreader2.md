## Description

Creates a read-only manifest object model from contents provided by an [IStream](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream), with an optional parameter for specifying the expected digest for the manifest.

## Parameters

### `inputStream` [in]

The input stream that delivers the manifest XML for reading. The stream must support [ISequentialStream::Read](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-isequentialstream-read), [IStream::Seek](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-seek), and [IStream::Stat](https://learn.microsoft.com/windows/win32/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes may be passed to and returned by this method.

### `expectedDigest` [in,optional]

An LPCWSTR containing the expected digest, a hashed representation of the manifest file.

### `manifestReader` [out]

The created manifest reader.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_INVALID_MANIFEST | The *inputStream* does not contain syntactically valid XML for the manifest. |
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |

## Remarks

Use **CreateManifestReader2** to read a manifest outside of an app package. This method validates the manifest XML. The *manifestReader* provides access to all data elements and attributes in the manifest XML. The manifest logs the location of manifest validation errors in the ETW event log for AppxPackaging.

Get the digest string for the *expecteDigest* parameter by calling [IAppxDigestProvider::GetDigest](https://learn.microsoft.com/windows/win32/api/appxpackaging/nf-appxpackaging-iappxdigestprovider-getdigest).

#### Examples

For an example, see [Quickstart: Read app package manifest info](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-query-package-identity-information).

## See also