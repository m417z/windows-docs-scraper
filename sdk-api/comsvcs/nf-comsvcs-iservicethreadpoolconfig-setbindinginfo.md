# IServiceThreadPoolConfig::SetBindingInfo

## Description

Binds all work submitted by the activity to a single single-threaded apartment.

## Parameters

### `binding` [in]

A value from the [CSC_Binding](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_binding) enumeration.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## See also

[IServiceThreadPoolConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicethreadpoolconfig)