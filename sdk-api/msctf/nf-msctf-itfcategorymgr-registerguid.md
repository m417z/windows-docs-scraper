# ITfCategoryMgr::RegisterGUID

## Description

Adds a GUID to the internal table and obtains an atom for the GUID.

## Parameters

### `rguid` [in]

Contains the GUID to obtain the identifier for.

### `pguidatom` [out]

Pointer to a [TfGuidAtom](https://learn.microsoft.com/windows/desktop/TSF/tfguidatom) value that receives the identifier of the GUID.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *pguidatom* is invalid. |

## Remarks

Identical **GUID** values receive identical **TfGuidAtom** values.

A **TfGuidAtom** value is only valid within the process that **ITfCategoryMgr::RegisterGUID** is called from.

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::GetGUID](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-getguid), [ITfCategoryMgr::IsEqualTfGuidAtom](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-isequaltfguidatom), [TfGuidAtom](https://learn.microsoft.com/windows/win32/tsf/tfguidatom)