# IMDSPStorage2::CreateStorage2

## Description

The **CreateStorage2** method creates a new storage with the specified name and returns a pointer to the **IMDSPStorage** interface on the newly created storage.

## Parameters

### `dwAttributes` [in]

**DWORD** containing the attributes as described in the **IMDSPStorage::CreateStorage** method.

### `dwAttributesEx` [in]

**DWORD** containing the extended attributes. There are currently no extended attributes defined.

### `pAudioFormat` [in]

Pointer to a **_WAVEFORMATEX** structure that contains audio format information about the object. This parameter is optional and is ignored if the file is not audio.

### `pVideoFormat` [in]

Pointer to a **_VIDEOINFOHEADER** structure that contains video format information about the object. This parameter is optional and is ignored if the file is not video.

### `pwszName` [in]

Pointer to a wide-character null-terminated string containing the name for the new storage.

### `qwFileSize` [in]

**QWORD** containing the size of the file to create. If the total size of the output file is not known at the time of creation, this value will be set to zero.

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

The new storage can be created at the same level or can be inserted into the current storage, provided that the current storage is a folder. This is controlled by the value of the *dwAttributes* parameter. If it specifies WMDM_STORAGECONTROL_INSERTBEFORE or WMDM_STORAGECONTROL_INSERTAFTER, the new storage will be created at the same level as the current storage. If it specifies WMDM_STORAGECONTROL_INSERTINTO, the new storage will be inserted into the current storage.

WMDM_STORAGECONTROL_INSERTBEFORE and WMDM_STORAGECONTROL_INSERAFTER imply an ordering of content in the file system. If the file system does not support ordering (for example, FAT32) both the flags have the identical effect of inserting the new storage at the same level as the current storage. If the current storage represents the root of the storage medium, and one of these two flags is specified, the operation fails.

WMDM_STORAGECONTROL_INSERTINTO is valid only if the current storage is a folder. If the current storage is a file, and this flag is specified, the operation fails.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage2)

[IMDSPStorage::CreateStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-createstorage)