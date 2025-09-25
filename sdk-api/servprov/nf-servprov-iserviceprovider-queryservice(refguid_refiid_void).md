## Description

## Parameters

Acts as the factory method for any services exposed through an implementation of [IServiceProvider](https://learn.microsoft.com/windows/win32/api/servprov/nn-servprov-iserviceprovider). Accepts a CLSID parameter.

### `guidService`

The unique identifier of the service (an SID).

### `riid`

The unique identifier of the interface that the caller wants to receive for the service.

### `ppvObject`

The address of the caller-allocated variable to receive the interface pointer of the service on successful return from this function. The caller becomes responsible for calling [Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) through this interface pointer when the service is no longer required.

## Return value

S_OK on success.

## Remarks

**QueryService** creates or accesses the implementation of the service identified with guidService. In ppv, it returns the address of the interface that is specified by riid.

## See also