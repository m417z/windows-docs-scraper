# IAutoComplete::Enable

## Description

Enables or disables autocompletion.

## Parameters

### `fEnable` [in]

Type: **BOOL**

A value that is set to **TRUE** to enable autocompletion, or **FALSE** to disable it.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error value otherwise.

## Remarks

Autocompletion is enabled by default. Applications need only to call this method to disable autocompletion or to reenable it if it has been disabled.

## See also

[IAutoComplete](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-iautocomplete)