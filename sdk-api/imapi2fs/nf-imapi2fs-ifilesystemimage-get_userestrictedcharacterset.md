# IFileSystemImage::get_UseRestrictedCharacterSet

## Description

Determines if the file and directory names use a restricted character.

## Parameters

### `pVal` [out]

Is VARIANT_TRUE if the file and directory names to add to the file system image must consist of characters that map directly to CP_ANSI (code points 32 through 127). Otherwise, VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::CreateDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createdirectoryitem)

[IFileSystemImage::CreateFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createfileitem)

[IFileSystemImage::put_UseRestrictedCharacterSet](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_userestrictedcharacterset)