# WdfCmResourceListInsertDescriptor function

## Description

[Applies to KMDF only]

The **WdfCmResourceListInsertDescriptor** method inserts a resource descriptor into a specified resource list.

## Parameters

### `List` [in]

A handle to a framework resource-list object that represents a list of hardware resources for a device.

### `Descriptor` [in]

A pointer to an [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes a hardware resource.

### `Index` [in]

A zero-based value that is used as an index into the logical configuration that *List* specifies. To add a resource descriptor to the end of the resource list, specify WDF_INSERT_AT_END or the return value from [WdfCmResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistgetcount).

## Return value

**WdfCmResourceListInsertDescriptor** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver was not allowed to add descriptors to the logical configuration that the *List* parameter specified. For example, the driver could not modify the logical configuration that its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) or [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function received. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate space to store the descriptor that the *Descriptor* parameter points to. |
| **STATUS_ARRAY_BOUNDS_EXCEEDED** | The value that the *Index* parameter specified was too large. |

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfCmResourceListInsertDescriptor** method inserts the resource descriptor that *Descriptor* specifies into the resource list that *List* specifies, in front of the resource descriptor that *Index* value identifies.

To add a resource descriptor to the end of a resource list, specify WDF_INSERT_AT_END or the return value from [WdfCmResourceListGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistgetcount) as the *Index* value. Alternatively, use the [WdfCmResourceListAppendDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistappenddescriptor) method.

The framework copies the contents of the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure into internal storage, so the driver routine that calls **WdfCmResourceListInsertDescriptor** can allocate the structure locally. After the driver calls **WdfCmResourceListInsertDescriptor**, it can reuse the CM_PARTIAL_RESOURCE_DESCRIPTOR structure.

For more information about resource lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example adds a resource descriptor to the end of the resource list that an [EvtDeviceResourcesQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resources_query) callback function receives.

```cpp
NTSTATUS
PdoEvtDeviceResourcesQuery(
    IN WDFDEVICE  Device,
    IN WDFCMRESLIST  Resources
    )
{
    CM_PARTIAL_RESOURCE_DESCRIPTOR newDescriptor;
...
    newDescriptor.Type = CmResourceTypePort;
    newDescriptor.ShareDisposition = CmResourceShareDeviceExclusive;
    newDescriptor.Flags = CM_RESOURCE_PORT_IO|CM_RESOURCE_PORT_16_BIT_DECODE;
    newDescriptor.u.Port.Length = 1;
    newDescriptor.u.Port.Start = 0;

    status = WdfCmResourceListInsertDescriptor(
                                               Resources,
                                               &newDescriptor,
                                               WDF_INSERT_AT_END
                                               );
...

}
```

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)

[EvtDeviceResourcesQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resources_query)

[WdfCmResourceListAppendDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistappenddescriptor)