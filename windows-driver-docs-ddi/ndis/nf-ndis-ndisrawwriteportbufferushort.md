# NdisRawWritePortBufferUshort macro

## Description

**NdisRawWritePortBufferUshort** writes a specified number of USHORT values from a caller-supplied buffer
to a given I/O port.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Buffer` [in]

Pointer to a caller-allocated resident buffer containing the USHORTs to be written.

### `Length` [in]

Specifies the number of USHORTs to write to the I/O port.

## Remarks

A miniport driver calls
**NdisRawWritePortBufferUshort** to transfer a sequence of USHORTs, one at a time, to a NIC.

**NdisRawWritePortBufferUshort** runs fast because it need not map a bus-relative port address onto a
host-dependent logical port address at every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferushort)

[NdisRawWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferuchar)

[NdisRawWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferulong)

[NdisRawWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportushort)