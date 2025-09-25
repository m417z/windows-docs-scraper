# WDF_QUERY_INTERFACE_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_QUERY_INTERFACE_CONFIG_INIT** function initializes a driver's [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure.

## Parameters

### `InterfaceConfig` [out]

A pointer to the driver's [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure.

### `Interface` [in]

A pointer to an [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

### `InterfaceType` [in]

A pointer to the GUID that identifies the interface.

### `EvtDeviceProcessQueryInterfaceRequest` [in, optional]

A pointer to the driver's [EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request) event callback function, which is called when another driver requests the interface.

## Remarks

For more information about driver-defined interfaces, see [Using Driver-Defined Interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces).

#### Examples

For a code example that uses **WDF_QUERY_INTERFACE_CONFIG_INIT**, see [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

## See also

[EvtDeviceProcessQueryInterfaceRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nc-wdfqueryinterface-evt_wdf_device_process_query_interface_request)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config)