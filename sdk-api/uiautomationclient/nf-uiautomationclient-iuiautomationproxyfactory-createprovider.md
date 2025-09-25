# IUIAutomationProxyFactory::CreateProvider

## Description

Creates a proxy object that provides Microsoft UI Automation support for a UI element.

## Parameters

### `hwnd` [in]

Type: **UIA_HWND**

The window handle of the UI element.

### `idObject` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The object ID. See Remarks.

### `idChild` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The child ID. See Remarks.

### `provider` [out, retval]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

Receives a pointer to the proxy object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *idObject* parameter is normally [OBJID_CLIENT](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), and *idChild* is normally CHILDID_SELF. However, when the method is called in response to a registered WinEvent, these values are from the event, specifying the subelement that raised the event.