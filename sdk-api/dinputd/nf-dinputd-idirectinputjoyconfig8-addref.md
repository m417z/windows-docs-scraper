# IDirectInputJoyConfig8::AddRef

## Description

The **IDirectInputJoyConfig8::AddRef** method increases the reference count of the DirectInputJoyConfig object by 1. This method is part of the **IUnknown** interface inherited by DirectInputJoyConfig.

## Return value

Returns the new reference count of the object.

## Remarks

When the DirectInputJoyConfig object is created, its reference count should be set to 1. Every time an application obtains an interface to the object or calls the **AddRef** method, the object's reference count is increased by 1. The application uses the **Release** method to decrease the reference count of the object by 1.