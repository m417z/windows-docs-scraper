# IUIAutomationTextRange::FindText

## Description

Retrieves a text range subset that contains the specified text.

## Parameters

### `text` [in]

Type: **BSTR**

The text to find.

### `backward` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the last occurring text range should be returned instead of the first; otherwise **FALSE**.

### `ignoreCase` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if case should be ignored; otherwise **FALSE**.

### `found` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Receives a pointer to the text range, or **NULL** if no match is found.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There is no differentiation between hidden and visible text.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)