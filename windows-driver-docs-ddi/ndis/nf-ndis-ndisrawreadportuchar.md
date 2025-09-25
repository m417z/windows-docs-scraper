# NdisRawReadPortUchar macro

## Description

**NdisRawReadPortUchar** reads a byte from a given I/O port on the NIC.

## Parameters

### `Port` [in]

Specifies the I/O port. This address falls in a range that was mapped during initialization with
[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterioportrange).

### `Data` [out]

Pointer to a caller-supplied variable in which this function returns a byte read in from the
port.

## Remarks

**NdisRawReadPortUchar** runs fast
because it need not map a bus-relative I/O port address onto a host-dependent logical port address at
every call.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterIoPortRange](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndismregisterioportrange)

[NdisRawReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportbufferuchar)

[NdisRawReadPortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportulong)

[NdisRawReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawreadportushort)

[NdisRawWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisrawwriteportuchar)