# UrsIoResourceListAppendDescriptor function

## Description

Appends the specified resource descriptor to the specified I/O resource list object that maintains resource descriptors for the
host or function role.

## Parameters

### `IoResourceList` [in]

 A role's I/O resource list object to which the resource descriptor is appended. This object is allocated by the framework and passed to the client driver when the framework invokes the driver's [EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_device_filter_resource_requirements) implementation.

### `Descriptor` [in]

A pointer to IO_RESOURCE_DESCRIPTOR that contains the resource descriptor for the role.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

After the client driver calls [UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize), the framework allocates memory for the *resource requirements list*. When the USB dual-role class extension invokes the client driver's implementation of [EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_device_filter_resource_requirements), it passes a WDFIORESREQLIST handle to that requirements list along with URSIORESLIST handles for host and function role *resource lists*. In the implementation, the client driver is expected to enumerate through the requirements list and add the resource descriptor (if it wants to use that resource) to the resource list for each role.

To add a resource descriptors for a role, the driver calls **UrsIoResourceListAppendDescriptor** and specifies the descriptor and the resource list to which the resource must be added.

For a code example, see [EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_device_filter_resource_requirements).

For more information about resource requirements lists, see [Handling Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

## See also

[EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nc-ursdevice-evt_urs_device_filter_resource_requirements)

[UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize)