# IAppxBundleWriter4::AddPayloadPackage

## Description

Adds a new app package to the bundle.

## Parameters

### `fileName` [in]

The name of the payload file. The file name path must be relative to the root of the package.

### `packageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of *fileName*.

### `isDefaultApplicablePackage` [in]

A flag for whether this package is a default applicable package.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBundleWriter4](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlewriter4)