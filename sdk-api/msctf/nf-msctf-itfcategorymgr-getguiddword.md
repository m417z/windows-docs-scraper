# ITfCategoryMgr::GetGUIDDWORD

## Description

Obtains the DWORD value of the specified GUID from the Windows registry.

## Parameters

### `rguid` [in]

Specifies the address of the GUID for which to get the value.

### `pdw` [out]

Pointer to the **DWORD** variable that receives the value of the GUID.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to get the **DWORD** value. |
| **E_INVALIDARG** | The specified *pdw* parameter was **NULL** on input. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::RegisterGUIDDWORD](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registerguiddword), [ITfCategoryMgr::UnregisterGUIDDWORD](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-unregisterguiddword)