# _HW_STREAM_OBJECT structure

## Description

HW_STREAM_OBJECT describes an instance of a minidriver stream.

## Members

### `SizeOfThisPacket`

Specifies the size, in bytes, of this structure.

### `StreamNumber`

Specifies the offset of the stream within the minidriver's [HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure.

### `HwStreamExtension`

Points to the stream extension, a buffer allocated by the class driver for the minidriver to use to hold private information about this stream. The minidriver sets the size of the buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself with the stream class driver.

### `ReceiveDataPacket`

Pointer to the stream's [StrMiniReceiveStreamDataPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routine.

### `ReceiveControlPacket`

Pointer to the stream's [StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85)) routine.

### `HwClockObject`

Contains the stream's clock object. See [HW_CLOCK_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_clock_object) for details.

### `Dma`

If **TRUE**, the device uses DMA to transfer data for this stream.

### `Pio`

If **TRUE**, the device uses programmed I/O to transfer data for this stream. Note that both the **Pio** and **Dma** members may be **TRUE**.

### `HwDeviceExtension`

Pointer to the minidriver's device extension. The minidriver may use this buffer to record private information. The minidriver sets the size of this buffer in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver also passes pointers to this buffer in the **HwDeviceExtension** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block), [HW_TIME_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `StreamHeaderMediaSpecific`

Specifies the size in bytes of the media-specific, per-stream header extension.

### `StreamHeaderWorkspace`

Specifies the size of the per-stream-header workspace.

### `Allocator`

Specifies **TRUE** if the driver uses allocators. Most minidrivers set this value to **FALSE**.

### `HwEventRoutine`

Pointer to the stream's [StrMiniEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_event_routine) routine

### `Reserved`

Reserved for system use. Do not use.

## Remarks

This structure is created by the class driver to hold information about a particular stream in the minidriver. For each stream-specific request, the class driver passes the HW_STREAM_OBJECT for the stream in the **StreamObject** member of the stream request block (See [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block)).

When the class driver opens the stream and issues the SRB_OPEN_STREAM request to the minidriver's [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routine, the minidriver initializes the stream object.

## See also

[HW_CLOCK_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_clock_object)