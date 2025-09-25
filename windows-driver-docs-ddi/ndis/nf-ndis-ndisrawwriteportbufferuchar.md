# NdisRawWritePortBufferUchar macro

## Description

**NdisRawWritePortBufferUchar** writes a specified number of bytes from a caller-supplied buffer to a
given I/O port.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Buffer` [in]

Pointer to a caller-allocated resident buffer containing the bytes to be written.

### `Length` [in]

Specifies the number of bytes to write to the I/O port.

## Remarks

A miniport driver calls
**NdisRawWritePortBufferUchar** to transfer a sequence of bytes, one at a time, to a NIC.

**NdisRawWritePortBufferUchar** runs fast because it need not map a bus-relative port address onto a
host-dependent logical port address at every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferuchar)

[NdisRawWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferulong)

[NdisRawWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferushort)

[NdisRawWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportuchar)