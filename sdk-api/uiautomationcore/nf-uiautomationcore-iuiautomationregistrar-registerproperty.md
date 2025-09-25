# IUIAutomationRegistrar::RegisterProperty

## Description

Registers a third-party property.

## Parameters

### `property` [in]

Type: **[UIAutomationPropertyInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationpropertyinfo)***

A pointer to a structure that contains information about the property to register.

### `propertyId` [out]

Type: **PropertyID***

Receives the property ID of the newly registered property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The property ID can be used in various property methods, including [GetCurrentPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpropertyvalue), and [CreatePropertyCondition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-createpropertycondition). The same value can be used as a WinEvent value for property change events in [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) implementations.

## See also

[IUIAutomationRegistrar](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationregistrar)