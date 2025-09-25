# IRichEditOle::HandsOffStorage

## Description

Indicates when a rich edit control is to release its reference to the storage interface associated with the specified object. This call does not call the object's **IRichEditOle::HandsOffStorage** method; the caller must do that.

## Parameters

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the object whose storage is to be released. If this parameter is REO_IOB_SELECTION, the storage of the selected object is to be released.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_INVALIDARG is returned if the index is invalid.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)