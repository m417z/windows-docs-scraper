# WdfIoResourceRequirementsListRemoveByIoResList function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListRemoveByIoResList** method removes a [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) from a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `IoResList` [in]

A handle to a framework resource-range-list object that represents the logical configuration to be removed from the resource requirements list that *RequirementsList* specifies.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfIoResourceRequirementsListRemoveByIoResList** method removes the logical configuration that is associated with the handle that the *IoResList* parameter specifies.

When **WdfIoResourceRequirementsListRemoveByIoResList** removes the logical configuration that has the index value *n*, the index value of the next logical configuration changes from *n*+1 to *n*.

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example searches the logical configurations in a device's resource requirements list to find a configuration that contains a specific port address. If the example finds that configuration, it removes the configuration.

```cpp
NTSTATUS
Example_EvtDeviceFilterRemoveResourceRequirements(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST RequirementsList
    )
{
    ULONG i, j, reqCount, resCount;
    BOOLEAN descriptorFound = FALSE;

    //
    // Obtain the number of logical configurations.
    //
    reqCount = WdfIoResourceRequirementsListGetCount(RequirementsList);

    //
    // Search each logical configuration.
    //
    for (i = 0; i < reqCount; i++) {
        WDFIORESLIST reslist;

        if (descriptorFound) {
            break;
        }
        reslist = WdfIoResourceRequirementsListGetIoResList(RequirementsList, i);

        //
        // Get the number of resource descriptors that
        // are in this logical configuration.
        //
        resCount = WdfIoResourceListGetCount(reslist);

        for (j = 0; j < resCount; j++) {
            PIO_RESOURCE_DESCRIPTOR descriptor;

            //
            // Get the next resource descriptor.
            //
            descriptor = WdfIoResourceListGetDescriptor(
                                 reslist,
                                 j
                                 );

            //
            // Stop if this descriptor is the port descriptor
            // that we're looking for.
            //
            if (descriptor->Type == CmResourceTypePort) {
                if ((descriptor->u.Port.MinimumAddress) == PORT_RANGE_A) {
                    WdfIoResourceRequirementsListRemoveByIoResList(
                                 RequirementsList,
                                 reslist
                                 );
                    descriptorFound = TRUE;
                    break;
            }
        }
    }
...
}
```

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[WdfIoResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistgetcount)

[WdfIoResourceListGetDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistgetdescriptor)

[WdfIoResourceRequirementsListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetcount)

[WdfIoResourceRequirementsListGetIoResList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistgetioreslist)

[WdfIoResourceRequirementsListRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcerequirementslistremove)