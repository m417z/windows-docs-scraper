# IWMDMOperation2::GetObjectAttributes2

## Description

Windows Media Device Manager calls **GetObjectAttributes** when a file is written to the device in order to learn the attributes of the file.

## Parameters

### `pdwAttributes` [out]

Pointer to a **DWORD** specifying the storage attributes defined in the [IWMDMStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes) method.

### `pdwAttributesEx` [out]

Pointer to a **DWORD** specifying extended attributes. There are currently no extended attributes defined.

### `pAudioFormat` [out]

Optional pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies audio file attributes.

### `pVideoFormat` [out]

Optional pointer to a [_VIDEOINFOHEADER](https://learn.microsoft.com/windows/desktop/WMDM/-videoinfoheader) structure that specifies video object attributes.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## See also

[IWMDMOperation2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation2)

[SetObjectAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation2-setobjectattributes2)