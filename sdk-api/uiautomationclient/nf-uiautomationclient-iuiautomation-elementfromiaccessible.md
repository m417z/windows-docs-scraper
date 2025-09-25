# IUIAutomation::ElementFromIAccessible

## Description

Retrieves a UI Automation element for the specified accessible object from a Microsoft Active Accessibility server.

## Parameters

### `accessible` [in]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)***

A pointer to the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface of the accessible object.

### `childId` [in]

Type: **int**

The child ID of the accessible object.

### `element` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the UI Automation element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method enables UI Automation clients to get [IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement) interfaces for accessible objects implemented by a Microsoft Active Accessibility server.

This method may fail if the server implements UI Automation provider interfaces alongside Microsoft Active Accessibility support.

The method returns E_INVALIDARG if the underlying implementation of the Microsoft UI Automation element is not a native Microsoft Active Accessibility server; that is, if a client attempts to retrieve the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface for an element originally supported by a proxy object from Oleacc.dll, or by the UIA-to-MSAA Bridge.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomation::ElementFromHandleBuildCache](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-elementfromhandlebuildcache)