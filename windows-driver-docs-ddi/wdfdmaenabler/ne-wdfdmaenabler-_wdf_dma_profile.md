# _WDF_DMA_PROFILE enumeration

## Description

[Applies to KMDF only]

The **WDF_DMA_PROFILE** enumeration identifies the types of bus-master or system-mode DMA operations that devices can support.

## Constants

### `WdfDmaProfileInvalid:0`

For internal use only.

### `WdfDmaProfilePacket`

The device supports single-packet DMA operations, using 32-bit addressing.

### `WdfDmaProfileScatterGather`

The device supports packet-based, scatter/gather DMA operations, using 32-bit addressing.

### `WdfDmaProfilePacket64`

The device supports single-packet DMA operations, using 64-bit addressing.

### `WdfDmaProfileScatterGather64`

The device supports packet-based, scatter/gather DMA operations, using 64-bit addressing.

### `WdfDmaProfileScatterGatherDuplex`

The device supports packet-based, scatter/gather DMA operations, using 32-bit addressing. The device also supports duplex operation.

### `WdfDmaProfileScatterGather64Duplex`

The device supports packet-based, scatter/gather DMA operations, using 64-bit addressing. The device also supports duplex operation.

### `WdfDmaProfileSystem`

The device supports system-mode DMA operations. This value is available in version 1.11 and later versions of KMDF running on Windows 8 or later versions of Windows.

### `WdfDmaProfileSystemDuplex`

The device supports system-mode DMA operations. The device also supports duplex operation. This value is available in version 1.11 and later versions of KMDF running on Windows 8 or later versions of Windows.

## Remarks

**WDF_DMA_PROFILE**-typed values are used within the driver's [WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config) structure. The driver supplies **WDF_DMA_ENABLER_CONFIG** when it calls [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate).

If the driver selects one of the system-mode DMA profiles, the framework requests the DMA version 3 interface from WDM. System-mode DMA is available starting in Windows 8. For more information about system-mode DMA, see [Supporting System-Mode DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-mode-dma).

Kernel-Mode Driver Framework (KMDF) miniport drivers such as NDIS miniport drivers can request the system-mode DMA profiles. For information about how to write a framework-based miniport driver, see [Creating Framework-based Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-kmdf-miniport-drivers).

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)