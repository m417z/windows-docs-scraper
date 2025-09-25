# IFileSystemImage::get_FileSystemsToCreate

## Description

Retrieves the types of file systems to create when generating the result stream.

## Parameters

### `pVal` [out]

One or more file system types to create when generating the result stream. For possible values, see the [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

To specify the file system types, call the [IFileSystemImage::put_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_filesystemstocreate) method. You could also call either [IFilesystemImage::ChooseImageDefaults](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-chooseimagedefaults) or [IFilesystemImage::ChooseImageDefaultsForMediaType](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-chooseimagedefaultsformediatype) to have IMAPI choose the file system for you.

To retrieve a list of supported file system types, call the [IFileSystemImage::get_FileSystemsSupported](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_filesystemssupported) method.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::CreateResultImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createresultimage)

[IFileSystemImage::put_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_filesystemstocreate)