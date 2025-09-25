# NdisRawReadPortUlong macro

## Description

**NdisRawReadPortUlong** reads a ULONG value from a given I/O port on the NIC.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Data` [out]

Pointer to a caller-supplied variable in which this function returns a ULONG value read in from
the port.

## Remarks

**NdisRawReadPortUlong** runs fast
because it need not map a bus-relative I/O port address onto a host-dependent logical port address at
every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferulong)

[NdisRawReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportuchar)

[NdisRawReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportushort)

[NdisRawWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportulong)