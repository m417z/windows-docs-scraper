# IWMDMOperation::GetObjectAttributes

## Description

The **GetObjectAttributes** method allows the application to specify attributes for an object being written to a device. Windows Media Device Manager calls this method before a file is written to the device in order to learn the file's attributes.

## Parameters

### `pdwAttributes` [out]

Pointer to a **DWORD** that specifies the attributes defined in the [IWMDMStorage::GetAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getattributes) method.

### `pFormat` [out]

Pointer to a [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structure that specifies the audio format for files with audio data attributes.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

When transferring data to the device, you should provide object attributes for optimal transference.

#### Examples

The following C++ code implements the **GetObjectAttributes** method. It tries to determine if the file being read (m_File) is a file or folder, and set the returned attributes accordingly.

```cpp

HRESULT GetObjectAttributes(DWORD* pdwAttributes, _WAVEFORMATEX* pFormat)
{
    // TODO: Display the message: IWMDMOperation event--GetObjectAttributes.
    *pdwAttributes = WMDM_FILE_ATTR_FILE |
        WMDM_STORAGE_ATTR_REMOVABLE |
        WMDM_FILE_ATTR_AUDIO;

    BY_HANDLE_FILE_INFORMATION fileInformation;
    if (GetFileInformationByHandle(m_File, &fileInformation))
    {
        if (fileInformation.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            *pdwAttributes |= WMDM_FILE_ATTR_FOLDER;
        else
            *pdwAttributes |= WMDM_FILE_ATTR_FILE;

        if (fileInformation.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
            *pdwAttributes |= FILE_ATTRIBUTE_READONLY;
    }

    return S_OK;
}

```

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::SetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-setobjectattributes)