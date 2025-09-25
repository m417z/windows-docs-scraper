# IUIAutomationElement::GetCurrentPattern

## Description

Retrieves the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the specified control pattern on this UI Automation element.

## Parameters

### `patternId` [in]

Type: **PATTERNID**

The identifier of the control pattern. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

### `patternObject` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method gets the specified control pattern based on its availability at the time of the call.

For some forms of UI, this method will incur cross-process performance overhead. Applications can reduce overhead by caching control patterns and then retrieving them by using [IUIAutomationElement::GetCachedPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpattern).

## See also

**Conceptual**

[GetCachedPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpattern)

[GetCurrentPatternAs](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpatternas)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**

[UI Automation Control Patterns Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpatternsoverview)