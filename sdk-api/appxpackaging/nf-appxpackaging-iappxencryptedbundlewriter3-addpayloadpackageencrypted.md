# IAppxEncryptedBundleWriter3::AddPayloadPackageEncrypted

## Description

Encrypts a new payload package to the bundle.

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

[IAppxEncryptedBundleWriter3](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptedbundlewriter3)