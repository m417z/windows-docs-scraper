# ICheckSxsConfig::IsSameSxsConfig

## Description

Determines whether the side-by-side assembly has the specified configuration.

## Parameters

### `wszSxsName` [in]

A text string that contains the file name of the side-by-side assembly. The proper extension is added automatically.

### `wszSxsDirectory` [in]

A text string that contains the directory of the side-by-side assembly.

### `wszSxsAppName` [in]

A text string that contains the name of the application domain.

## Return value

This method can return the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The current side-by-side assembly has the specified configuration. |
| **E_FAIL** | The current side-by-side assembly does not have the specified configuration. |

## See also

[ICheckSxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ichecksxsconfig)