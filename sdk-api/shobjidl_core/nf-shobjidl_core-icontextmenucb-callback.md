# IContextMenuCB::CallBack

## Description

Enables the callback function for a context menu.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface of the object that supports the **IContextMenuCB::CallBack** interface. The context menu interface is returned on a call to [GetUIObjectOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getuiobjectof).

### `hwndOwner` [in, optional]

Type: **HWND**

A handle to the owner of the context menu. This value can be **NULL**.

### `pdtobj` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) that contains information about a menu selection. Implement interface **IDataObject**, or call [SHCreateDataObject](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedataobject) for the default implementation.

### `uMsg` [in]

Type: **UINT**

A notification from the Shell's default menu implementation. For example, the default menu implementation calls [DFM_MERGECONTEXTMENU](https://learn.microsoft.com/windows/desktop/shell/registering-control-panel-items) to allow the implementer of **IContextMenuCB::CallBack** to remove, add, or disable context menu items in this callback. Use one of the following notifications.

|  |
| --- |
| [DFM_MERGECONTEXTMENU](https://learn.microsoft.com/windows/win32/shell/dfm-mergecontextmenu) |
| [DFM_INVOKECOMMAND](https://learn.microsoft.com/windows/win32/shell/dfm-invokecommand) |
| [DFM_GETHELPTEXT](https://learn.microsoft.com/windows/win32/shell/dfm-gethelptext) |
| [DFM_GETHELPTEXTW](https://learn.microsoft.com/windows/win32/shell/dfm-gethelptextw) |
| [DFM_WM_MEASUREITEM](https://learn.microsoft.com/windows/win32/shell/dfm-wm-measureitem) |
| [DFM_WM_DRAWITEM](https://learn.microsoft.com/windows/win32/shell/dfm-wm-drawitem) |
| [DFM_WM_INITMENUPOPUP](https://learn.microsoft.com/windows/win32/shell/dfm-wm-initmenupopup) |
| [DFM_VALIDATECMD](https://learn.microsoft.com/windows/win32/shell/dfm-validatecmd) |
| [DFM_INVOKECOMMANDEX](https://learn.microsoft.com/windows/win32/shell/dfm-invokecommandex) |
| [DFM_MAPCOMMANDNAME](https://learn.microsoft.com/windows/win32/shell/dfm-mapcommandname) |
| [DFM_GETDEFSTATICID](https://learn.microsoft.com/windows/win32/shell/dfm-getdefstaticid) |
| [DFM_GETVERB](https://learn.microsoft.com/windows/win32/shell/dfm-getverb) |
| [DFM_MERGECONTEXTMENU_BOTTOM](https://learn.microsoft.com/windows/win32/shell/dfm-mergecontextmenu-bottom) |

### `wParam` [in]

Type: **WPARAM**

Data specific to the notification specified in *uMsg*. See the individual notification page for specific requirements.

### `lParam` [in]

Type: **LPARAM**

Data specific to the notification specified in *uMsg*. See the individual notification page for specific requirements.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Creating Context Menu Handlers](https://learn.microsoft.com/windows/desktop/shell/context-menu-handlers)

[IContextMenuCB](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenucb)