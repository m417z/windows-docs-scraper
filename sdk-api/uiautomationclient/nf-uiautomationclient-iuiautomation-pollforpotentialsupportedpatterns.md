# IUIAutomation::PollForPotentialSupportedPatterns

## Description

Retrieves the control patterns that might be supported on a UI Automation element.

## Parameters

### `pElement` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

The address of the element to poll.

### `patternIds` [out]

Type: **SAFEARRAY(int)****

Receives a pointer to an array of control pattern identifiers.

### `patternNames` [out]

Type: **SAFEARRAY(BSTR)****

Receives a pointer to an array of control pattern names.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is intended only for use by Microsoft UI Automation tools that need to scan for properties. It is not intended to be used by UI Automation clients.

There is no guarantee that the element will support any particular control pattern when asked for it later.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[Custom Properties, Events, and Control Patterns](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-custompropertieseventscontrolpatterns)

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[PollForPotentialSupportedProperties](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-pollforpotentialsupportedproperties)

**Reference**