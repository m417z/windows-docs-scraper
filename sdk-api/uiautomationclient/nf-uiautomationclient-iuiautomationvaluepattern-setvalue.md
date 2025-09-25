# IUIAutomationValuePattern::SetValue

## Description

Sets the value of the element.

## Parameters

### `val` [in]

Type: **BSTR**

The value to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [CurrentIsEnabled](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-get_currentisenabled) property must be **TRUE**, and the [IUIAutomationValuePattern::CurrentIsReadOnly](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationvaluepattern-get_currentisreadonly) property must be **FALSE**.