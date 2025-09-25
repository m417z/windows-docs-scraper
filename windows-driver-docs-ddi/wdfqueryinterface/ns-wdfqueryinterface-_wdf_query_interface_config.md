# _WDF_QUERY_INTERFACE_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_QUERY_INTERFACE_CONFIG** structure describes a driver-defined interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Interface`

A pointer to an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure that describes the driver-defined interface.

### `InterfaceType`

A pointer to the GUID that identifies the interface.

> [!NOTE]
> When introducing a new version of an existing interface, create a new GUID instead of revising the **Size** or **Version** fields of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure. For more info, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

### `SendQueryToParentStack`

If **TRUE**, and if your driver specifies a device object that represents a physical device object (PDO) when it calls [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface), the framework sends requests for the interface to the top of the parent device's driver stack. If this member is **FALSE**, or if the device object does not represent a PDO, the framework does not send requests to the parent device's stack. For more information, see the following Remarks section.

### `EvtDeviceProcessQueryInterfaceRequest`

A pointer to your driver's [EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request) event callback function, which is called when another driver requests the interface.

### `ImportInterface`

If **TRUE**, the interface supports two-way communication between your driver and drivers that request the interface.

If this member is **FALSE**, the interface supports one-way communication from your driver to drivers that request the interface.

## Remarks

The **WDF_QUERY_INTERFACE_CONFIG** structure is used as input to the [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface) method.

For each driver-defined interface that your driver exports, you must allocate a WDF_QUERY_INTERFACE_CONFIG structure that represents the interface. Other drivers can request access to the interface by calling [WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface).

If you want your interface to support two-way communication between the requesting driver and your driver, set the **ImportInterface** member to **TRUE**. If **ImportInterface** is **TRUE**, the structure that is provided by the requesting driver can contain data that your driver can read. In this case:

* The [EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request) callback function is required, and it must initialize the interface structure that the requesting driver provides.
* Because the [EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request) callback function
  provides the interface to the requesting driver, the **Interface** member of **WDF_QUERY_INTERFACE_CONFIG** can be **NULL**.
  If you provide a non-**NULL** pointer, the framework verifies that the size and version values that the requesting driver supplies are equal to or greater than the values in your registered
  [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure. If either of these values are smaller, the framework rejects the request.
  If you do not provide a value for **Interface**, your *EvtDeviceProcessQueryInterfaceRequest* callback function must verify those values.

If you want your interface to support only one-way communication from your driver to the requesting driver, set **ImportInterface** is **FALSE**. The interface structure that the requesting driver provides can receive only data that your driver provides. In this case:

* The [EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request) callback function is optional.
* The **Interface** member cannot be **NULL**. The framework verifies that the GUID, size, and version values that the requesting driver supplies match the ones you supplied, and the framework rejects the request if the values do not match. If the values are valid, the framework initializes the interface structure that the requesting driver provides by using the values you supply for **Interface**.

Additionally, the **Interface** member can be **NULL** if the value of the **SendQueryToParentStack** member is **TRUE**.

If the **Interface** member is non-**NULL**, the framework copies the value to internal storage space. Therefore, the driver can allocate the INTERFACE structure in local, temporary storage space.

When your driver calls [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface), it can associate the interface with a framework device object that represents either a functional device object (FDO) or a physical device object (PDO). If the driver associates the interface with a PDO, it can set the **SendQueryToParentStack** member of the **WDF_QUERY_INTERFACE_CONFIG** structure to **TRUE**. When the framework intercepts a request for the interface, it checks the **SendQueryToParentStack** member and, if it is set to **TRUE**, the framework sends the request to the top of the driver stack of the PDO's parent. As a result, the request travels down two driver stacks: first, the stack that contains the driver that is requesting the interface and, second, the stack of the parent of the interface's device.

The framework provides two reference/dereference methods that you can use with your interfaces by specifying their addresses for the **InterfaceReference** and **InterfaceDereference** members of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure. For more information about these methods, see [WdfDeviceInterfaceReferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacereferencenoop) and [WdfDeviceInterfaceDereferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacedereferencenoop).

Drivers should initialize this structure by calling [WDF_QUERY_INTERFACE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdf_query_interface_config_init).

For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

## See also

[EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[WDF_QUERY_INTERFACE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdf_query_interface_config_init)

[WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface)

[WdfDeviceInterfaceDereferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacedereferencenoop)

[WdfDeviceInterfaceReferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacereferencenoop)

[WdfFdoQueryForInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoqueryforinterface)