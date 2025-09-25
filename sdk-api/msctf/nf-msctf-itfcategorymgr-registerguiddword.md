# ITfCategoryMgr::RegisterGUIDDWORD

## Description

Enters a DWORD value for a GUID previously registered in the Windows registry.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service that owns the GUID.

### `rguid` [in]

Contains the GUID that the **DWORD** is registered for.

### `dw` [in]

Contains the **DWORD** value registered for the GUID.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to register the **DWORD** value. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::GetGUIDDWORD](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-getguiddword), [ITfCategoryMgr::UnregisterGUIDDWORD](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-unregisterguiddword)