# IUIAutomationElement::GetCurrentPropertyValue

## Description

Retrieves the current value of a property for this UI Automation element.

## Parameters

### `propertyId` [in]

Type: **PROPERTYID**

The identifier of the property. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `retVal` [out, retval]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)***

Receives the value of the property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Microsoft UI Automation properties of the **double** type support Not a Number (NaN) values. When retrieving a property of the **double** type, a client can use the [_isnan](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa298428(v=vs.60)) function to determine whether the property is a NaN value.

## See also

**Conceptual**

[GetCachedPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpropertyvalue)

[GetCurrentPropertyValueEx](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpropertyvalueex)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**

[UI Automation Properties Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-propertiesoverview)