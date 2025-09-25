# ITfCategoryMgr::IsEqualTfGuidAtom

## Description

Determines whether the specified atom represents the specified GUID in the internal table.

## Parameters

### `guidatom` [in]

Specifies an atom that represents a GUID in the internal table.

### `rguid` [in]

Specifies the address of the GUID to compare with the atom in the internal table.

### `pfEqual` [out]

Pointer to a Boolean variable that receives an indication of whether the atom represents the GUID.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method cannot access the internal table. |
| **E_INVALIDARG** | The specified *pfEqual* parameter was **NULL** on input. |

## Remarks

If the atom specified by the *guidatom* parameter represents the **GUID** specified by the *rguid* parameter, the *pfEqual* parameter receives a nonzero value. Otherwise, the *pfEqual* parameter receives zero.

## See also

[ITfCategoryMgr interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcategorymgr), [ITfCategoryMgr::GetGUID](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-getguid), [ITfCategoryMgr::RegisterGUID](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcategorymgr-registerguid)