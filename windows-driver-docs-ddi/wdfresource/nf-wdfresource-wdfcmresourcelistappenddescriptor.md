# WdfCmResourceListAppendDescriptor function

## Description

[Applies to KMDF only]

The **WdfCmResourceListAppendDescriptor** method adds a resource descriptor to the end of a specified resource list.

## Parameters

### `List` [in]

A handle to a framework resource-list object that represents a list of hardware resources for a device.

### `Descriptor` [in]

A pointer to a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes a hardware resource.

## Return value

**WdfCmResourceListAppendDescriptor** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_ACCESS_DENIED** | The driver was not allowed to add descriptors to the logical configuration that the *List* parameter specified. For example, the driver could not modify the logical configuration that its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) or [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function received. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate space to store the descriptor that the *Descriptor* parameter specified. |

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The framework copies the contents of the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure into internal storage, so the driver routine that calls **WdfCmResourceListAppendDescriptor** can allocate the structure locally. After the driver calls **WdfCmResourceListAppendDescriptor** it can reuse the **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure.

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

    status = WdfCmResourceListAppendDescriptor(
                                               Resources,
                                               &newDescriptor
                                               );
...

}
```

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)

[EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)

[EvtDeviceResourcesQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resources_query)

[WdfCmResourceListInsertDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfcmresourcelistinsertdescriptor)