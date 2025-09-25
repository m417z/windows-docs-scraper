# IWMDMStorage::SetAttributes

## Description

The **SetAttributes** method sets the attributes of the storage.

## Parameters

### `dwAttributes` [in]

**DWORD** specifying the attributes to be set. The following table lists the attributes that can be set by this parameter.

| Attribute | Description |
| --- | --- |
| WMDM_FILE_ATTR_AUDIO | This file contains audio data. |
| WMDM_FILE_ATTR_DATA | This file contains non-audio data. |
| WMDM_FILE_ATTR_CANPLAY | This audio file can be played by the device. |
| WMDM_FILE_ATTR_CANDELETE | This file can be deleted. |
| WMDM_FILE_ATTR_CANMOVE | This file or folder can be moved around on the storage medium. |
| WMDM_FILE_ATTR_CANRENAME | This file or folder can be renamed. |
| WMDM_FILE_ATTR_CANREAD | This file can be read by the host computer. |
| WMDM_FILE_ATTR_MUSIC | This audio file contains music. |
| WMDM_FILE_ATTR_AUDIOBOOK | This is an audio book file. |
| WMDM_FILE_ATTR_HIDDEN | This file is hidden on the file system |
| WMDM_FILE_ATTR_SYSTEM | This is a system file |
| WMDM_FILE_ATTR_READONLY | This is a read-only file. |

### `pFormat` [in]

Optional pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies audio information about the object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Many of the attributes listed for [GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes) cannot be set, and so are not listed in the attribute table for **SetAttributes**.

## See also

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes)