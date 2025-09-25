# IAppxBundleWriter4::AddExternalPackageReference

## Description

Adds a reference within the package bundle to an external app package.

## Parameters

### `fileName` [in]

The name of the payload file. The file name path must be relative to the root of the package.

### `inputStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of *fileName*.

### `isDefaultApplicablePackage` [in]

A flag for whether this package is a default applicable package.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetIsDefaultApplicablePackage](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxbundlemanifestpackageinfo2-getisdefaultapplicablepackage)

[IAppxBundleWriter4](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxbundlewriter4)