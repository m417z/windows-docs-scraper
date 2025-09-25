# ITfCategoryMgr::RegisterGUIDDescription

## Description

Enters a description for a GUID previously registered in the Windows registry.

## Parameters

### `rclsid` [in]

Contains the CLSID of the text service that owns the GUID.

### `rguid` [in]

Contains the GUID that the description is registered for.

### `pchDesc` [in]

Pointer to a **WCHAR** buffer that contains the description for the GUID.

### `cch` [in]

Contains the length, in characters, of the description string.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to register the description string. |
| **E_INVALIDARG** | *pchDest* is invalid. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::GetGUIDDescription](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-getguiddescription), [ITfCategoryMgr::UnregisterGUIDDescription](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-unregisterguiddescription)