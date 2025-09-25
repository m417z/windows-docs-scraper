# ITfCategoryMgr::UnregisterGUIDDWORD

## Description

Removes the DWORD value for a GUID from the Windows registry.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service that owns the GUID.

### `rguid` [in]

Contains the GUID that the **DWORD** is removed for.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The GUID cannot be found. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::GetGUIDDWORD](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-getguiddword), [ITfCategoryMgr::RegisterGUIDDWORD](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registerguiddword)