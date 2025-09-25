# WdfIoResourceRequirementsListSetInterfaceType function

## Description

[Applies to KMDF only]

The **WdfIoResourceRequirementsListSetInterfaceType** method assigns a bus type to a resource requirements list.

## Parameters

### `RequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `InterfaceType` [in]

An [INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type)-typed value that identifies the type of bus that the device is connected to.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Your driver must provide a bus type if your device does not support Plug and Play (PnP).

For more information about resource requirements lists, see [Hardware Resources for Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

#### Examples

The following code example shows how an [EvtDeviceResourceRequirementsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resource_requirements_query) callback function for a nonPnP device calls **WdfIoResourceRequirementsListSetInterfaceType** to assign a bus type to a device.

```cpp
NTSTATUS
Example_EvtDeviceResourceRequirementsQuery(
    IN WDFDEVICE Device,
    IN WDFIORESREQLIST Requirements
    )
{
...
    WdfIoResourceRequirementsListSetInterfaceType(
                                                  Requirements,
                                                  Isa
                                                  );
...
}
```

## See also

[INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type)