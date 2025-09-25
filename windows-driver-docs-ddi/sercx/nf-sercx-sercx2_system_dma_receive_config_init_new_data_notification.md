# SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION function

## Description

The **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION** function initializes a [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config) structure.

## Parameters

### `Config` [out]

A pointer to the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config) structure that is to be initialized.

### `MaximumTransferLength` [in]

The value to load into the **MaximumTransferLength** member of the **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG** structure. For more information, see the description of the **MaximumTransferLength** member in [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

### `Address` [in]

The value to load into the **DeviceAddress** member of the **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

### `DmaWidth` [in]

The value to load into the **DmaWidth** member of the **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

### `DmaDescriptor` [in]

The value to load into the **DmaDescriptor** member of the **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

### `EvtSerCx2SystemDmaReceiveEnableNewDataNotification` [in]

The value to load into the **EvtSerCx2SystemDmaReceiveEnableNewDataNotification** member of the **SERCX2_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

### `EvtSerCx2SystemDmaReceiveCancelNewDataNotification` [in]

The value to load into the **EvtSerCx2SystemDmaReceiveCancelNewDataNotification** member of the **SERCX2_CONFIG** structure. For more information, see the description of this member in [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config).

## Remarks

Your serial controller driver must use either this function or the [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init) function to initialize a [SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config) structure before passing a pointer to this structure as an input parameter to the [SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate) method.

**SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION** sets the **Size** member of the structure to **sizeof**(**SERCX2_SYSTEM_DMA_RECEIVE_CONFIG**), and sets six additional members of the structure to the values supplied as input parameters to the function. The function sets the other members of the structure to zero. The driver can, if necessary, explicitly set these other members to nonzero values after the **SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION** call.

## See also

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx2_system_dma_receive_config)

[SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2_system_dma_receive_config_init)

[SerCx2SystemDmaReceiveCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2systemdmareceivecreate)