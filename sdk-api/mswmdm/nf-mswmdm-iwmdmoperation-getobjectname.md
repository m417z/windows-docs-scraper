# IWMDMOperation::GetObjectName

## Description

Windows Media Device Manager calls **GetObjectName** before an object is written to the device in order to know what it should be named on the device.

## Parameters

### `pwszName` [out]

Pointer to a wide-character null-terminated string that specifies the object name. The name should include a file extension, if required. Windows Media Device Manager allocates and releases this buffer. *nMaxChars* specifies the maximum number of characters, including the terminating null character.

### `nMaxChars` [in]

Integer specifying the number of characters in *pwszName*, including the terminating null character.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

This method is only called if the application did not specify the name as a parameter in the **Insert** method.

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::SetObjectName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-setobjectname)