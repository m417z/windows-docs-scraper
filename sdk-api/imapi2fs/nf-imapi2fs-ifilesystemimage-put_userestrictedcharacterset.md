# IFileSystemImage::put_UseRestrictedCharacterSet

## Description

Determines if file and directory names should be restricted to using only CP_ANSI characters.

**Note** **IFileSystemImage::put_UseRestrictedCharacterSet** has been deprecated. Implementing this method is not recommended.

## Parameters

### `newVal` [in]

Set to VARIANT_TRUE to restrict file and directory names to use only CP_ANSI characters. Otherwise, VARIANT_FALSE. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

Setting this property does not affect files or directories already in the file system image.

You can change the value of this property only when the result stream is not active.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::CreateDirectoryItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createdirectoryitem)

[IFileSystemImage::CreateFileItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createfileitem)

[IFileSystemImage::get_UseRestrictedCharacterSet](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_userestrictedcharacterset)