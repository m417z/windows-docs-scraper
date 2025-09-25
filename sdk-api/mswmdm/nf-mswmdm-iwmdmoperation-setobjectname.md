# IWMDMOperation::SetObjectName

## Description

The **SetObjectName** method assigns a name to the content being read or written. This method is currently not called by Windows Media Device Manager.

## Parameters

### `pwszName` [in]

Pointer to a wide-character null-terminated string specifying the object name.

### `nMaxChars` [in]

Integer specifying the maximum number of characters that this string can hold.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

This method is called after **BeginRead** is called.

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::GetObjectName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjectname)