# DFileSystemImageImportEvents::UpdateImport

## Description

Receives import notification for every file and directory item imported from an optical medium.

## Parameters

### `object` [in]

Pointer to an [IFilesystemImage3](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage3) interface of a file system image object to which data is being imported.

### `fileSystem` [in]

Type of the file system currently being imported. For possible values, see the [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

### `currentItem` [in]

A string containing the name of the file or directory being imported at the moment.

### `importedDirectoryItems` [in]

The number of directories imported so far.

### `totalDirectoryItems` [in]

The total number of directories to be imported from the optical medium.

### `importedFileItems` [in]

The number of files imported so far.

### `totalFileItems` [in]

The total number of files to be imported from the optical medium.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Notifications are sent in response to calling one of the following methods for importing a file system.

* [IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem)
* [IFileSystemImage::ImportSpecificFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importspecificfilesystem)

UpdateImport method receives import notifications from ISO9660, Joliet and UDF file systems. A notification is sent:

* Once after every individual imported file.
* Once before every directory import begins.

The *totalFileItems* parameter of an **UpdateImport** event is always set to (-1) for ISO9660 and Joliet file systems, because of the difficulty quickly and accurately determining the total number of files in an ISO9660/Joliet file system prior to import.

Import notifications are generated only for files and directories, and not for associated named streams.

If the *currentItem* is a directory, it contains a back slash '\' at the end.

## See also

[DFileSystemImageImportEvents](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-dfilesystemimageimportevents)