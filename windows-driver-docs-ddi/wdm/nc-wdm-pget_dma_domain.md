## Description

The PGET_DMA_DOMAIN callback function gets the handle to the DMA domain.

## Parameters

### `DmaAdapter:` [in]

A pointer to a DMA_ADAPTER structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

## Return value

Returns the HANDLE to the DMA domain.

## Remarks

## See also