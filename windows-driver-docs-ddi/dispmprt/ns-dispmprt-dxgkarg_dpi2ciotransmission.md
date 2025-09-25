# DXGKARG_DPI2CIOTRANSMISSION structure

## Description

The **DXGKARG_DPI2CIOTRANSMISSION** structure is a parameter for the [**DXGKDDI_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission) callback.

## Members

### `Read`

If set, perform a DP I2C over AUX read operation.

### `Write`

If set, perform a DP I2C over AUX write operation.

### `EDDCMode`

If set, the device at **I2CAddress** is Enhanced Display Data Channel (E-DDC).

### `OffsetSizeInBytes`

Offset size from **Offset**, in bytes, at which to write data for non-E-DDC devices.

### `CanUseCachedData`

If set, the driver can use cached data.

### `Reserved`

Reserved; do not use.

### `RootPortIndex`

Index value of the DP-capable connector on which to perform the DP I2C over AUX read or write operation. The driver returned the total number of DP-capable connectors on the GPU in a prior call to [**DXGKDDI_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps). Subsequent calls to [**DXGKDDI_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission) refer to the DP connectors with **RootPortIndex** ranging from **0** to **NumRootPorts - 1**.

### `I2CAddress`

I2C address. Set to 0xA0 for EDID, or 0xA4 for DisplayID.

### `WordOffset`

Word offset, in bytes.

### `SegmentPointer`

When **EDDCMode** is set, the driver should write **SegmentPointer** to I2C address 0x60. **SegmentPointer** identifies the 256-byte data block being accessed for E-DDC devices.

### `Reserved1`

Reserved; do not use.

### `Offset`

Address for IO within the device.

### `BufferSizeSupplied`

Size of the **Data** buffer, in bytes. **BufferSizeSupplied** should be greater than or equal to the larger of **BytesToWrite** and **BytesToWrite**.

### `BytesToWrite`

Number of bytes to write for a write operation.

### `BytesToRead`

Number of bytes to read for a read operation.

### `DPNativeError`

Field in which the driver can encode more details about the error when returning STATUS_DEVICE_PROTOCOL_ERROR from [**DXGKDDI_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission).

### `BytesWritten`

Number of bytes written. The driver should return this value as accurately as possible in the case of failure.

### `BytesRead`

Number of bytes read. The driver should return this value as accurately as possible in the case of failure.

### `Data`

Buffer containing the data to write for a write operation, and/or in which to receive the data for a read operation.

## Remarks

When **EDDCMode** is set, the driver should write **WordOffset** to **OffsetSizeInBytes**.

When **EDDCMode** is set, there are E-DDC devices at **I2CAddress** (0xA0 for EDID, 0xA4 for DisplayID). In this situation, the driver should write **SegmentPointer** to I2C address 0x60, **WordOffset** to **I2CAddress**, and then carry out the IO operation. For all other I2C devices, the driver should write bytes of **Offset** according to **OffsetSizeInBytes**.

In case of failure, the driver should return **BytesWritten** and **BytesRead** as accurately as possible.

For Windows 10 version 2004, a write operation is only allowed for MCCS I2C address of 0x6E. All other operations will be blocked until a later OS release when access control is added.

## See also

[**DXGKDDI_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission)

[**DXGKDDI_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps)