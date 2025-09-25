## Description

Specifies an owner window to be used by a Windows Runtime (WinRT) object that is used in a desktop app.

For info and code examples about this method, see [Display WinRT UI objects that depend on CoreWindow](https://learn.microsoft.com/windows/apps/develop/ui-input/display-ui-objects#winui-3-with-c). In addition to the types listed in that topic, [**Shell data object**](https://learn.microsoft.com/windows/win32/shell/dataobject) is also associated with this API.

## Parameters

### `hwnd` [in]

The handle of the window to be used as the owner window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also

* [IInitializeWithWindow interface](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iinitializewithwindow)
* [Display WinRT UI objects that depend on CoreWindow](https://learn.microsoft.com/windows/apps/develop/ui-input/display-ui-objects)