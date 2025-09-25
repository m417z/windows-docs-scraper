# IWMDMOperation::SetObjectAttributes

## Description

The **SetObjectAttributes** method specifies the file attributes. This method is currently not called by Windows Media Device Manager.

## Parameters

### `dwAttributes` [in]

**DWORD** specifying the object attributes as defined in the [IWMDMStorage::SetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-setattributes) method.

### `pFormat` [in]

Pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure specifying the format for files with audio data attributes. If the file contains audio data, this parameter should be filled.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

Audio attributes include the number of samples per second, the number of bytes per sample, and so on.

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::GetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjectattributes)