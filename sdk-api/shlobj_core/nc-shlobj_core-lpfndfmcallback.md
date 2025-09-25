# LPFNDFMCALLBACK callback function

## Description

[**LPFNDFMCALLBACK** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Defines the prototype for the callback function that receives messages from the Shell's default context menu implementation.

## Parameters

### `psf` [in, optional]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object the message applies to. This value can be **NULL**.

### `hwnd` [in, optional]

Type: **HWND**

The handle of the window that contains the view. This value can be **NULL**.

### `pdtobj` [in, optional]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) that represents the selection the context menu is based on. This value can be **NULL**.

### `uMsg`

Type: **UINT**

One of the following notifications.

| Notification | Usage |
| --- | --- |
| [DFM_MERGECONTEXTMENU](https://learn.microsoft.com/windows/desktop/shell/registering-control-panel-items) | Sent by the default context menu implementation to allow **LPFNDFMCALLBACK** to add items to the menu. |
| [DFM_INVOKECOMMAND](https://learn.microsoft.com/windows/desktop/shell/preview-handler-guidelines) | Sent by the default context menu implementation to request **LPFNDFMCALLBACK** to invoke a menu command. |
| [DFM_GETDEFSTATICID](https://learn.microsoft.com/windows/desktop/shell/library-ovw) | Sent by the default context menu implementation when the default menu command is being created, allowing an alternate choice to be made. |

### `wParam`

Type: **WPARAM**

Additional information. See the individual notification pages for specific requirements.

### `lParam`

Type: **LPARAM**

Additional information. See the individual notification pages for specific requirements.

## Return value

Type: **HRESULT**

Returns S_OK if the message was handled, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | The message was not handled. |