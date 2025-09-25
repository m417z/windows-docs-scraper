# EVT_WDF_WMI_INSTANCE_EXECUTE_METHOD callback function

## Description

[Applies to KMDF only]

A driver's *EvtWmiInstanceExecuteMethod* callback function executes a specified method that the driver provides for a WMI data provider's instance.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object.

### `MethodId` [in]

A value that identifies a method in a provider instance. This value corresponds to the [WmiMethodId](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-property-qualifiers) value that is specified in the provider's MOF file.

### `InBufferSize` [in]

The number of bytes of input data.

### `OutBufferSize` [in]

The number of bytes of output data that the buffer that *Buffer* points to can hold.

### `Buffer` [in, out]

A pointer to a buffer that is used for input, output, or both, as determined by the specified method. If both input and output data are provided, the driver overwrites the input data with the output data.

### `BufferUsed` [out]

A pointer to a location that receives the number of bytes that the driver wrote into the output buffer. If the output buffer size that the *OutBufferSize* parameter specifies is too small, the driver sets this location to the required buffer size.

## Return value

The *EvtWmiInstanceExecuteMethod* callback function must return STATUS_SUCCESS if the operation succeeds. Otherwise, this function must return a status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **FALSE**. The driver must return STATUS_BUFFER_TOO_SMALL if the value of the *OutBufferSize* parameter indicates that the output buffer is too small to receive the data.

## Remarks

To register an *EvtWmiInstanceExecuteMethod* callback function, your driver must place the function's address in a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure before calling [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

After a driver executes the instance method that the *MethodId* parameter specifies, the driver must use the *BufferUsed* parameter to store the number of bytes that were written to the buffer.

The framework does not synchronize calls to a driver's WMI event callback functions with each other or with any of the driver's other event callback functions. If an *EvtWmiInstanceExecuteMethod* callback function's data is dynamic and shared with other callback functions, your driver can use the framework's [wait locks or spin locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks) to synchronize access to the data.

For more information about the *EvtWmiInstanceExecuteMethod* callback function, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

## See also

[EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance)

[EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance)

[EvtWmiInstanceSetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_item)

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)