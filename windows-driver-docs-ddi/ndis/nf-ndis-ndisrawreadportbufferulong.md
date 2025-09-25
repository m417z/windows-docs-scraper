# NdisRawReadPortBufferUlong macro

## Description

**NdisRawReadPortBufferUlong** reads a specified number of ULONGs into a caller-supplied buffer.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Buffer` [out]

Pointer to a caller-allocated buffer, in resident memory, into which the ULONGs will be
transferred from the NIC. The caller must allocate a buffer at least (
**sizeof**(ULONG)
     *
*Length* ).

### `Length` [in]

Specifies how many ULONGs to transfer from the NIC.

## Remarks

**NdisRawReadPortBufferUlong** reads each ULONG value, one at a time, from the given I/O port into the
given buffer.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferuchar)

[NdisRawReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferushort)

[NdisRawReadPortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportulong)

[NdisRawWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferulong)