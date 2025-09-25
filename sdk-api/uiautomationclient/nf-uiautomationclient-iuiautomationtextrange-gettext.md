# IUIAutomationTextRange::GetText

## Description

Returns the plain text of the text range.

## Parameters

### `maxLength` [in]

Type: **int**

The maximum length of the string to return, or -1 if no limit is required.

### `text` [out, retval]

Type: **BSTR***

Receives a pointer to the string, possibly truncated at the specified *maxLength*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)