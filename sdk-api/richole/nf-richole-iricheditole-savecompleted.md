# IRichEditOle::SaveCompleted

## Description

Indicates when the most recent save operation has been completed and that the rich edit control should hold onto a different storage for the object.

## Parameters

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the object whose storage is being specified. If this parameter is REO_IOB_SELECTION, the selected object is used.

### `lpstg`

Type: **LPSTORAGE**

New storage for the object. If the storage is not **NULL**, the rich edit control releases any storage it is currently holding for the object and uses this new storage instead.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_INVALIDARG is returned if the index is invalid.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)