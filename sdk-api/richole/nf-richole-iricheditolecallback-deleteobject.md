# IRichEditOleCallback::DeleteObject

## Description

Sends notification that an object is about to be deleted from a rich edit control. The object is not necessarily being released when this member is called.

## Parameters

### `lpoleobj`

Type: **LPOLEOBJECT**

The object that is being deleted.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK**.

## See also

[IRichEditOleCallback](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditolecallback)