# IDirectInputEffectDriver::AddRef

## Description

The **IDirectInputEffectDriver::AddRef**  method increases the reference count of the DirectInputEffectDriver object by 1. This method is part of the **IUnknown** interface inherited by DirectInputEffectDriver.

## Return value

Returns S_OK if successful; otherwise, returns an error code.

## Remarks

When the DirectInputEffectDriver object is created, its reference count should be set to 1. Each time an application obtains an interface to the object or calls the **AddRef** method, the object's reference count is increased by 1. The application uses the **Release** method to decrease the reference count of the object by 1.