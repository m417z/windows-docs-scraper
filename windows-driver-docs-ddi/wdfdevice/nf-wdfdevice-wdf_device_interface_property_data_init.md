# WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT function

## Description

[Applies to UMDF only]

The **WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT** function initializes a driver's [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure.

## Parameters

### `PropertyData` [in]

A pointer to [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure.

### `InterfaceClassGUID` [in]

A pointer to a GUID that identifies the device interface class.

### `PropertyKey` [in]

A pointer to a **DEVPROPKEY** structure that specifies the device property key.

## Remarks

Before calling the following methods, a driver must call **WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT** to initialize a [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure.

* [WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)
* [WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)
* [WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)

The **WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT** function zeros the specified [WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data) structure and sets the structure's **Size** member. It also sets the structure's **InterfaceClassGUID** and **PropertyKey** members to the specified values.

For a code example that uses **WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT**, see [WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty).

## See also

[WDF_DEVICE_INTERFACE_PROPERTY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_interface_property_data)

[WdfDeviceAllocAndQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceallocandqueryinterfaceproperty)

[WdfDeviceAssignInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigninterfaceproperty)

[WdfDeviceQueryInterfaceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicequeryinterfaceproperty)