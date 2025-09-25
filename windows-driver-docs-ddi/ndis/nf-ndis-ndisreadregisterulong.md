# NdisReadRegisterUlong macro

## Description

**NdisReadRegisterUlong** is called by the miniport driver to read a ULONG from a memory-mapped device
register.

## Parameters

### `Register` [in]

Pointer to the memory-mapped register. This virtual address must fall within a range returned by
an initialization-time call to [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace).

### `Data` [out]

Pointer to the caller-supplied variable in which this function returns the ULONG read from
*Register* .

## Remarks

If a driver calls this function, a NIC's device registers must be mapped to noncached memory during
driver initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisteruchar)

[NdisReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterushort)

[NdisWriteRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterulong)