# IWMDMOperation::SetObjectTotalSize

## Description

The **SetObjectTotalSize** method assigns the total size in bytes of an object. This method is currently not called by Windows Media Device Manager.

## Parameters

### `dwSize` [in]

**DWORD** specifying the low-order bits of the object size, in bytes.

### `dwSizeHigh` [in]

**DWORD** specifying the high-order bits of the object size, in bytes.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The read operation should continue. |
| **WMDM_E_USER_CANCELLED** | The read operation should be cancelled without finishing. |
| **E_FAIL** | An unspecified error occurred, and the read operation should be cancelled without finishing. |

## Remarks

This method is called after **SetObjectAttributes**.

## See also

[Handling File Transfers Manually](https://learn.microsoft.com/windows/desktop/WMDM/handling-file-transfers-manually)

[IWMDMOperation Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmoperation)

[IWMDMOperation::GetObjectTotalSize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmoperation-getobjecttotalsize)