# NdisRawWritePortUchar macro

## Description

**NdisRawWritePortUchar** writes a byte to an I/O port on the NIC.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Data` [in]

Specifies the byte to be written.

## Remarks

**NdisRawWritePortUchar** runs fast because it need not map a bus-relative I/O port address onto a
host-dependent logical port address at every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportuchar)

[NdisRawWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferuchar)

[NdisRawWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportulong)

[NdisRawWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportushort)