## Description

Creates a new instance of an object that implements [IPropertySetSerializer](https://learn.microsoft.com/uwp/api/windows.storage.streams.ipropertysetserializer).

## Parameters

### `ppPropertySetSerializer`

Recieves a pointer to the new instance of **IPropertySetSerializer**.

## Return value

S_OK on success.

## Remarks

The returned **IPropertySetSerializer** can be used to serialize and deserialize property
sets to and from buffers that are used within a process or passed between two running processes.
There is no guarantee that a serialized property set buffer can be deserialized
by another computer or by the same computer after a reboot.

## See also