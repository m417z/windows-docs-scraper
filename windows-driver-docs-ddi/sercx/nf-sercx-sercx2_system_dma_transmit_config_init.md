# SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT function

## Description

The **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT** function initializes a [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config) structure that is to be initialized.

### `MaximumTransferLength` [in]

The value to load into the **MaximumTransferLength** member of the **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config).

### `Address` [in]

The value to load into the **DeviceAddress** member of the **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config).

### `DmaWidth` [in]

The value to load into the **DmaWidth** member of the **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config).

### `DmaDescriptor` [in]

The value to load into the **DmaDescriptor** member of the **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config).

## Remarks

Your serial controller driver must use this function to initialize a [SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate) method.

**SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT** sets the **Size** member of the structure to **sizeof**(**SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG**), and sets four additional members of the structure to the values supplied as input parameters to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT** call.

## See also

[SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_transmit_config)

[SerCx2SystemDmaTransmitCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmatransmitcreate)