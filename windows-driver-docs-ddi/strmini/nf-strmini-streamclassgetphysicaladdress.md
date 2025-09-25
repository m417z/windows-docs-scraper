## Description

The **StreamClassGetPhysicalAddress** routine translates a virtual memory address to a physical memory address and locks the corresponding physical memory for a DMA operation.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the minidriver's device extension. The minidriver specifies the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver then passes pointers to the buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `HwSRB` [in, optional]

Specifies a stream request block. This parameter is used only if the *Type* parameter has the value SRBDataBuffer, otherwise *HwSRB* should be **NULL**. This parameter is optional.

### `VirtualAddress` [in]

Specifies the virtual address to be translated.

### `Type` [in]

Specifies the type of buffer pointed to by *VirtualAddress*. This value may be PerRequestExtension, DmaBuffer, or SRBDataBuffer.

### `Length` [out]

Specifies the length, in bytes, of the buffer.

## Return value

**StreamClassGetPhysicalAddress** returns the translated virtual address as a physical memory address.

## Remarks

The type of buffer to be used is specified in the *Type* parameter. The meanings of these values are shown in the following table.

| Buffer Type | Description |
|---|---|
| PerRequestExtension | Indicates the physical address of the SRB extension. |
| DmaBuffer | Indicates the physical address of the DMA buffer. |
| SRBDataBuffer | Indicates the physical address of the data buffer. |