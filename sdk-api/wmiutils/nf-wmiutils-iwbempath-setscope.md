# IWbemPath::SetScope

## Description

The
**IWbemPath::SetScope** method sets a scope in the path based upon an index. The index is always 0 (zero) and the scope is the class or key portion of the path. This method also sets the class name.

## Parameters

### `uIndex` [in]

Index of the scope.

### `pszClass` [in]

Class name of the scope.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)