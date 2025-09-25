# IUIAutomationElement::GetCachedPropertyValueEx

## Description

Retrieves a property value from the cache for this UI Automation element, optionally ignoring any default value.

## Parameters

### `propertyId` [in]

Type: **PROPERTYID**

The identifier of the property. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `ignoreDefaultValue` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that specifies whether a default value should be ignored if the specified property is not supported: **TRUE** if the default value is not to be returned, or **FALSE** if it is to be returned.

### `retVal` [out, retval]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)***

Receives the value of the property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method retrieves the specified property from the cache for the UI Automation element. To retrieve the current property, call [IUIAutomationElement::GetCurrentPropertyValueEx](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpropertyvalueex).

Passing **FALSE** in the *ignoreDefaultValue* parameter is equivalent to calling [IUIAutomationElement::GetCachedPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpropertyvalue).

If the Microsoft UI Automation provider for the element itself supports the property, the value of the property is returned. Otherwise, if *ignoreDefaultValue* is **FALSE**, a default value specified by UI Automation is returned.

This method returns a failure code if the requested property was not previously cached.

UI Automation properties of the **double** type support Not a Number (NaN) values. When retrieving a property of the **double** type, a client can use the [_isnan](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa298428(v=vs.60)) function to determine whether the property is a NaN value.

## See also

**Conceptual**

[GetCachedPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpropertyvalue)

[GetCurrentPropertyValueEx](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpropertyvalueex)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**

[UI Automation Properties Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-propertiesoverview)