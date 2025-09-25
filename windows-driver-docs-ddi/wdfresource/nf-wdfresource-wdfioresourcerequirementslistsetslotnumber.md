# WdfIoResourceRequirementsListSetSlotNumber function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListSetSlotNumber** method assigns a slot number to a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `SlotNumber` [in]

A value that identifies the bus slot number to which the device is connected.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Your driver must provide a slot number if your device does not support Plug and Play (PnP).

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example shows how an [EvtDeviceResourceRequirementsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resource_requirements_query) callback function for a nonPnP device calls **WdfIoResourceRequirementsListSetSlotNumber** to assign slot 0 to a device.

```cpp
NTSTATUS
Example_EvtDeviceResourceRequirementsQuery(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST Requirements
    )
{
...
    WdfIoResourceRequirementsListSetSlotNumber(
                                               Requirements,
                                               0
                                               );
...
}
```