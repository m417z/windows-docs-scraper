# _HW_STREAM_DESCRIPTOR structure

## Description

The minidriver uses the HW_STREAM_DESCRIPTOR structure to return stream information to the stream class driver.

## Members

### `StreamHeader`

Contains the [HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header) for the stream descriptor.

### `StreamInfo`

Contains the [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) block for the zero stream.

## Remarks

The minidriver returns this structure to the class driver in response to a [SRB_GET_STREAM_INFO](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-info) request. The class driver makes this request by calling the minidriver's [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routine.

The class driver expects HW_STREAM_DESCRIPTOR to be laid out in memory as an [HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header) followed by an array of [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) structures. The array begins at the address of the **StreamInfo** member. The HW_STREAM_HEADER's **NumberOfStreams** member indicates the number of entries in the array. The minidriver uses HW_STREAM_HEADER to describe those kernel streaming properties of the driver as a whole, while each HW_STREAM_INFORMATION structure describes each individual stream the device supports.

## See also

[HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header)

[HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information)