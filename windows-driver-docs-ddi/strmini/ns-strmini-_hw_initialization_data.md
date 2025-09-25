# _HW_INITIALIZATION_DATA structure (strmini.h)

## Description

The HW_INITIALIZATION_DATA structure specifies the basic information the class driver needs to begin initializing the minidriver. The minidriver passes an HW_INITIALIZATION_DATA structure to the class driver when it registers itself by calling [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter).

## Members

### `SizeOfThisPacket`

### `StreamClassVersion`

### `HwInitializationDataSize`

Specifies the size of this data structure, in bytes.

### `HwInterrupt`

Points to the minidriver's [StrMiniInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_interrupt) routine.

### `HwReceivePacket`

Points to the minidriver's [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routine.

### `HwCancelPacket`

Points to the minidriver's [StrMiniCancelPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_cancel_srb) routine.

### `HwRequestTimeoutHandler`

Points to the minidriver's [StrMiniRequestTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_request_timeout_handler) routine.

### `DeviceExtensionSize`

Specifies the size in bytes of the buffer the class driver should allocate for the minidriver's device extension. The minidriver may use this buffer to record private information. The class driver passes pointers to this buffer in the **HwDeviceExtension** member of [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `PerRequestExtensionSize`

Specifies the size in bytes of the buffer the class driver should allocate for the buffer pointed to by **SRBExtension** member of [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block) structures it passes to the minidriver. The class driver will allocate one buffer for each HW_STREAM_REQUEST_BLOCK.

### `PerStreamExtensionSize`

Specifies the size in bytes of the buffer the class driver should allocate for the buffer pointed to by the **HwStreamExtension** member of a stream's [HW_STREAM_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object). The class driver will allocate one buffer for each stream.

### `FilterInstanceExtensionSize`

Specifies the size in bytes of the buffer the class extension should allocate for the buffer pointed to by the **HwInstanceExtension** member of [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block) structures it passes to the minidriver. The class driver allocates one buffer for each instance of the minidriver.

### `BusMasterDMA`

If **TRUE**, the device can perform direct bus-master DMA to the minidriver's DMA buffer.

### `Dma24BitAddresses`

Minidrivers should set this to **TRUE** if the DMA hardware the devices uses can access only the lower 24 bits of the address space.

### `BufferAlignment`

Specifies the alignment requirement, in bytes, for DMA buffers. For example, a value of 4 indicates the DMA buffers should be aligned on 4-byte boundaries.

### `TurnOffSynchronization`

If **TRUE**, the minidriver will handle its own synchronization; otherwise the class driver handles synchronization. Most minidrivers should set this value to **FALSE**. See [Minidriver Synchronization](https://learn.microsoft.com/windows-hardware/drivers/stream/minidriver-synchronization) in the *Streaming Minidriver Design Guide* for more information.

### `DmaBufferSize`

Specifies the size in bytes of the DMA buffer the class driver should allocate for the minidriver. The minidriver gets a pointer to this buffer by calling [StreamClassGetDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassgetdmabuffer). The class driver allocates contiguous nonpageable memory that will not be available to the operating system, or to other drivers, so this value should be as small as possible.

### `NumNameExtensions`

### `NameExtensionArray`

### `Reserved`

Reserved for system use. Minidrivers should ignore this member.