# NdisRawReadPortBufferUshort macro

## Description

**NdisRawReadPortBufferUshort** reads a specified number of USHORTs into a caller-supplied buffer.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Buffer` [out]

Pointer to a caller-allocated buffer, in resident memory, into which the USHORTs will be
transferred from the NIC. The caller must allocate a buffer at least (**sizeof**(USHORT)
     *
*Length* ).

### `Length` [in]

Specifies how many USHORTs to transfer from the NIC.

## Remarks

**NdisRawReadPortBufferUshort** reads each USHORT value, one at a time, from the given I/O port into
the given buffer.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferuchar)

[NdisRawReadPortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferulong)

[NdisRawReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportushort)

[NdisRawWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferushort)