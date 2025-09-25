# EVT_WDF_WMI_INSTANCE_QUERY_INSTANCE callback function

## Description

[Applies to KMDF only]

A driver's *EvtWmiInstanceQueryInstance* callback function copies a WMI provider's instance data into a buffer for delivery to a WMI client.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object.

### `OutBufferSize` [in]

The size, in bytes, of the output buffer that *OutBuffer* points to.

### `OutBuffer` [in]

A pointer to the output buffer.

### `BufferUsed` [out]

A pointer to a location that receives the number of bytes that the driver places in the output buffer. If the output buffer size that the *OutBufferSize* parameter specifies is too small, the driver sets this location to the required buffer size.

## Return value

The *EvtWmiInstanceQueryInstance* callback function must return STATUS_BUFFER_TOO_SMALL, if the value of the *OutBufferSize* parameter indicates that the output buffer is too small to receive the data. Otherwise, the callback function must copy data into the buffer and return STATUS_SUCCESS.

## Remarks

To register an *EvtWmiInstanceQueryInstance* callback function, your driver must place the function's address in a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure before calling [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

Before the framework sends the driver-supplied instance data to the WMI client, it adds all of the necessary WMI header information to the data.

If your driver sets the **UseContextForQuery** member of the WMI instance object's [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure to **TRUE** for a read-only data block, the driver does not provide an *EvtWmiInstanceQueryInstance* callback function.

If your driver must provide string data to a WMI client, the driver should call the [WDF_WMI_BUFFER_APPEND_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_buffer_append_string) function to format the string.

For more information about the *EvtWmiInstanceQueryInstance* callback function, see [Supporting Read/Write WMI Data Blocks](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-data-blocks-and-events-in-your-driver) and [Supporting Read-Only WMI Data Blocks](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-data-blocks-and-events-in-your-driver).

The framework does not synchronize calls to a driver's WMI event callback functions with each other or with any of the driver's other event callback functions. If an *EvtWmiInstanceQueryInstance* callback function's data is dynamic and shared with other callback functions, your driver can use the framework's [wait locks or spin locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks) to synchronize access to the data.

For more information about WMI, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

## See also

[EvtWmiInstanceExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_execute_method)

[EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance)

[EvtWmiInstanceSetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_item)

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WDF_WMI_BUFFER_APPEND_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_buffer_append_string)

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)