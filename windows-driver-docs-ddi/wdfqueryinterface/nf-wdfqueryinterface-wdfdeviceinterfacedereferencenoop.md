# WdfDeviceInterfaceDereferenceNoOp function

## Description

[Applies to KMDF only]

The **WdfDeviceInterfaceDereferenceNoOp** method can be used for driver-defined interfaces that do not require reference counts.

## Parameters

### `Context` [in]

This parameter is not used.

## Remarks

You can use the **WdfDeviceInterfaceDereferenceNoOp** method's address as the **InterfaceDereference** member of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure that is contained in the framework's [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure.

For more information about interface reference counts and the **WdfDeviceInterfaceDereferenceNoOp** method, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

#### Examples

For a code example that uses **WdfDeviceInterfaceDereferenceNoOp**, see [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

## See also

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config)

[WdfDeviceInterfaceReferenceNoOp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceinterfacereferencenoop)