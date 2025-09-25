# WdfCmResourceListRemoveByDescriptor function

## Description

[Applies to KMDF only]

The **WdfCmResourceListRemoveByDescriptor** method removes a specified resource descriptor from a specified resource list.

## Parameters

### `List` [in]

A handle to a framework resource-list object that represents a list of hardware resources for a device.

### `Descriptor` [in]

A pointer to an [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes a hardware resource.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfCmResourceListRemoveByDescriptor** method removes the resource descriptor that matches the *Descriptor* parameter. To find a match, the method compares the specified resource descriptor with the resource descriptors in the logical configuration, byte for byte.

When **WdfCmResourceListRemoveByDescriptor** removes the resource descriptor that has the index value *n*, the index value of the next resource descriptor changes from *n*+1 to *n*.

For more information about resource lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example searches for port resource descriptors in a device's resource lists. For each port resource that the example finds, it checks to see if the port address is within a certain range. If the port address is outside of the range, the example removes the descriptor from both the [raw and translated resource lists](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources).

```cpp
NTSTATUS
MyEvtDeviceRemoveAddedResources(
    WDFDEVICE Device,
    WDFCMRESLIST ResourcesRaw,
    WDFCMRESLIST ResourcesTranslated
    )
{
    ULONG i, count;

    pDevExt = DeviceGetExtension(Device);
    count = WdfCmResourceListGetCount(ResourcesRaw);

    for (i = 0; i < count; i++) {
        PCM_PARTIAL_RESOURCE_DESCRIPTOR descriptor;

        descriptor = WdfCmResourceListGetDescriptor(
                                                    ResourcesRaw,
                                                    i
                                                    );

        if (descriptor->Type != CmResourceTypePort) {
            continue;
        }

        if (descriptor->u.Port.Start.QuadPart < pDevExt->Ranges[0].MinAddress ||
             descriptor->u.Port.Start.QuadPart > pDevExt->Ranges[0].MaxAddress)
        {
            WdfCmResourceListRemoveByDescriptor(
                                                ResourcesRaw,
                                                descriptor
                                                );

            // The descriptor may not be the same in the raw and translated resource lists, so use an index for the second removal

            WdfCmResourceListRemove(
                                                ResourcesTranslated,
                                                i
                                                );
            break;
        }
    }
}
```

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[WdfCmResourceListRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistremove)