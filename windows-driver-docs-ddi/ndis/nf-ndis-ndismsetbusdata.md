# NdisMSetBusData function

## Description

NDIS drivers call the
**NdisMSetBusData** function to write to the configuration space of a device.

## Parameters

### `NdisMiniportHandle`

The miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `WhichSpace` [in]

The type of bus data to be written. For further information, see the discussion of the
*WhichSpace* parameter on the reference page for
[IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config).

### `Offset` [in]

The byte offset in the configuration space, specified by
*WhichSpace*, to which data is written.

### `Buffer` [in]

A pointer to a buffer that contains the data to write to the bus. Must be at least as large as
*Length* .

### `Length` [in]

The length, in bytes, of the data to write.

## Return value

**NdisMGetBusData** returns the number of bytes written.

## Remarks

This function replaces the NDIS 5.1
[NdisWritePciSlotInformation](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff554871(v=vs.85)) function.

## See also

[IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata)