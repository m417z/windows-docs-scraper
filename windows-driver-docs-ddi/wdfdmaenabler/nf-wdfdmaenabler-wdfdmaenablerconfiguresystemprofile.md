# WdfDmaEnablerConfigureSystemProfile function

## Description

[Applies to KMDF only]

 The **WdfDmaEnablerConfigureSystemProfile** method
configures the hardware-specific settings for a system-mode DMA enabler and completes the resource initialization.

## Parameters

### `DmaEnabler` [in]

A handle to a DMA enabler object.

### `ProfileConfig` [in]

A pointer to a [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config) structure. Drivers must initialize this structure by calling [WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_system_profile_config_init).

### `ConfigDirection` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value that specifies the direction of the DMA transfer operation. If the [WDF_DMA_PROFILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_profile) value for this enabler is not **WdfDmaProfileSystemDuplex**, the framework ignores this parameter.

## Return value

**WdfDmaEnablerConfigureSystemProfile** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The driver requested a DMA configuration that is not supported on the current operating system. |
| **STATUS_INVALID_PARAMETER** | The driver supplied NULL in the *ProfileConfig* parameter. |
| **STATUS_INFO_LENGTH_MISMATCH** | The **Size** member of the structure pointed to by the *ProfileConfig* parameter is not equal to the size of the [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config) structure. |
| **STATUS_INVALID_PARAMETER** | The **DmaDescriptor** member of the structure pointed to by the *ProfileConfig* parameter is NULL or the *ConfigDirection* parameter contains an invalid value. |

## Remarks

Before calling **WdfDmaEnablerConfigureSystemProfile**, the driver must call [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate) to create the enabler object.

A driver typically calls **WdfDmaEnablerConfigureSystemProfile** from its [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function.

If your driver specified a duplex profile when it called [WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate), the **WdfDmaEnablerConfigureSystemProfile** method's *ConfigDirection* parameter's value must be **WdfDmaDirectionReadFromDevice** to obtain the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure for read operations and **WdfDmaDirectionWriteToDevice** to obtain the **DMA_ADAPTER** structure for write operations.

If the DMA enabler is a duplex enabler, the driver must initialize a particular direction before it can use it.

 If your driver did not specify a duplex profile, the driver can specify either **WdfDmaDirectionReadFromDevice** or **WdfDmaDirectionWriteToDevice**.

#### Examples

The following code example is from a driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. This example initializes a [WDF_DMA_SYSTEM_PROFILE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_system_profile_config) structure and calls **WdfDmaEnablerConfigureSystemProfile**.

```cpp

WDF_DMA_SYSTEM_PROFILE_CONFIG systemDmaConfig;
PHYSICAL_ADDRESS pa;

pa.QuadPart = 0;

WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT(&systemDmaConfig,
                                   pa,
                                   Width8Bits,
                                   partial);

systemDmaConfig.DemandMode = true;

ntStatus = WdfDmaEnablerConfigureSystemProfile(fdoExtension->DmaEnabler,
                                               &systemDmaConfig,
                                               WdfDmaDirectionReadFromDevice);

```

## See also

[WDF_DMA_ENABLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ns-wdfdmaenabler-_wdf_dma_enabler_config)

[WDF_DMA_ENABLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_enabler_config_init)

[WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdf_dma_system_profile_config_init)

[WdfDmaEnablerCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/nf-wdfdmaenabler-wdfdmaenablercreate)