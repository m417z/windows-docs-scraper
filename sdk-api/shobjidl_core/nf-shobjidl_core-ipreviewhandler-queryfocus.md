# IPreviewHandler::QueryFocus

## Description

Directs the preview handler to return the **HWND** from calling the [GetFocus Function](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getfocus).

## Parameters

### `phwnd` [out]

Type: **HWND***

When this method returns, contains a pointer to the HWND returned from calling the [GetFocus Function](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getfocus) from the preview handler's foreground thread.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is necessary because [GetFocus Function](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getfocus) can only succeed if the focus is on a window created by the calling thread. This method is used by the host to manage the tabbing order and to support tabbing into and out of the preview handler's windows.