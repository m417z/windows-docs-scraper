# IDebugDataSpaces::ReadBusData

## Description

The **ReadBusData** method reads data from a system bus.

## Parameters

### `BusDataType` [in]

Specifies the bus data type to read from. For details of allowed values see the documentation for the BUS_DATA_TYPE enumeration in the Microsoft Windows SDK.

### `BusNumber` [in]

Specifies the system-assigned number of the bus. This is usually zero, unless the system has more than one bus of the same bus data type.

### `SlotNumber` [in]

Specifies the logical slot number on the bus.

### `Offset` [in]

Specifies the offset in the bus data to start reading from.

### `Buffer` [out]

Receives the data from the bus.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be returned.

### `BytesRead` [out, optional]

Receives the number of bytes read from the bus. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.

The nature of the data read from the bus is system, bus, and slot dependent.