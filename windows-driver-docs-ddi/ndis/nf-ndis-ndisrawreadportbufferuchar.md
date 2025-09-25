# NdisRawReadPortBufferUchar macro

## Description

**NdisRawReadPortBufferUchar** reads a specified number of bytes into a caller-supplied buffer.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Buffer` [out]

Pointer to a caller-allocated buffer, in resident memory, into which the bytes will be transferred
from the NIC's port. The caller must allocate a buffer at least
sizeof(
*Length* ).

### `Length` [in]

Specifies how many bytes to transfer from the NIC.

## Remarks

**NdisRawReadPortBufferUchar** reads each byte, one at a time, from the given I/O port into the given
buffer.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferulong)

[NdisRawReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferushort)

[NdisRawReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportuchar)

[NdisRawWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferuchar)