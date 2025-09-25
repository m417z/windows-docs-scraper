## Description

Creates a read-only bundle object to which encrypted Windows app packages can be added, with an optional parameter for specifying the expected digest for the encrypted bundle.

## Parameters

### `inputStream` [in]

A stream for reading the encrypted bundle.

### `keyInfo` [in]

 Key info containing the base encryption key and key ID for decrypting the bundle. The base key is used to derive the per file encryption keys. If this parameter is null, the global test key and key ID are used.

### `expectedDigest` [in.optional]

An LPCWSTR containing the expected digest, a hashed representation of the bundle file.

### `bundleReader` [out]

The created bundle reader.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |

## Remarks

Get the digest string for the *expecteDigest* parameter by calling [IAppxDigestProvider::GetDigest](https://learn.microsoft.com/windows/win32/api/appxpackaging/nf-appxpackaging-iappxdigestprovider-getdigest).

## See also