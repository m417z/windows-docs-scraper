# IDirectInputJoyConfig8::QueryInterface

## Description

The **IDirectInputJoyConfig8::QueryInterface**  method determines whether the DirectInputJoyConfig object supports a particular COM interface. If it does, the system increases the reference count for the object by 1, and the application can begin using that interface immediately. This method is part of the **IUnknown** interface inherited by DirectInputJoyConfig.

## Parameters

### `riid`

Reference identifier of the interface being requested.

### `ppvObj`

Address of a pointer to be filled with the interface pointer if the query is successful.

## Return value

Returns DI_OK if successful; otherwise, returns E_NOINTERFACE.

## Remarks

When the application no longer needs to use the interface obtained by calling this method, it must call the **Release** method for that interface to free it.