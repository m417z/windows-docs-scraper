# IMDSPStorage::CreateStorage

## Description

The **CreateStorage** method creates a new storage and returns a pointer to the **IMDSPStorage** interface on the newly created storage. This method is optional unless *dwAttributes* is WMDM_FILE_ATTR_FILE. In that case, this method must be implemented and must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## Parameters

### `dwAttributes` [in]

**DWORD** containing the attributes for the new storage. The following table lists the available storage attributes.

| Attribute | Description |
| --- | --- |
| WMDM_STORAGECONTROL_INSERTBEFORE | The new storage object will be created in front of the target object. |
| WMDM_STORAGECONTROL_INSERTAFTER | The new storage object will be created after the target object. |
| WMDM_STORAGECONTROL_INSERTINTO | The new storage object will be created in the target object folder. |
| WMDM_STORAGECONTROL_OVERWRITE | If storage with the same name already exists, it will be destroyed and a new storage created. |
| WMDM_STORAGE_ATTR_FILESYSTEM | This object is the top-level storage medium (for example, a storage card or some other on-board storage.) |
| WMDM_STORAGE_ATTR_REMOVABLE | This storage medium is removable. |
| WMDM_STORAGE_ATTR_CANEDITMETADATA | This storage can edit metadata. |
| WMDM_STORAGE_ATTR_FOLDERS | This storage medium supports folders and file hierarchy. |
| WMDM_FILE_ATTR_FOLDER | This is a folder on the storage medium. |
| WMDM_FILE_ATTR_LINK | This is a link that creates an association among multiple files. |
| WMDM_FILE_ATTR_FILE | This is a file on the storage medium. |
| WMDM_FILE_ATTR_AUDIO | This file is audio data. |
| WMDM_FILE_ATTR_DATA | This file is non-audio data. |
| WMDM_FILE_ATTR_CANPLAY | This audio file can be played by the device. |
| WMDM_FILE_ATTR_CANDELETE | This file can be deleted. |
| WMDM_FILE_ATTR_CANMOVE | This file or folder can be moved around on the storage medium. |
| WMDM_FILE_ATTR_CANRENAME | This file or folder can be renamed. |
| WMDM_FILE_ATTR_CANREAD | This file can be read by the host computer. |
| WMDM_FILE_ATTR_MUSIC | This audio file is music. |
| WMDM_FILE_ATTR_VIDEO | This file contains video data. |
| WMDM_FILE_ATTR_HIDDEN | This file is hidden on the file system |
| WMDM_FILE_ATTR_SYSTEM | This is a system file |
| WMDM_FILE_ATTR_READONLY | This is a read-only file. |
| WMDM_STORAGE_IS_DEFAULT | This storage is the default storage where new media should be placed. |
| WMDM_STORAGE_CONTAINS_DEFAULT | This storage contains the default storage where new media should be placed. |

### `pFormat` [in]

Pointer to a **_WAVEFORMATEX** structure that contains information about the object, if the object is an audio file.

### `pwszName` [in]

Pointer to a wide-character null-terminated string containing the name for the new storage.

### `ppNewStorage` [out]

Pointer to an **IMDSPStorage** pointer to receive the **IMDSPStorage** interface for the newly created storage.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If both the WMDM_FILE_ATTR_FOLDER and WMDM_FILE_ATTR_FILE attributes are set, the folder attribute overrides the file attribute, and the new storage is created as a folder.

Only one of WMDM_STORAGECONTROL_INSERTBEFORE, WMDM_STORAGECONTROL_INSERTAFTER, and WMDM_STORAGECONTROL_INSERTINTO can be specified by the client.

The new storage can be created at the same level or can be inserted into the current storage provided that the current storage is a folder. This is controlled by the value of *dwAttributes* parameter. If it specifies WMDM_STORAGECONTROL_INSERTBEFORE or WMDM_STORAGECONTROL_INSERTAFTER, the new storage will be created at the same level as the current storage. If it specifies WMDM_STORAGECONTROL_INSERTINTO, the new storage will be inserted into the current storage.

WMDM_STORAGECONTROL_INSERTBEFORE and WMDM_STORAGECONTROL_INSERAFTER imply an ordering of content in the file system. If the file system does not support ordering (for example, FAT32) both the flags have the identical effect of inserting the new storage at the same level of the current storage. If the current storage represents the root of the storage medium, and one of these two flags is specified, the operation fails.

WMDM_STORAGECONTROL_INSERTINTO is valid only if the current storage is a folder. If the current storage is a file, and this flag is specified, the operation fails.

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage2::CreateStorage2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage2-createstorage2)

[_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex)