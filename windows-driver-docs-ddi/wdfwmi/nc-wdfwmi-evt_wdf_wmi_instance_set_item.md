# EVT_WDF_WMI_INSTANCE_SET_ITEM callback function

## Description

[Applies to KMDF only]

A driver's *EvtWmiInstanceSetItem* callback function sets a single item of a WMI data provider's instance data to a value that a WMI client supplies.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object.

### `DataItemId` [in]

A value that identifies an item of data for a provider instance. This value corresponds to the [WmiDataId](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-property-qualifiers) value that is specified in the provider's MOF file.

### `InBufferSize` [in]

The size, in bytes, of the input buffer that *InBuffer* points to.

### `InBuffer` [in]

A pointer to the input buffer.

## Return value

The *EvtWmiInstanceSetItem* callback function must return STATUS_SUCCESS if the operation succeeds. Otherwise, this function must return a status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **FALSE**. If the input buffer that the *InBuffer* parameter points to is too small to contain all of the data that the driver expects, the callback function must return STATUS_WMI_SET_FAILURE.

## Remarks

To register an *EvtWmiInstanceSetItem* callback function, your driver must place the function's address in a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure before calling [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

The framework does not synchronize calls to a driver's WMI event callback functions with each other or with any of the driver's other event callback functions. If an *EvtWmiInstanceSetItem* callback function's data is dynamic and shared with other callback functions, your driver can use the framework's [wait locks or spin locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks) to synchronize access to the data.

For more information about the *EvtWmiInstanceSetItem* callback function, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

## See also

[EvtWmiInstanceExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_execute_method)

[EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance)

[EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance)

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)