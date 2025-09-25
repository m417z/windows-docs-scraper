# ContextInfo2::GetApplicationInstanceId

## Description

Retrieves the GUID of the application instance of the current object context.

This information is useful when using [COM+ Application Recycling](https://learn.microsoft.com/windows/desktop/cossdk/com--application-recycling), for example.

## Parameters

### `__MIDL__ContextInfo20002` [out]

A reference to the application instance identifier.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ContextInfo2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-contextinfo2)