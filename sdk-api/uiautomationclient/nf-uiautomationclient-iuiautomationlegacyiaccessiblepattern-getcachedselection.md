# IUIAutomationLegacyIAccessiblePattern::GetCachedSelection

## Description

Retrieves the cached Microsoft Active Accessibility property that identifies the selected children of this element.

## Parameters

### `pvarSelectedChildren` [out, retval]

Type: **[IUIAutomationElementArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelementarray)****

Receives a pointer to the cached collection of the selected child elements.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationLegacyIAccessiblePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationlegacyiaccessiblepattern)