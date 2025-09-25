# IAppxBundleWriter3::AddPackageReference

## Description

Adds a reference to an optional app package or a payload file within an app bundle.

## Parameters

### `fileName` [in]

The name of the payload file. The file name path must be relative to the root of the package.

### `inputStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of *fileName*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

By adding a reference to a payload file or optional app package to an app bundle, the overall size of the bundle is reduced.

## See also

[IAppxBundleWriter3](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlewriter3)