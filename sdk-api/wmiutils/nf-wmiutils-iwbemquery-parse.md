# IWbemQuery::Parse

## Description

The
**IWbemQuery::Parse** method parses a query string.

## Parameters

### `pszLang` [in]

Language of the query. Must be either "WQL" or "SQL" (case-sensitive). Any other value will result in the method failing and **WBEM_E_INVALID_PARAMETER** being returned.

### `pszQuery` [in]

Valid WQL or SQL WMI query.

### `uFlags` [in]

Reserved for future use. Must be 0 (zero).

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemQuery](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbemquery)