# IWMDMOperation::GetObjectTotalSize

## Description

Windows Media Device Manager calls **GetObjectTotalSize** before a file is written to the device in order to retrieve the total size of the object, in bytes.

## Parameters

### `pdwSize` [out]

Pointer to a **DWORD** that, on return, specifies the low-order bits of the object size in bytes.

### `pdwSizeHigh` [out]

Pointer to a **DWORD** that, on return, specifies the high-order bits of the object size in bytes.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

This method is called after the [GetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjectattributes) method has been called. When transferring, the object implementing this interface is passed the total size of the content being sent.

#### Examples

The following C++ code implements GetObjectTotalSize. It uses the Win32 function GetFileInformationByHandle to retrieve the file size of the file about to be written to the device (m_File), and returns the values.

```cpp

// About to start writing to the device.
HRESULT GetObjectTotalSize(DWORD*  pdwSize,    DWORD*  pdwSizeHigh)
{
    BY_HANDLE_FILE_INFORMATION fileInfo;
    GetFileInformationByHandle(
        m_File,
        &fileInfo);

    *pdwSize = fileInfo.nFileSizeLow;
    *pdwSizeHigh = fileInfo.nFileSizeHigh;
    // TODO: Display the message: "IWMDMOperation event--GetObjectTotalSize."
    return S_OK;
}

```

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[SetObjectTotalSize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-setobjecttotalsize)