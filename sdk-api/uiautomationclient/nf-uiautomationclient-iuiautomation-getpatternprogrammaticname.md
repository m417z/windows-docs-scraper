# IUIAutomation::GetPatternProgrammaticName

## Description

Retrieves the registered programmatic name of a control pattern.

## Parameters

### `pattern` [in]

Type: **PATTERNID**

The identifier of the control pattern. For a list of control pattern IDs, see [Control Pattern Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-controlpattern-ids).

### `name` [out, retval]

Type: **BSTR***

Receives the registered programmatic name.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The programmatic name is intended for debugging and diagnostic purposes only. The string is not localized.

This property should not be used in string comparisons. To determine whether two control patterns are the same, compare the control pattern identifiers directly.