# IWMDMOperation2::SetObjectAttributes2

## Description

The **SetObjectAttributes2** method sets attributes of files or storages. This method is currently not called by Windows Media Device Manager.

## Parameters

### `dwAttributes` [in]

Pointer to a **DWORD** specifying the attributes as defined by the [IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes) method.

### `dwAttributesEx` [in]

**DWORD** specifying the extended attributes. No extended attributes are currently defined.

### `pFormat` [in]

Optional pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies audio information about the object.

### `pVideoFormat` [in]

Optional pointer to a [_VIDEOINFOHEADER](https://learn.microsoft.com/windows/desktop/WMDM/-videoinfoheader) structure that specifies video information about the object.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## See also

[GetObjectAttributes2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation2-getobjectattributes2)

[IWMDMOperation2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation2)