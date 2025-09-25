# ITfCategoryMgr::GetGUID

## Description

Obtains a GUID from the internal table using its atom.

## Parameters

### `guidatom` [in]

Contains a **TfGuidAtom** value that specifies the GUID to obtain.

### `pguid` [out]

Pointer to a **GUID** value that receives the **GUID** for the specified atom. Receives GUID_NULL if the **GUID** for the atom cannot be found.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pguid* is invalid. |

## See also

[nn-msctf-itfcategorymgr](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::RegisterGUID](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registerguid), [ITfCategoryMgr::IsEqualTfGuidAtom](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-isequaltfguidatom)