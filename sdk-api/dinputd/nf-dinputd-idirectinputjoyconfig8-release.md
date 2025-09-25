# IDirectInputJoyConfig8::Release

## Description

The **IDirectInputJoyConfig8::Release**  method decreases the reference count of the DirectInputJoyConfig object by 1. This method is part of the **IUnknown** interface inherited by DirectInputJoyConfig.

## Return value

Returns the new reference count of the object.

## Remarks

The DirectInputJoyConfig object deallocates itself when its reference count reaches 0. Use the [IDirectInputJoyConfig8::AddRef](https://learn.microsoft.com/windows/desktop/api/dinputd/nf-dinputd-idirectinputjoyconfig8-addref) method to increase the reference count of the object by 1.