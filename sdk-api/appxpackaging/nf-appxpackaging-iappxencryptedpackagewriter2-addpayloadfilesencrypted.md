# IAppxEncryptedPackageWriter2::AddPayloadFilesEncrypted

## Description

Adds one or more payload files to an encrypted app package.

## Parameters

### `fileCount` [in]

The number of payload files to be added to the encrypted app package.

### `payloadFiles` [in]

The payload files to be added.

### `memoryLimit` [in]

The memory limit in bytes.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code.

## See also

[IAppxEncryptedPackageWriter2](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxencryptedpackagewriter2)