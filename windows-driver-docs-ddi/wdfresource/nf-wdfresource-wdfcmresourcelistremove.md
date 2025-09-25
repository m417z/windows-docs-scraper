# WdfCmResourceListRemove function

## Description

[Applies to KMDF only]

The **WdfCmResourceListRemove** method removes a resource descriptor from a specified resource list.

## Parameters

### `List` [in]

A handle to a framework resource-list object that represents a list of hardware resources for a device.

### `Index` [in]

A zero-based value that is used as an index into the resource list that *List* specifies.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfCmResourceListRemove** method removes the resource descriptor that is associated with the index value that the *Index* parameter specifies.

When **WdfCmResourceListRemove** removes the resource descriptor that has the index value *n*, the index value of the next resource descriptor changes from *n*+1 to *n*.

For more information about resource lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example removes the third resource descriptor from the raw and translated lists of hardware resources that an [EvtDeviceRemoveAddedResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_remove_added_resources) callback function receives.

```cpp
NTSTATUS
MyEvtDeviceRemoveAddedResources(
    WDFDEVICE Device,
    WDFCMRESLIST ResourcesRaw,
    WDFCMRESLIST ResourcesTranslated
    )
{
...
    WdfCmResourceListRemove(
                            ResourcesRaw,
                            2
                            );
    WdfCmResourceListRemove(
                            ResourcesTranslated,
                            2
                            );
...

}
```

## See also

[WdfCmResourceListRemoveByDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistremovebydescriptor)