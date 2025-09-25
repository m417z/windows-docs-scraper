# IUIAutomationMultipleViewPattern::GetViewName

## Description

Retrieves the name of a control-specific view.

## Parameters

### `view` [in]

Type: **int**

The identifier of the view.

### `name` [out, retval]

Type: **BSTR***

Receives a pointer to a localized view name.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.