# IUIAutomationRegistrar::RegisterPattern

## Description

Registers a third-party control pattern.

## Parameters

### `pattern` [in]

Type: **[UIAutomationPatternInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiautomationpatterninfo)***

A pointer to a structure that contains information about the control pattern to register.

### `pPatternId` [out]

Type: **PATTERNID***

Receives the pattern identifier.

### `pPatternAvailablePropertyId` [out]

Type: **PROPERTYID***

Receives the property identifier for the pattern. This value can be used with UI Automation client methods to determine whether the element supports the new pattern. This is equivalent to values such as [UIA_IsInvokePatternAvailablePropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-control-pattern-availability-propids).

### `propertyIdCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of properties supported by the control pattern.

### `pPropertyIds` [out]

Type: **PROPERTYID***

Receives an array of identifiers for properties supported by the pattern.

### `eventIdCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of events supported by the control pattern.

### `pEventIds` [out]

Type: **EVENTID***

Receives an array of identifiers for events that are raised by the pattern.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The pattern, property, and event IDs retrieved by this method can be used in [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) implementations.

## See also

[IUIAutomationRegistrar](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationregistrar)