## Description

This callback function leaves the specified DMA domain.

## Parameters

### `DmaAdapter` [in]

A pointer to a DMA_ADAPTER structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

## Return value

Returns STATUS_SUCCESS if the call is successful. Otherwise, returns an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also