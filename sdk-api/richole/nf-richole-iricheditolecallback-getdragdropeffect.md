# IRichEditOleCallback::GetDragDropEffect

## Description

Allows the client to specify the effects of a drop operation.

## Parameters

### `fDrag`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the query is for a [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) or [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover). **FALSE** if the query is for [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop).

### `grfKeyState`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Key state as defined by OLE.

### `pdwEffect`

Type: **[LPDWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The effect used by a rich edit control. When
*fDrag* is **TRUE**, on return, its content is set to the effect allowable by the rich edit control. When
*fDrag* is **FALSE**, on return, the variable is set to the effect to use.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This method returns **S_OK**.

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)