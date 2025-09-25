# WdfIoResourceRequirementsListGetIoResList function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListGetIoResList** method returns a handle to the framework resource-range-list object that represents a specified [logical configuration](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) in a specified resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `Index` [in]

A zero-based value that is used as an index into the resource requirements list that *RequirementsList* specifies.

## Return value

**WdfIoResourceRequirementsListGetIoResList** returns a handle to the framework resource-range-list object that represents the logical configuration that the *Index* parameter identifies, if the index value is valid. Otherwise, the method returns **NULL**.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

The following code example searches a device's resource requirements list to find the first resource descriptor that describes an interrupt resource.

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
        reslist = WdfIoResourceRequirementsListGetIoResList(
                                          RequirementsList,
                                          i
                                          );

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
            // Stop if this descriptor is an interrupt descriptor.
            //
            if (descriptor->Type == CmResourceTypeInterrupt) {
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