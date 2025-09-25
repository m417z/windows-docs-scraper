# _STREAM_DATA_INTERSECT_INFO structure

## Description

STREAM_DATA_INTERSECT_INFO describes the parameters of a data intersection operation.

## Members

### `StreamNumber`

Specifies the stream number. This corresponds to the offset of the stream within the minidriver's array of [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) structures. The possible data formats depend on the stream type.

### `DataRange`

Pointer to the data ranges to be examined for a match.

### `DataFormatBuffer`

Pointer to the buffer the minidriver fills in with the matching data format.

### `SizeOfDataFormatBuffer`

Specifies the size in bytes of the **DataFormatBuffer**.

## Remarks

The class driver passes this data structure when it submits a [SRB_GET_DATA_INTERSECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-data-intersection) request to the minidriver's [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb).