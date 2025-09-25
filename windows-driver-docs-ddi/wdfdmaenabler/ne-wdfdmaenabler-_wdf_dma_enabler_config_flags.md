# _WDF_DMA_ENABLER_CONFIG_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_DMA_ENABLER_CONFIG_FLAGS** enumeration type defines flags that are used in a driver's [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure.

## Constants

### `WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION:0x00000001`

 The WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION flag applies only to the following DMA profiles:

* WdfDmaProfileScatterGather
* WdfDmaProfileScatterGather64
* WdfDmaProfileScatterGatherDuplex
* WdfDmaProfileScatterGather64Duplex

By default, when **WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION** is not set and the [WDF_DMA_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_profile) is one of those in the previous list, WDF
creates a lookaside list of scatter/gather lists that is used by this DMA adapter's transaction
objects. The list entries are initialized to allow the maximum specified
transfer length. When the transaction is executed, WDF calls the [BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list) entry function. Forward progress drivers
must not set this flag and must use one of the four profiles shown previously.

 When **WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION** is set and the [WDF_DMA_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_profile) is one of those in the previous list, WDF does not create a lookaside list. When the transaction is executed, WDF calls [GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list).

Setting **WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION** can result in reduced memory usage, particularly when the maximum transfer length is large. However, setting this flag may cause failure to perform DMA operations in low memory conditions. To guarantee forward progress when **WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION** is set, a driver might use a separate DMA enabler, or bounce transfers through a common buffer.

### `WDF_DMA_ENABLER_CONFIG_REQUIRE_SINGLE_TRANSFER:0x00000002`

The **WDF_DMA_ENABLER_CONFIG_REQUIRE_SINGLE_TRANSFER** flag is available starting in version 1.19 of KMDF. This flag also requires DMA version 3.
To select DMA version 3, set the **WdmDmaVersionOverride** member of [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) to 3.

This flag applies to all DMA profiles. When it is set, WDF does not fragment any WDFDMATRANSACTION created with this enabler into multiple DMA transfers. If this is not possible, attempts to initialize or execute the transaction fail. This option is intended for devices that need to receive all data in a single DMA operation.

Drivers also have the option of specifying this on a per-transaction level with [WdfDmaTransactionSetSingleTransferRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetsingletransferrequirement).

For more info, see [Using Single Transfer DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-single-transfer-dma).

## Remarks

You can specify a valid bitwise OR of the values on this page for the **Flags** member of the [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure.

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WDF_DMA_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_profile)

[WdfDmaTransactionSetSingleTransferRequirement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetsingletransferrequirement)