# EVT_WDF_DEVICE_RELATIONS_QUERY callback function

## Description

[Applies to KMDF only]

A driver's *EvtDeviceRelationsQuery* event callback reports changes in the relationships among devices that are supported by the driver.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `RelationType` [in]

A DEVICE_RELATION_TYPE-typed enumerator value. The DEVICE_RELATION_TYPE enumeration is defined in *wdm.h*.

## Remarks

To register the *EvtDeviceRelationsQuery* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

Most framework-based drivers do not need to provide this callback function.

During system initialization, the Plug and Play manager enumerates all of the devices on the system by sending an [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) request to the driver stack. If a framework-based driver has registered an *EvtDeviceRelationsQuery* callback function, the framework calls it. The function driver for the bus must report all of the child devices that are attached to the bus.

Additionally, after the framework calls the [IoInvalidateDeviceRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinvalidatedevicerelations) routine to report a changed relationship among the devices on the driver's bus, the Plug and Play manager sends another IRP_MN_QUERY_DEVICE_RELATIONS request to the driver stack. The framework then calls the driver's *EvtDeviceRelationsQuery* callback function so that the driver can provide details about the change.

The type of work that a driver must do depends on the value received for the *RelationType* parameter. The value can be one of the following:

**BusRelations**

Most framework-based drivers do not report bus relations in an EvtDeviceRelationsQuery callback function. Instead, the drivers follow the guidelines that are described in Enumerating the Devices on a Bus.

**EjectionRelations**

Most framework-based drivers do not report ejection relations in an EvtDeviceRelationsQuery callback function. Instead, the driver for the device's bus calls WdfPdoAddEjectionRelationsPhysicalDevice and WdfPdoRemoveEjectionRelationsPhysicalDevice.

**RemovalRelations**

Most framework-based drivers do not report removal relations in an EvtDeviceRelationsQuery callback function. Instead, the drivers call WdfDeviceAddRemovalRelationsPhysicalDevice and WdfDeviceRemoveRemovalRelationsPhysicalDevice.

**TargetDeviceRelation**

Framework-based drivers do not have to report a device's target relation. Instead, the framework handles this request.

The framework can call the *EvtDeviceRelationsQuery* callback function with a *RelationType* value of **EjectionRelations** or **RemovalRelations** even if the device is being removed.