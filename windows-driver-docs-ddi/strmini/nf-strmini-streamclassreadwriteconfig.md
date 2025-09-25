# StreamClassReadWriteConfig function

## Description

The **StreamClassReadWriteConfig** routine reads or writes configuration data for the minidriver's parent bus driver.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the minidriver's device extension. The minidriver specifies the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver then passes pointers to the buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `Read` [in]

Specifies whether to read or write the configuration information. A value of **TRUE** indicates that a read is requested. A value of **FALSE** indicates that a write should be performed.

### `Buffer` [in, out]

Points to the buffer to use to read/write the configuration information.

### `Offset` [in]

Specifies the offset within the configuration information to begin the read/write operation.

### `Length` [in]

Specifies the length of the data to read or write.

## Return value

Returns **TRUE** on success, **FALSE** on failure.

## Remarks

This routine reads or writes configuration information for the minidriver's parent bus driver. For example, for a PCI device, **StreamClassReadWriteConfig** reads or writes PCI configuration information.

This routine can only be called at PASSIVE_LEVEL.