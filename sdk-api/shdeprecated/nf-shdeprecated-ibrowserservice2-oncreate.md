# IBrowserService2::OnCreate

## Description

Deprecated. Calls the derived class from the base class on receipt of a [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message. The derived class handles the message.

## Parameters

### `pcs` [in]

Type: **tagCREATESTRUCTW***

A pointer to a [CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructa) structure that receives the initialization parameters passed to the window procedure (WinProc) of the class.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.