# SerCx2SystemDmaReceiveGetDmaEnabler function

## Description

The **SerCx2SystemDmaReceiveGetDmaEnabler** method gets the DMA enabler for the system DMA controller that is used for system-DMA-receive transactions.

## Parameters

### `SystemDmaReceive` [in]

A [SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles) handle to a system-DMA-receive object. The serial controller driver previously called the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method to create this object.

## Return value

This method returns a WDFDMAENABLER handle to the framework DMA enabler object that represents the system DMA controller that is used for system-DMA-receive transactions.

## Remarks

If necessary, your serial controller driver can call this method to configure special features in the system DMA controller. The driver can use the DMA enabler returned by this method to specify DMA settings that were not supplied in the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config) structure that the driver previously passed as an input parameter to the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method. Or, the driver can use the DMA enabler to change the DMA settings that were previously specified in this structure.

For more information about DMA enabler objects, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions). For more information about system-DMA-receive transactions, see [SerCx2 System-DMA-Receive Transactions](https://learn.microsoft.com/previous-versions/dn265343(v=vs.85)).

## See also

[SERCX2SYSTEMDMARECEIVE](https://learn.microsoft.com/windows-hardware/drivers/serports/sercx2-object-handles)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)