# IRawElementProviderHwndOverride::GetOverrideProviderForHwnd

## Description

Gets a UI Automation provider for the specified element.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The window handle of the element.

### `pRetVal` [out, retval]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

Receives a pointer to the new provider for the specified window, or **NULL** if the provider is not being overridden.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by fragment roots that contain window-based child elements.
By default, controls hosted in windows are served by default providers in addition to any custom providers.
The default providers treat all windows within a parent window as siblings. If you want to restructure the UI Automation
tree so that one window-based control is seen as a child of another, you must override the default provider by implementing
this method on the fragment root. The returned provider can supply additional properties or override properties of the
specified component.

The returned provider must be part of the fragment tree. It can supply additional properties or
override properties of the specified component.

If the returned provider implements [IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment),
the provider should be part of the fragment's tree and be reachable by navigating from the fragment's root.

## See also

[IRawElementProviderHwndOverride](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderhwndoverride)