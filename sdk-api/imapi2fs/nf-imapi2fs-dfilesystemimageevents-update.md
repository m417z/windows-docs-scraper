# DFileSystemImageEvents::Update

## Description

Implement this method to receive progress notification of the current write operation. The notifications are sent when copying the content of a file or while adding directories or files to the file system image.

## Parameters

### `object` [in]

An [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage) interface of the file system image that is being written.

This parameter is a **CFileSystemImage** object in a script.

### `currentFile` [in]

String that contains the full path of the file being written.

### `copiedSectors` [in]

Number of sectors copied.

### `totalSectors` [out]

Total number of sectors in the file.

## Return value

Return values are ignored.

## Remarks

Notifications are sent in response to calling one of the following methods:

* [IFsiDirectoryItem::Add](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-add)
* [IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile)
* [IFsiDirectoryItem::AddTree](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addtree)

Notifications can also be sent when calling one of the following methods to import a UDF file system that was created using immediate allocation (immediate allocation means that the file data is contained within the file descriptor instead of having allocation descriptors in the file descriptor that point to sectors of data):

* [IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem)
* [IFileSystemImage::ImportSpecificFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importspecificfilesystem)

Notification is sent:

* Once before adding the first sector of a file (*copiedSectors* is 0)
* For every megabyte that is written
* Once after the final write if the file did not end on a megabyte boundary

## See also

[DFileSystemImageEvents](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-dfilesystemimageevents)