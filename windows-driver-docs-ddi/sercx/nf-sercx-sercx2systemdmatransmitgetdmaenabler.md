# SerCx2SystemDmaTransmitGetDmaEnabler function

## Description

The **SerCx2SystemDmaTransmitGetDmaEnabler** method gets the DMA enabler for the system DMA controller that is used for system-DMA-transmit transactions.

## Parameters

### `SystemDmaTransmit` [in]

A [SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-transmit object. The serial controller driver previously called the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method to create this object.

## Return value

This method returns a WDFDMAENABLER handle to the framework DMA enabler object that represents the system DMA controller that is used for system-DMA-transmit transactions.

## Remarks

If necessary, your serial controller driver can call this method to configure special features in the system DMA controller. The driver can use the DMA enabler returned by this method to specify DMA settings that were not supplied in the [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config) structure that the driver previously passed as an input parameter to the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method. Or, the driver can use the DMA enabler to change the DMA settings that were previously specified in this structure.

For more information about DMA enabler objects, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions). For more information about system-DMA-transmit transactions, see [SerCx2 System-DMA-Transmit Transactions](https://learn.microsoft.com/previous-versions/dn265338(v=vs.85)).

## See also

[SERCX2SYSTEMDMATRANSMIT](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)