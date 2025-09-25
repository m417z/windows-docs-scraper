# IUIAutomationLegacyIAccessiblePattern::GetIAccessible

## Description

Retrieves an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) object that corresponds to the Microsoft UI Automation element.

## Parameters

### `ppAccessible` [out, retval]

Type: **[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)****

Receives a pointer to an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface for the accessible object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns **NULL** if the underlying implementation of the UI Automation element is not a native Microsoft Active Accessibility server; that is, if a client attempts to retrieve the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface for an element originally supported by a proxy object from OLEACC.dll, or by the UIA-to-MSAA Bridge.

## See also

[IUIAutomationLegacyIAccessiblePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationlegacyiaccessiblepattern)