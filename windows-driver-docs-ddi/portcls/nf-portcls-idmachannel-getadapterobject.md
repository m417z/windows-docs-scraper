# IDmaChannel::GetAdapterObject

## Description

The GetAdapterObject method returns the DMA channel's hardware adapter object.

## Return value

This method returns PADAPTER_OBJECT. It returns a pointer to the DMA-channel object's internal adapter object, which is a DMA_ADAPTER structure.

## Remarks

The method returns a pointer to a DMA adapter object that has a system-defined interface to the DMA operations that the hardware supports. The adapter driver can pass this pointer as a parameter to the AllocateCommonBuffer and FreeCommonBuffer functions if the miniport driver needs to allocate its own physically contiguous memory for common buffer blocks. These blocks can be accessed both by DMA hardware and by software running on the processor.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)