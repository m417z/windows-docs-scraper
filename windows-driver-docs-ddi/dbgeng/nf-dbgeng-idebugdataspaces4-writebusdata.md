# IDebugDataSpaces4::WriteBusData

## Description

The **WriteBusData** method writes data to a system bus.

## Parameters

### `BusDataType` [in]

Specifies the bus data type of the bus to write to. For details of allowed values see the documentation for the BUS_DATA_TYPE enumeration in the Microsoft Windows SDK.

### `BusNumber` [in]

Specifies the system-assigned number of the bus. This is usually zero, unless the system has more than one bus of the same bus data type.

### `SlotNumber` [in]

Specifies the logical slot number on the bus.

### `Offset` [in]

Specifies the offset in the bus data to start writing to.

### `Buffer` [in]

Specifies the data to write to the bus.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be written.

### `BytesWritten` [out, optional]

Receives the number of bytes written to the bus. If *BytesWritten* is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available in kernel-mode debugging.

The nature of the data read from the bus is system, bus, and slot dependent.