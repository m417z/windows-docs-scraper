# ITfCategoryMgr::GetGUIDDescription

## Description

Obtains the description of the specified GUID from the Windows registry.

## Parameters

### `rguid` [in]

Specifies the GUID to obtain the description for.

### `pbstrDesc` [out]

Pointer to a **BSTR** value that receives the description string. Allocate using [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The caller must free this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

Pointer to a **BSTR** value that receives the description string. This must be allocated using **SysAllocString**. The caller must free this memory using **SysFreeString** when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method cannot obtain the description. |
| **E_INVALIDARG** | *pbstrDesc* is invalid. |

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::RegisterGUIDDescription](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registerguiddescription), [ITfCategoryMgr::UnregisterGUIDDescription](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-unregisterguiddescription)