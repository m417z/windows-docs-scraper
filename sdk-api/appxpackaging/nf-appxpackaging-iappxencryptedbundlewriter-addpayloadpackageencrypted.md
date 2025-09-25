# IAppxEncryptedBundleWriter::AddPayloadPackageEncrypted

## Description

Encrypts a new payload package to the bundle.

## Parameters

### `fileName` [in]

The name of the payload file. The file name path must be relative to the root of the package.

### `packageStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that provides the contents of *fileName*.
The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptedBundleWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptedbundlewriter)