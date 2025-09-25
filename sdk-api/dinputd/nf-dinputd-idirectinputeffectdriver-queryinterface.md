# IDirectInputEffectDriver::QueryInterface

## Description

The **IDirectInputEffectDriver::QueryInterface**  method determines whether the DirectInputEffectDriver object supports a particular COM interface. If it does, the system increases the reference count for the object by 1, and the application can begin using that interface immediately. This method is part of the **IUnknown** interface inherited by DirectInputEffectDriver.

## Parameters

### `riid`

Reference identifier of the interface being requested.

### `ppvObj`

Address of a pointer to be filled with the interface pointer if the query is successful.

## Return value

Returns S_OK if the interface is supported; otherwise, returns E_NOINTERFACE.

## Remarks

When the application no longer needs to use the interface retrieved by a call to this method, it must call the **Release** method for that interface to free it.