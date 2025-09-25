# WdfRegistryClose function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryClose** method closes the registry key that is associated with a specified framework registry-key object and then deletes the registry-key object.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After your driver has finished accessing a registry key, it must call **WdfRegistryClose** or [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete). Both of these methods close the registry key and delete the registry-key object.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example closes a registry key and deletes the registry-key object.

```cpp
WdfRegistryClose(Key);
```

## See also

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)