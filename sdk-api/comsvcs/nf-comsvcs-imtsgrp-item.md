# IMtsGrp::Item

## Description

Retrieves the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer for the specified package.

## Parameters

### `lIndex` [in]

The index containing running packages.

### `ppUnkDispatcher` [out]

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer, which can be used to access [IMtsEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsevents).

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## See also

[IMtsGrp](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsgrp)