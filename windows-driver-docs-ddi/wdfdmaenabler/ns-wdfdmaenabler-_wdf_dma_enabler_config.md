# _WDF_DMA_ENABLER_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_DMA_ENABLER_CONFIG** structure supplies characteristics for a DMA enabler object.

## Members

### `Size`

The size, in bytes, of this structure.

### `Profile`

A [WDF_DMA_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_profile)-typed value, which identifies the type of bus-master DMA operation that will be associated with the DMA enabler object.

### `MaximumLength`

The default maximum size, in bytes, that the device can handle in a single [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers). (Drivers can override this default value for individual [DMA transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers) by calling [WdfDmaTransactionSetMaximumLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetmaximumlength).) If your driver must run on versions of Microsoft Windows operating systems that support a maximum of 16 [map registers](https://learn.microsoft.com/windows-hardware/drivers/kernel/map-registers), **MaximumLength** must be less than 65,536.

### `EvtDmaEnablerFill`

A pointer to the driver's [EvtDmaEnablerFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_fill) event callback function, or **NULL**.

### `EvtDmaEnablerFlush`

A pointer to the driver's [EvtDmaEnablerFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_flush) event callback function, or **NULL**.

### `EvtDmaEnablerDisable`

A pointer to the driver's [EvtDmaEnablerDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_disable) event callback function, or **NULL**.

### `EvtDmaEnablerEnable`

A pointer to the driver's [EvtDmaEnablerEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_enable) event callback function, or **NULL**.

### `EvtDmaEnablerSelfManagedIoStart`

A pointer to the driver's [EvtDmaEnablerSelfManagedIoStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_selfmanaged_io_start) event callback function, or **NULL**.

### `EvtDmaEnablerSelfManagedIoStop`

A pointer to the driver's [EvtDmaEnablerSelfManagedIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_selfmanaged_io_stop) event callback function, or **NULL**.

### `AddressWidthOverride`

Set to zero to accept the address width specified in **Profile**. A driver can override the **Profile** address width by setting this member to a value between 24 and 63. If your driver specifies a system-mode DMA profile, **AddressWidthOverride** must be zero. If your driver specifies a 32-bit DMA profile, **AddressWidthOverride** cannot be greater than 32. The **AddressWidthOverride** member is available in version 1.11 and later versions of KMDF. See more information in **Remarks**.

### `Flags`

A bitwise OR of one or more values from the [WDF_DMA_ENABLER_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_enabler_config_flags) enumeration. The **Flags** member is available in version 1.11 and in later versions of KMDF.

### `WdmDmaVersionOverride`

Set to zero to accept the default DMA version. To request DMA version 3, set to 3. The **WdmDmaVersionOverride** member is available in version 1.11 and in later versions of KMDF. DMA version 3 is available starting in Windows 8.

## Remarks

The **WDF_DMA_ENABLER_CONFIG** structure is used as an input parameter to the [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate) method.

Drivers must call [WDF_DMA_ENABLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_enabler_config_init) to initialize the **WDF_DMA_ENABLER_CONFIG** structure.

In Windows 8 and later, when the driver provides a nonzero value for **AddressWidthOverride**, the framework requests DMA version 3 and passes the **AddressWidthOverride** value through to the HAL.

On Windows 7 and Windows Vista, when the driver provides a nonzero value for **AddressWidthOverride**, the framework uses either 32-bit or 24-bit DMA. For example, if the driver specifies a 64-bit profile and provides an **AddressWidthOverride** of 32, the framework uses 32-bit DMA. If the driver specifies a 32-bit profile and provides an **AddressWidthOverride** of 24, the framework uses 24-bit DMA.

## See also

[EvtDmaEnablerDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_disable)

[EvtDmaEnablerEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_enable)

[EvtDmaEnablerFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_fill)

[EvtDmaEnablerFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_flush)

[EvtDmaEnablerSelfManagedIoStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_selfmanaged_io_start)

[EvtDmaEnablerSelfManagedIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nc-wdfdmaenabler-evt_wdf_dma_enabler_selfmanaged_io_stop)

[WDF_DMA_ENABLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_enabler_config_init)

[WDF_DMA_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_profile)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)

[WdfDmaTransactionSetMaximumLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsetmaximumlength)