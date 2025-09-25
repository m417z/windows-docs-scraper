# IRichEditOle::SetDvaspect

## Description

Sets the aspect that a rich edit control uses to draw an object. This call does not change the drawing information cached in the object; this must be done by the caller. The call does cause the object to be redrawn.

## Parameters

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the object whose aspect is to be set. If this parameter is REO_IOB_SELECTION, the aspect of the selected object is to be set.

### `dvaspect`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Aspect to use when drawing. The values are defined by OLE.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_INVALIDARG is returned if the index is invalid.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)