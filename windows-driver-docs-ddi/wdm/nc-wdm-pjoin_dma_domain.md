## Description

The PJOIN_DMA_DOMAIN callback function joins the specified DMA domain.

## Parameters

### `DmaAdapter` [in]

A pointer to a DMA_ADAPTER structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `DomainHandle` [in]

The handle to the DMA domain that the caller previous obtained through [*PGET_DMA_DOMAIN*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_domain).

## Return value

Returns STATUS_SUCCESS if the call is successful. Otherwise, returns an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also