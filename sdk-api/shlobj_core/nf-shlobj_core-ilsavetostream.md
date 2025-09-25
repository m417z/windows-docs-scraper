# ILSaveToStream function

## Description

Saves an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to a stream.

## Parameters

### `pstm` [in]

Type: **IStream ***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface where the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) is saved.

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

A pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure to be saved.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

The stream must be opened for writing, or **ILSaveToStream** returns an error.

## See also

[ILLoadFromStream](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-illoadfromstream)