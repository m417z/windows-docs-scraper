# IUIAutomationElement::GetCachedPatternAs

## Description

Retrieves the control pattern interface of the specified pattern from the cache of this UI Automation element.

## Parameters

### `patternId` [in]

Type: **PATTERNID**

The identifier of the control pattern. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*.

### `patternObject` [out]

Type: **void****

Receives the interface pointer requested in *riid*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.

## See also

**Conceptual**

[GetCachedPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpattern)

[GetCurrentPatternAs](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcurrentpatternas)

[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)

**Reference**

[UI Automation Control Patterns Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpatternsoverview)