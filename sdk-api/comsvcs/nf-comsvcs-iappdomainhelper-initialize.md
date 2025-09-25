# IAppDomainHelper::Initialize

## Description

Binds the calling object to the current application domain and provides a callback function for shutdown that is executed when the application domain is unloaded.

## Parameters

### `pUnkAD` [in]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the current application domain.

### `__MIDL__IAppDomainHelper0000`

Reference to the shutdown function that is executed when the application domain is unloaded. The parameter of this function, *pv*, comes from the *pPool* parameter, which is defined next.

### `pPool` [in]

This parameter is used to provide any data that the shutdown function might need.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IAppDomainHelper](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iappdomainhelper)