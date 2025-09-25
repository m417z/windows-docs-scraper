# IFileSystemImage::get_SessionStartBlock

## Description

Retrieves the starting block address for the recording session.

## Parameters

### `pVal` [out]

Starting block address for the recording session.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

The session starting block can be set in the following ways:

* Importing a file system automatically sets the session starting block.
* If the previous session is not imported, the client can call [IFileSystemImage::put_SessionStartBlock](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_sessionstartblock) to set this property.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem)

[IFileSystemImage::ImportSpecificFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importspecificfilesystem)