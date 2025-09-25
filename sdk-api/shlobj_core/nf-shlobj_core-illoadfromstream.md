# ILLoadFromStream function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Deprecated. Loads an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure from a stream.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer that indicates the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface that the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) loads from.

### `pidl` [out]

Type: **PIDLIST_RELATIVE***

Address of a pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. **ILLoadFromStream** allocates the necessary memory for the structure, and assigns the address to this parameter.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error-code otherwise.

## Remarks

When you are finished with the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure, you must free it by calling [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree).

## See also

[ILSaveToStream](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilsavetostream)