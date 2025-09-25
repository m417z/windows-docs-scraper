# NdisReadRegisterUchar macro

## Description

**NdisReadRegisterUchar** is called by the miniport driver to read a UCHAR from a memory-mapped device
register.

## Parameters

### `Register` [in]

Pointer to the memory-mapped register. This virtual address must fall within a range returned by
an initialization-time call to [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace).

### `Data` [out]

Pointer to the caller-supplied variable in which this function returns the UCHAR read from
*Register* .

## Remarks

If a driver calls this function, a NIC's device registers must be mapped to noncached memory during
driver initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterulong)

[NdisReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterushort)

[NdisWriteRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisteruchar)