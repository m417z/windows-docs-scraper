# EVT_WDF_DEVICE_RESOURCE_REQUIREMENTS_QUERY callback function

## Description

[Applies to KMDF only]

A bus driver's *EvtDeviceResourceRequirementsQuery* event callback function creates a resource requirements list that represents the device's required hardware resources.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `IoResourceRequirementsList` [in]

A handle to a framework resource-requirements-list object that represents an empty resource requirements list.

## Return value

If the driver did not encounter any errors, it must return STATUS_SUCCESS (whether or not it specifies any required hardware resource). If the driver encounters errors, it must return an NTSTATUS value that [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) evaluates as **FALSE**.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

Framework-based bus drivers can provide an *EvtDeviceResourceRequirementsQuery* callback function. To register this callback function, bus drivers call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

The framework calls the bus driver's *EvtDeviceResourceRequirementsQuery* callback function to obtain a [resource requirements list](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources) for the device.

The driver must populate the supplied resource-requirements-list object with logical configurations of hardware resources that will allow the device to operate properly.

To create a resource requirements list, the driver calls [framework resource-range-list object methods](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/), which add resource descriptors to logical configurations, and framework resource-requirements-list object methods, which add logical configurations to the resource requirements list.

For more information about hardware resources and creating resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

If a driver is running on an operating system version that is earlier than Windows 7, a bus driver can use *EvtDeviceResourceRequirementsQuery* to [set a device property](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdevicepropertydata) on a child device prior to enumerating the child.

To [set a device property](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetdevicepropertydata) on Windows 7 or later, a bus driver can [provide a preprocess routine](https://learn.microsoft.com/windows-hardware/drivers/wdf/preprocessing-and-postprocessing-irps) for [IRP_MN_DEVICE_ENUMERATED](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-device-enumerated).

## See also

[EvtDeviceResourcesQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resources_query)