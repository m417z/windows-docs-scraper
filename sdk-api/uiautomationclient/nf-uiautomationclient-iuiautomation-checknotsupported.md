# IUIAutomation::CheckNotSupported

## Description

Checks a provided [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to see if it contains the Not Supported identifier.

## Parameters

### `value` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)**

The value to check.

### `isNotSupported` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Receives **TRUE** if the provided [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) contains the Not Supported identifier, or **FALSE** otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After retrieving a property for a UI Automation element, call this method to determine whether the element supports the retrieved property. **CheckNotSupported** is typically called after calling a property retrieving method such as [GetCurrentPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpropertyvalue).

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomation::ReservedNotSupportedValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-get_reservednotsupportedvalue)