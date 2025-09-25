# IContextMenu3::HandleMenuMsg2

## Description

Allows client objects of the [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3) interface to handle messages associated with owner-drawn menu items.

## Parameters

### `uMsg`

Type: **UINT**

The message to be processed. In the case of some messages, such as WM_INITMENUPOPUP, WM_DRAWITEM, WM_MENUCHAR, or WM_MEASUREITEM, the client object being called may provide owner-drawn menu items.

### `wParam`

Type: **WPARAM**

Additional message information. The value of this parameter depends on the value of the *uMsg* parameter.

### `lParam`

Type: **LPARAM**

Additional message information. The value of this parameter depends on the value of the *uMsg* parameter.

### `plResult`

Type: **LRESULT***

The address of an **LRESULT** value that the owner of the menu will return from the message. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IContextMenu3::HandleMenuMsg2** generally replaces [IContextMenu2::HandleMenuMsg](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu2-handlemenumsg), and is called when [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) determines that [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3) is supported and one of the supported messages (see *uMsg*) has been received. However, in some cases, **IContextMenu2::HandleMenuMsg** is still called. Context menu hosts may dispatch menu messages through either or both methods. Consequently, if a Shell extension implements both **IContextMenu2::HandleMenuMsg** and **IContextMenu3::HandleMenuMsg2**, it must be prepared for menu messages to arrive through either method.

**Note** If [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3) is not implemented, there is no guarantee that [IContextMenu2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu2) will be called in its place. In some cases, the absence of **IContextMenu3** is determined and then the process is halted.