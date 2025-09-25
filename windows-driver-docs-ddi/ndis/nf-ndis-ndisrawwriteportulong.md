# NdisRawWritePortUlong macro

## Description

**NdisRawWritePortUlong** writes a ULONG value to an I/O port on the NIC.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Data` [in]

Specifies the ULONG to be written.

## Remarks

**NdisRawWritePortUlong** runs fast because it need not map a bus-relative I/O port address onto a
host-dependent logical port address at every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportulong)

[NdisRawWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportbufferulong)

[NdisRawWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportuchar)

[NdisRawWritePortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportushort)