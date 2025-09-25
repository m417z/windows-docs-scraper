# IWMDMStorage::GetAttributes

## Description

The **GetAttributes** method retrieves the attributes of the storage.

## Parameters

### `pdwAttributes` [out]

Pointer to a **DWORD** specifying one or more of the following attributes, combined with a bitwise **OR**.

| Attribute | Description |
| --- | --- |
| WMDM_STORAGE_ATTR_FILESYSTEM | This object is the top-level storage medium, for example, a storage card or some other type of on-board storage. |
| WMDM_STORAGE_ATTR_REMOVABLE | The global storage medium is removable. |
| WMDM_STORAGE_ATTR_NONREMOVABLE | The global storage medium is not removable. |
| WMDM_STORAGE_ATTR_FOLDERS | The global storage medium supports folders and file hierarchy. |
| WMDM_STORAGE_ATTR_HAS_FILES | This storage object contains at least one file as an immediate child. |
| WMDM_STORAGE_ATTR_HAS_FOLDERS | This storage object contains at least one folder as an immediate child. |
| WMDM_STORAGE_ATTR_CANEDITMETADATA | This storage can edit metadata. |
| WMDM_FILE_ATTR_FILE | This is a file on the storage medium. |
| WMDM_FILE_ATTR_FOLDER | This is a folder on the storage medium. |
| WMDM_FILE_ATTR_LINK | This is a link that creates an association between multiple files. |
| WMDM_FILE_ATTR_AUDIO | This file contains audio data. |
| WMDM_FILE_ATTR_DATA | This file contains non-audio data. |
| WMDM_FILE_ATTR_CANPLAY | This audio file can be played by the device. |
| WMDM_FILE_ATTR_CANDELETE | This file can be deleted. |
| WMDM_FILE_ATTR_CANMOVE | This file or folder can be moved around on the storage medium. |
| WMDM_FILE_ATTR_CANRENAME | This file or folder can be renamed. |
| WMDM_FILE_ATTR_CANREAD | This file can be read by the host computer. |
| WMDM_FILE_ATTR_MUSIC | This audio file contains music. |
| WMDM_FILE_ATTR_AUDIOBOOK | This is an audio book file. |
| WMDM_FILE_ATTR_VIDEO | This file contains video data. |
| WMDM_FILE_ATTR_HIDDEN | This file is hidden on the file system |
| WMDM_FILE_ATTR_SYSTEM | This is a system file |
| WMDM_FILE_ATTR_READONLY | This is a read-only file. |
| WMDM_STORAGE_ATTR_VIRTUAL | This storage is virtual and does not correspond to an actual storage on the file system of the device. (Folders created based on metadata are one example of virtual storage.) |
| WMDM_STORAGE_IS_DEFAULT | This storage is the default location for putting new digital media on the device. |
| WMDM_STORAGE_CONTAINS_DEFAULT | This storage contains the default storage where new digital media should be placed. |

### `pFormat` [out]

Optional pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies the object's audio attributes.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Exploring a Device](https://learn.microsoft.com/windows/desktop/WMDM/exploring-a-device)

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorage::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-enumstorage)

[IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes)

[_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex)