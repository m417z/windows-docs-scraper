# UiaReturnRawElementProvider function

## Description

Gets an interface to the UI Automation provider for a window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle of the window containing the element served by the provider.

### `wParam` [in]

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The *wParam* argument of the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message.

### `lParam` [in]

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The *lParam* argument of the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message.

### `el` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The UI Automation provider.

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The key for the client process to connect to the server process through UI Automation.

This function returns zero when it is used to notify UI Automation that it is safe to remove the provider raised-event map. For more information, see Remarks.

## Remarks

This function is called by a control when it receives the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message, to provide UI Automation with the UI Automation provider for the control. The control should pass the *wParam* and *lParam* parameters to the **UiaReturnRawElementProvider** function without filtering them first, because filtering can cause problems with Microsoft Active Accessibility clients. The control's window procedure should return the result of calling **UiaReturnRawElementProvider**.

When Microsoft Active Accessibility clients are listening to events raised by a UI Automation provider, UI Automation maintains a map of the providers that have raised events. When the Microsoft Active Accessibility clients request further information, UI Automation uses the map to route the requests to the appropriate providers. When a window that previously returned providers has been destroyed, you should notify UI Automation by calling the **UiaReturnRawElementProvider** function as follows: `UiaReturnRawElementProvider(hwnd, 0, 0, NULL)`. This call tells UI Automation that it can safely remove all map entries that refer to the specified window. This call can save memory because it releases references to the providers being held by the raised-event map. The function returns zero when called with these special parameters. Microsoft recommends making this call from the [WM_DESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-destroy) message handler of the window that returns the UI Automation providers.