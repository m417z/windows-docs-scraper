# IFileSystemImage::GetDefaultFileSystemForImport

## Description

Retrieves the file system to import by default.

## Parameters

### `fileSystems` [in]

One or more file system values. For possible values, see the [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

### `importDefault` [out]

A single file system value that identifies the default file system. The value is one of the file systems specified in *fileSystems*

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |

## Remarks

Use this method to identify the default file system to use with [IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem).

To identify the supported file systems, call the [IFileSystemImage::get_FileSystemsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_filesystemssupported) method.

## See also

[FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems)

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem)

[IFileSystemImage::get_FileSystemsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_filesystemssupported)