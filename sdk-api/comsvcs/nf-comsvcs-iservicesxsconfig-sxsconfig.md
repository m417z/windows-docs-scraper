# IServiceSxsConfig::SxsConfig

## Description

Configures the side-by-side assembly for the enclosed work.

## Parameters

### `scsConfig` [in]

A value from the [CSC_SxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_sxsconfig) enumeration.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

The [SxsDirectory](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicesxsconfig-sxsdirectory) method must be called if a new side-by-side assembly domain is created using a call to this method.

## See also

[IServiceSxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicesxsconfig)