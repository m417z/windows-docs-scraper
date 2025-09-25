# IServiceSxsConfig::SxsName

## Description

Sets the file name of the side-by-side assembly for the enclosed work.

## Parameters

### `szSxsName` [in]

The file name for the side-by-side assembly.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

The appropriate file name extension will be added to the *szSxsName* parameter. A default file name is used if this method is not called.

## See also

[IServiceSxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicesxsconfig)