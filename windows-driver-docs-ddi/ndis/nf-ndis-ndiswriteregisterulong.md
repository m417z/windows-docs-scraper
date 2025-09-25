# NdisWriteRegisterUlong macro

## Description

**NdisWriteRegisterUlong** is called by the miniport driver to write a ULONG to a memory-mapped device
register.

## Parameters

### `Register` [in]

Pointer to the memory-mapped register. This virtual address must fall within a range returned by
an initialization-time call to [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace).

### `Data` [in]

Specifies the caller-supplied ULONG that this function transfers to the
*Register* .

## Remarks

If a driver calls this function, a NIC's device registers must be mapped to noncached memory during
driver initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterulong)

[NdisWriteRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisteruchar)

[NdisWriteRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterushort)