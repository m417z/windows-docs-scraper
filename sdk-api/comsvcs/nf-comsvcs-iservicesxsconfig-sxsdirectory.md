# IServiceSxsConfig::SxsDirectory

## Description

Sets the directory for the side-by-side assembly for the enclosed work.

## Parameters

### `szSxsDirectory` [in]

The name of the directory for the side-by-side assembly that is to be used for the enclosed work.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

This method must be called if a new side-by-side assembly domain is created using the call to [SxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicesxsconfig-sxsconfig).

## See also

[IServiceSxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicesxsconfig)