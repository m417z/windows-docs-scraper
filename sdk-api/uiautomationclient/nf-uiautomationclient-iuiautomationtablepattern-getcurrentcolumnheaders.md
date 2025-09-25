# IUIAutomationTablePattern::GetCurrentColumnHeaders

## Description

Retrieves a collection of UI Automation elements representing all the column headers in a table.

## Parameters

### `retVal` [out, retval]

Type: **[IUIAutomationElementArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelementarray)****

Receives a pointer to the collection of column headers. The default is an empty array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationTablePattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtablepattern)

[IUIAutomationTablePattern::GetCurrentRowHeaders](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtablepattern-getcurrentrowheaders)