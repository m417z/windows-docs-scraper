# IAppDomainHelper::DoCallback

## Description

Switches into a given application domain (which the calling object must be bound to), executes the supplied callback function in that application domain, and then returns to the original application domain.

## Parameters

### `pUnkAD` [in]

Reference to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the application domain that you want to switch to. The object calling **DoCallback** must be bound to that application domain.

### `__MIDL__IAppDomainHelper0001`

Reference to the callback function. This function is executed in the application domain that you switched to. The parameter of this function, *pv*, comes from the *pPool* parameter, which is defined next.

### `pPool` [in]

This parameter is used to provide any data that the callback function might need.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IAppDomainHelper](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iappdomainhelper)