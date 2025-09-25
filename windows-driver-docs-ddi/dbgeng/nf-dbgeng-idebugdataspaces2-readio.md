# IDebugDataSpaces2::ReadIo

## Description

The **ReadIo** method reads from the system and bus I/O memory.

## Parameters

### `InterfaceType` [in]

Specifies the interface type of the I/O bus. This parameter may take values in the INTERFACE_TYPE enumeration defined in wdm.h.

### `BusNumber` [in]

Specifies the system-assigned number of the bus. This is usually zero, unless the system has more than one bus of the same interface type.

### `AddressSpace` [in]

This parameter must be equal to one.

### `Offset` [in]

Specifies the I/O address within the address space.

### `Buffer` [out]

Receives the data read from the I/O bus.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be read. At present, this must be 1, 2, or 4.

### `BytesRead` [out, optional]

Receives the number of bytes returned read from the I/O bus. If *BytesRead* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in kernel-mode debugging.