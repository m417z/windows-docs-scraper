# IDebugDataSpaces2::WriteIo

## Description

The **WriteIo** method writes to the system and bus I/O memory.

## Parameters

### `InterfaceType` [in]

Specifies the interface type of the I/O bus. This parameter may take values in the INTERFACE_TYPE enumeration defined in wdm.h.

### `BusNumber` [in]

Specifies the system-assigned number of the bus. This is usually zero, unless the system has more than one bus of the same interface type.

### `AddressSpace` [in]

Set to one.

### `Offset` [in]

Specifies the location of the requested data.

### `Buffer` [in]

Specifies the data to write to the I/O bus.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be written.

### `BytesWritten` [out, optional]

Receives the number of bytes written to I/O bus. If *BytesWritten* is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available in kernel-mode debugging.