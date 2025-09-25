# IFileSystemImage::ImportSpecificFileSystem

## Description

Import a specific file system from disc.

## Parameters

### `fileSystemToUse` [in]

Identifies the file system to import. For possible values, see the [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |
| **IMAPI_E_MULTISESSION_NOT_SET** | MultisessionInterfaces property must be set prior calling this method.<br><br>Value: 0xC0AAB15D |
| **IMAPI_E_BOOT_OBJECT_CONFLICT** | A boot object can only be included in an initial disc image.<br><br>Value: 0xC0AAB149 |
| **IMAPI_E_EMPTY_DISC** | Optical media is empty.<br><br>Value: 0xC0AAB150 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **IMAPI_E_NO_COMPATIBLE_MULTISESSION_TYPE** | IMAPI supports none of the multisession type(s) provided on the current media.<br><br>Value: 0xC0AAB15C<br><br>**Note** [IFileSystemImage::ImportFileSystem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-importfilesystem) method returns this error if there is no media in the recording device. |
| **IMAPI_E_INCOMPATIBLE_PREVIOUS_SESSION** | Operation failed because of incompatible layout of the previous session imported from the medium.<br><br>Value: 0xC0AAB133 |
| **IMAPI_E_FILE_SYSTEM_NOT_FOUND** | The specified disc does not contain a '%1!ls!' file system.<br><br>Value: 0xC0AAB152 |
| **IMAPI_E_INVALID_PATH** | The file system specified for import contains an invalid file name.<br><br>Value: 0xC0AAB110 |

## Remarks

You must call [IFileSystemImage::put_MultisessionInterfaces](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_multisessioninterfaces) prior to calling **IFileSystemImage::ImportSpecificFileSystem**. Additionally, it is recommended that [IDiscFormat2::get_MediaHeuristicallyBlank](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2-get_mediaheuristicallyblank) is called before **IFileSystemImage::put_MultisessionInterfaces** to verify that the media is not blank.

You may call this method at any time during the construction of the in-memory file system. If, during import, a file or directory already exists in the in-memory copy, the in-memory version will be retained; the imported file will be discarded.

On re-writable media (DVD+/-RW, DVDRAM, BD-RE), import or burning a second session is not support if the first session has an ISO9660 file system, due to file system limitations.

This method only reads the file information. If the item is a file, the file data is copied when calling [IFsiDirectoryItem::AddFile](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addfile), [IFsiDirectoryItem::AddTree](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addtree), or [IFsiDirectoryItem::Add](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-add) method.

this method returns **IMAPI_E_INCOMPATIBLE_PREVIOUS_SESSION** if the layout of the file system in the last session is incompatible with the layout used by IMAPI for the creation of requested file systems for the result image. For more details see the [IFileSystemImage::put_FileSystemsToCreate](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-put_filesystemstocreate) method documentation.
If the file system specified by *fileSystemToUse* has not been found, this method returns **IMAPI_E_FILE_SYSTEM_NOT_FOUND**.

## See also

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)