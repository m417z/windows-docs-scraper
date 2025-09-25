# IUIAutomationSelectionPattern::GetCachedSelection

## Description

Retrieves the cached selected elements in the container.

## Parameters

### `retVal` [out, retval]

Type: **[IUIAutomationElementArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelementarray)****

Receives a pointer to the cached collection of selected elements. The default is an empty array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationSelectionPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationselectionpattern)