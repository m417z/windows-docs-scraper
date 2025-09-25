# NdisWriteRegisterUshort macro

## Description

**NdisWriteRegisterUshort** is called by the miniport driver to write a USHORT to a memory-mapped device
register.

## Parameters

### `Register` [in]

Pointer to the memory-mapped register. This virtual address must fall within a range returned by
an initialization-time call to [**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace).

### `Data` [in]

Specifies the caller-supplied USHORT that this function transfers to the
*Register* .

## Remarks

If a driver calls this function, a NIC's device registers must be mapped to noncached memory during
driver initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[**NdisMMapIoSpace**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismmapiospace)

[NdisReadRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadregisterushort)

[NdisWriteRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisteruchar)

[NdisWriteRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteregisterulong)