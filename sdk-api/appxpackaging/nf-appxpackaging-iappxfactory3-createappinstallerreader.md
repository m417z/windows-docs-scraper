## Description

Creates an instance of [IAppxInstallerReader](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxappinstallerreader), with an optional parameter for specifying the expected digest for the App Installer file.

## Parameters

### `inputStream` [in]

An [IStream](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream) that provides the contents of an App Installer File.

### `expectedDigest` [in, optional]

An LPCWSTR containing the expected digest, a hashed representation of the App Installer File.

### `appInstallerReader` [out]

Receives the created **IAppInstallerReader** Instance.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|-------------|-------------|
| APPX_E_DIGEST_MISMATCH | The digest for the object doesn't match the digest provided in *expectedDigest*. |

## Remarks

Get the digest string for the *expecteDigest* parameter by calling [IAppxDigestProvider::GetDigest](https://learn.microsoft.com/windows/win32/api/appxpackaging/nf-appxpackaging-iappxdigestprovider-getdigest).

## See also

[App Installer File overview](https://learn.microsoft.com/windows/msix/app-installer/app-installer-file-overview)