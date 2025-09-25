# IDirectInputEffectDriver::Release

## Description

The **IDirectInputEffectDriver::Release**  method decreases the reference count of the DirectInputEffectDriver object by 1. This method is part of the **IUnknown** interface inherited by DirectInputEffectDriver.

## Return value

Returns the new reference count of the object.

## Remarks

The DirectInputEffectDriver object deallocates itself when its reference count reaches 0. Use the **IDirectInputEffectDriver::AddRef** method to increase the reference count of the object by 1.