# DXGKARG_DPAUXIOTRANSMISSION structure

## Description

The **DXGKARG_DPAUXIOTRANSMISSION** structure is a parameter for the [**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission) callback.

## Members

### `Write`

Indicates whether the operation is read or write. A value of zero indicates that the DisplayPort Configuration Data (DPCD) operation is a read; a value of one indicates a write to the DPCD.

### `CanUseCachedData`

When set, indicates that the driver can use cached data without actual AUX transaction.

### `Reserved`

Reserved; do not use.

### `RootPortIndex`

Index value of the DP-capable connector on which to perform the DPCD read or write operation. The driver returned the total number of DP-capable connectors on the GPU in a prior call to [DXGKDDI_QUERYDPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps). Subsequent calls to [**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission) refer to the DP connectors with **RootPortIndex** ranging from **0** to **NumRootPorts - 1**.

### `DPCDAddress`

The DPCD address for the read or write operation.

### `NumBytesRequested`

Number of bytes to read/write starting at **DPCDAddress**.

### `DPNativeError`

Field in which the driver can encode more details about the error when returning STATUS_DEVICE_PROTOCOL_ERROR from [**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission).

### `NumBytesDone`

Actual number of bytes that were read or written.

### `Data`

Buffer containing the data to write for a write operation, or in which to receive the data for a read operation.

## Remarks

## See also

[DXGKDDI_QUERYDPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps)

[**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission)