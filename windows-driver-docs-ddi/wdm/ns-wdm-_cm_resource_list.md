## Description

The **CM_RESOURCE_LIST** structure specifies all of the system hardware resources assigned to a device.

## Members

### `Count`

The number of full resource descriptors that are specified by this **CM_RESOURCE_LIST** structure. The **List** member is the header for the first full resource descriptor. For WDM drivers, **Count** is always 1.

### `List`

The [**CM_FULL_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_full_resource_descriptor) structure that serves as the header for the first full resource descriptor. If the **CM_RESOURCE_LIST** structure contains more than one full resource descriptor, the second full resource descriptor immediately follows the first in memory, and so on. The size of each full resource descriptor depends on the length of the [**CM_PARTIAL_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) array that it contains. For more information, see the following Remarks section.

## Remarks

This structure describes the assignment of hardware resources to a device. An [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRP uses this structure to specify the resources that the Plug and Play manager assigns to a device. Drivers for legacy devices use this structure to pass their resource requirements to the [IoReportResourceForDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportresourcefordetection) routine. For more information about hardware resource allocation, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

The **CM_RESOURCE_LIST** structure is a header for a larger data structure, of variable size, that contains one or more full resource descriptors. All of the data in this larger structure occupies a contiguous block of memory. Each full resource descriptor occupies a subblock within the larger block.

A full resource descriptor begins with a [**CM_FULL_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_full_resource_descriptor) structure, which serves as a header for an array of [**CM_PARTIAL_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structures. The length of this array determines the size of the full resource descriptor. The last member in the **CM_FULL_RESOURCE_DESCRIPTOR** structure is a [**CM_PARTIAL_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list) structure that contains, as its last member, the first element in this array. If the array contains more than one element, the remaining elements immediately follow, in memory, the end of the **CM_PARTIAL_RESOURCE_LIST** structure, which is also the end of the **CM_FULL_RESOURCE_DESCRIPTOR** structure.

Driver code can use pointer arithmetic to step from one full resource descriptor to the next. For example, if a parameter named *list* is a pointer to the **CM_FULL_RESOURCE_DESCRIPTOR** structure at the start of one full resource descriptor, *list* can be updated to point to the start of the next full resource descriptor as follows:

```cpp
list = (PCM_FULL_RESOURCE_DESCRIPTOR)(list->PartialResourceList.PartialDescriptors +
                                        list->PartialResourceList.Count);
```

In this example, `list->PartialResourceList.PartialDescriptors` is a pointer to the start of the **CM_PARTIAL_RESOURCE_DESCRIPTOR** array, and `list->PartialResourceList.Count` is the number of elements in the array. For more information about the **PartialDescriptors** and **Count** members, see [**CM_PARTIAL_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list).

### Examples

All PnP drivers must handle [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRPs. Typically, a driver's handler for this IRP walks the lists of assigned resources that are pointed to by the **Parameters.StartDevice.AllocatedResources** and **Parameters.StartDevice.AllocatedResourcesTranslated** members of the [**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure in the IRP. The following code example contains a function—named GetAssignedResources—that is called in the handler to walk each list. This function verifies that the required resources are specified in the list, and configures the device to use the resources.

The GetAssignedResources function returns **TRUE** if it succeeds. Otherwise, it returns **FALSE** (probably from the **switch** statement, although the details are omitted to simplify the code example).

```cpp
/* Process the assigned hardware resources. */

BOOLEAN GetAssignedResources(PCM_RESOURCE_LIST reslist)
{
    PCM_FULL_RESOURCE_DESCRIPTOR list;

    list = reslist->List;

    for (int ix = 0; ix < reslist->Count; ++ix)
    {
        /* Process resources in CM_FULL_RESOURCE_DESCRIPTOR block number ix. */

        for (int jx = 0; jx < list->PartialResourceList.Count; ++jx)
        {
            PCM_PARTIAL_RESOURCE_DESCRIPTOR desc;

            desc = list->PartialResourceList.PartialDescriptors + jx;

            switch (desc->Type)
            {
                /* Process element jx in PartialDescriptors array. */

                ...

            }
        }

        /* Advance to next CM_FULL_RESOURCE_DESCRIPTOR block in memory. */

        list = (PCM_FULL_RESOURCE_DESCRIPTOR)(list->PartialResourceList.PartialDescriptors +
                                              list->PartialResourceList.Count);
    }

    return TRUE;
}
```

## See also

[**CM_FLOPPY_DEVICE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_floppy_device_data)

[**CM_FULL_RESOURCE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_full_resource_descriptor)

[**CM_KEYBOARD_DEVICE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_keyboard_device_data)

[**CM_PARTIAL_RESOURCE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list)

[**CM_RESOURCE_LIST**]()

[**CM_SCSI_DEVICE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_scsi_device_data)

[**CM_SERIAL_DEVICE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_serial_device_data)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty)

[IoReportResourceForDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportresourcefordetection)