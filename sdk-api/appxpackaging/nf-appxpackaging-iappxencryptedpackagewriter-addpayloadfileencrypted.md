# IAppxEncryptedPackageWriter::AddPayloadFileEncrypted

## Description

Adds a new encrypted payload file to the appx package.

## Parameters

### `fileName` [in]

The name of the payload file. The file name path must be relative to the root of the package.

### `compressionOption` [in]

The type of compression to use to store *fileName* in the package.

### `inputStream` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) providing the contents of *fileName*.
The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptedPackageWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptedpackagewriter)