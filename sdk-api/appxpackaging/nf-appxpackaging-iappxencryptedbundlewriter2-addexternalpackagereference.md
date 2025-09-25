# IAppxEncryptedBundleWriter2::AddExternalPackageReference

## Description

Adds a reference within the encrypted package bundle to an external app package.

## Parameters

### `fileName` [in]

The name of the payload file. The file name path must be relative to the root of the package.

### `inputStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of *fileName*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxEncryptedBundleWriter2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptedbundlewriter2)