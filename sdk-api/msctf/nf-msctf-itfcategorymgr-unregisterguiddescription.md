# ITfCategoryMgr::UnregisterGUIDDescription

## Description

Removes the description for a GUID from the Windows registry.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service that owns the GUID.

### `rguid` [in]

Contains the GUID that the description is removed for.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The GUID cannot be found. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::GetGUIDDescription](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-getguiddescription), [ITfCategoryMgr::RegisterGUIDDescription](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registerguiddescription)