# IInputPaneInterop::GetForWindow

## Description

Gets an instance of an [InputPane](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.inputpane) object for the specified window.

## Parameters

### `appWindow` [in]

The top-level ([GA_ROOT](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getancestor)) window for which you want to get the [InputPane](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.inputpane) object.

### `riid` [in]

The interface identifier for the interface that you want to get in the *inputPane* parameter. This value is typically **IID_IInputPane** or **IID_IInputPane2**, as defined in Windows.UI.ViewManagement.h.

### `inputPane` [out, retval]

The [InputPane](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.inputpane) object for the window that the *appWindow* parameter specifies. This parameter is typically a pointer to an **IInputPane** or **IInputPane2** interface, as defined in Windows.UI.ViewManagement.idl.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IInputPaneInterop](https://learn.microsoft.com/windows/desktop/api/inputpaneinterop/nn-inputpaneinterop-iinputpaneinterop)

[InputPane](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.inputpane)