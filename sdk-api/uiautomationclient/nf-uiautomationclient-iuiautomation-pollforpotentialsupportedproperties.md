# IUIAutomation::PollForPotentialSupportedProperties

## Description

Retrieves the properties that might be supported on a UI Automation element.

## Parameters

### `pElement` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

The address of the UI Automation element to poll.

### `propertyIds` [out]

Type: **SAFEARRAY(int)****

Receives a pointer to an array of property identifiers. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `propertyNames` [out]

Type: **SAFEARRAY(BSTR)****

Receives a pointer to an array of property names.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is intended only for use by Microsoft UI Automation tools that need to scan for properties and control patterns. It is not intended to be used by UI Automation clients.

There is no guarantee that the element will support any particular property when asked for it later.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-custompropertieseventscontrolpatterns)

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[PollForPotentialSupportedPatterns](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-pollforpotentialsupportedpatterns)

**Reference**