# IFileSystemImage::Exists

## Description

Checks for the existence of a given file or directory.

## Parameters

### `fullPath` [in]

String that contains the fully qualified path of the directory or file to check.

### `itemType` [out]

Indicates if the item is a file, a directory, or does not exist. For possible values, see the [FsiItemType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsiitemtype) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_INVALID_PATH** | The specified path is not fully qualified. The path must begin with '\\' or '/' to indicate the image root, or the images position within a directory structure.<br><br>Value: 0xC0AAB110 |
| **IMAPI_E_DIR_NOT_FOUND** | The directory '%1!s!' not found in FileSystemImage hierarchy.<br><br>Value: 0xC0AAB11A |
| **E_NOINTERFACE** | The object doesn't support this interface.<br><br>Value: 0x80004002 |

## See also

[FsiItemType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsiitemtype)

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)