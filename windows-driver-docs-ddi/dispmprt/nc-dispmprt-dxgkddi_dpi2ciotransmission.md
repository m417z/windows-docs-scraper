# DXGKDDI_DPI2CIOTRANSMISSION callback function

## Description

The **DXGKDDI_DPI2CIOTRANSMISSION** callback performs DP I2C over AUX read/write operations on devices directly attached on GPU.

## Parameters

### `Context`

Context pointer provided when querying the interface.

### `pArgs`

Pointer to a [**DXGKARG_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_dpi2ciotransmission) structure.

## Return value

**DXGKDDI_DPI2CIOTRANSMISSION** returns STATUS_SUCCESS if it succeeds; otherwise it returns an error code such as one of the following:

| Error Code | Meaning |
| ---------- | ------- |
| STATUS_DRIVER_INTERNAL_ERROR | An internal software error occurred.|
| STATUS_ACCESS_DENIED | The request is not supported. For Windows 10 version 2004, only I2C over AUX read is supported. |
| STATUS_BUFFER_TOO_SMALL | The buffer is too small for the operation. |
| STATUS_DEVICE_HARDWARE_ERROR | A hardware error occurred. |
| STATUS_DEVICE_POWERED_OFF | The device is powered off. |
| STATUS_DEVICE_NOT_CONNECTED | The device is not connected. |
| STATUS_DEVICE_PROTOCOL_ERROR | An error occurred at the I2C over AUX protocol level. The driver can use **DPNativeError** to encode more details about the error. |

## Remarks

This DDI call is used to perform DP I2C over AUX read/write on devices directly attached on GPU.

For I2C, the maximum size of **Data** buffer in the [**DXGKARG_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_dpi2ciotransmission) structure pointed to by *pArgs* is 128 bytes. Combining a write operation before a read operation in a single bus transaction/cycle is supported for MCCS and other protocols. The **Data** buffer is of size **BufferSizeSupplied**, which should be greater than or equal to the larger value of **BytesToWrite** and **BytesToRead**.

**Offset** is the address for IO within the device. When **EDDCMode** is set, there are E-DDC devices at **I2CAddress** (0xA0 for EDID, 0xA4 for DisplayID). The driver should write **SegmentPointer** to I2C address 0x60, **WordOffset** to **I2CAddress** and then carry out the IO operation. For all other I2C devices, the driver should write bytes of **Offset** according to **OffsetSizeInBytes**.

In case of failure, the driver should return **BytesWritten** and **BytesRead** as accurately as possible.

For Windows 10 version 2004, the write operation is only allowed for MCCS I2C address of 0x6E. All other operations will be blocked until a later OS release when access control is added.

## See also

[DXGKARG_DPI2CIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_dpi2ciotransmission)