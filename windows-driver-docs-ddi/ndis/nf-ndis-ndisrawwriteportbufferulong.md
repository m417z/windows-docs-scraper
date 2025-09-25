# NdisRawWritePortBufferUlong macro

## Description

**NdisRawWritePortBufferUlong** writes a specified number of ULONG values from a caller-supplied buffer
to a given I/O port.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Buffer` [in]

Pointer to a caller-allocated resident buffer containing the ULONGs to be written.

### `Length` [in]

Specifies the number of ULONGs to write to the I/O port.

## Remarks

A miniport driver calls
**NdisRawWritePortBufferUlong** to transfer a sequence of ULONGs, one at a time, to a NIC.

**NdisRawWritePortBufferUlong** runs fast because it need not map a bus-relative port address onto a
host-dependent logical port address at every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferulong)

[NdisRawWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferuchar)

[NdisRawWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferushort)

[NdisRawWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportulong)