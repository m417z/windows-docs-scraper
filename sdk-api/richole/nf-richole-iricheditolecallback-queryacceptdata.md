# IRichEditOleCallback::QueryAcceptData

## Description

During a paste operation or a drag event, determines if the data that is pasted or dragged should be accepted.

## Parameters

### `lpdataobj`

Type: **LPDATAOBJECT**

The data object being pasted or dragged.

### `lpcfFormat`

Type: **CLIPFORMAT***

The clipboard format that will be used for the paste or drop operation. If the value pointed to by
*lpcfFormat* is zero, the best available format will be used. If the callback changes the value pointed to by
*lpcfFormat*, the rich edit control only uses that format and the operation will fail if the format is not available.

### `reco`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A clipboard operation flag, which can be one of these values.

| Value | Meaning |
| --- | --- |
| **RECO_DROP** | Drop operation (drag-and-drop). |
| **RECO_PASTE** | Paste from the clipboard. |

### `fReally`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether the drag-drop is actually happening or if it is just a query. A nonzero value indicates the paste or drop is actually happening. A zero value indicates the operation is just a query, such as for
[EM_CANPASTE](https://learn.microsoft.com/windows/desktop/Controls/em-canpaste).

### `hMetaPict`

Type: **[HGLOBAL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a metafile containing the icon view of an object if **DVASPECT_ICON** is being imposed on an object by a paste special operation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success. See Remarks.

## Remarks

 On failure, the rich edit control refuses the data and terminates the operation. Otherwise, the control checks the data itself for acceptable formats. A success code other than **S_OK** means that the callback either checked the data itself (if *fReally* is **FALSE**) or imported the data itself (if *fReally* is **TRUE**). If the application returns a success code other than **S_OK**, the control does not check the read-only state of the edit control.

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)