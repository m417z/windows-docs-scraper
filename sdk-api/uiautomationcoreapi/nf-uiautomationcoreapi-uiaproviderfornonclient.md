# UiaProviderForNonClient function

## Description

Gets the provider for the entire non-client area of a window, or for a control in the non-client area of a window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The window that owns the non-client area or non-client control.

### `idObject` [in]

Type: **long**

The object identifier of the non-client control, or [OBJID_WINDOW](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers) for the entire non-client area. For a list of possible values, see **Object Identifiers**.

### `idChild` [in]

Type: **long**

The child identifier of the non-client control.

### `ppProvider` [out]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

Receives the provider for the non-client area or non-client control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

This function returns the default Microsoft UI Automation provider for the non-client area of a window. UI Automation supports the non-client area without any explicit help from the window. You can override and customize the support by using the [IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple) interface that is retrieved by this function.

This function is particularly useful when you use it with the [ProviderOptions_RefuseNonClientSupport](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-provideroptions) flag, which disables the UI Automation default provider for the non-client area so that the window can supply its own provider.

The supported object IDs for controls in the non-client area include [OBJID_WINDOW](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers)[, OBJID_VSCROLL](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), [OBJID_HSCROLL](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), [OBJID_TITLEBAR](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), [OBJID_MENU](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), and [OBJID_SIZEGRIP](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers). For **OBJID_TITLEBAR**, use the child ID to distinguish between the entire title bar and the buttons that it contains.

## See also

[Functions for Providers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-functions)