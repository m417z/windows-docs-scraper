# IContextMenu2::HandleMenuMsg

## Description

Enables client objects of the [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) interface to handle messages associated with owner-drawn menu items.

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

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IContextMenu2::HandleMenuMsg** is generally replaced by [HandleMenuMsg2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu3-handlemenumsg2). **HandleMenuMsg2** is called when [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) determines that [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3) is supported and receives one of the messages specified in the description of the *uMsg* parameter. However, in some cases, **IContextMenu2::HandleMenuMsg** is still called.

If [IContextMenu2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu2) or [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3) is needed, the best implementation for new context menus is to implement all their logic in [HandleMenuMsg2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu3-handlemenumsg2) and have their **IContextMenu2::HandleMenuMsg** implementation simply delegate the call to **HandleMenuMsg2** and pass **NULL** as the *plResult* parameter.

**Note** If [IContextMenu3](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu3) is not implemented, there is no guarantee that [IContextMenu2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu2) will be called in its place. In some cases, the absence of **IContextMenu3** is determined and then the process is halted.

## See also

[HandleMenuMsg2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu3-handlemenumsg2)

[IContextMenu2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu2)