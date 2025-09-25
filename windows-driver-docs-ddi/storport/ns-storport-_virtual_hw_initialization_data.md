# VIRTUAL_HW_INITIALIZATION_DATA structure

## Description

The **VIRTUAL_HW_INITIALIZATION_DATA** structure contains information particular to each virtual miniport driver.

## Members

### `HwInitializationDataSize`

Specifies the size of this structure in bytes, as returned by **sizeof**(). This member indicates the version of this structure that is used by the virtual miniport driver. A virtual miniport driver's **DriverEntry** routine should set this member's value for the port driver.

### `AdapterInterfaceType`

For storport virtual miniport drivers, the value for **AdapterInterfaceType** will almost always be **internal**. This is because the Storport driver does not support legacy buses.

Note that because of this, most of the adapter interface types that are used with the SCSI port driver are invalid for Storport drivers. In particular, Storport does not support:

* Isa
* Eisa
* MicroChannel
* TurboChannel

Additionally, unlike the SCSI port case, a virtual miniport driver that works with the Storport driver is not required to supply values for the following members:

* **VendorIdLength**
* **VendorId**
* **DeviceIdLength**
* **DeviceId**

### `HwInitialize`

A pointer to the virtual miniport driver's [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine, which is a required entry point for all virtual miniport drivers.

### `HwStartIo`

A pointer to the virtual miniport driver's [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine, which is a required entry point for all virtual miniport drivers.

### `HwInterrupt`

Not used. Virtual miniport drivers do not process interrupts.

### `HwFindAdapter`

A pointer to the virtual miniport driver's [**VirtualHwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-virtual_hw_find_adapter) routine, which is a required entry point for all virtual miniport drivers.

### `HwResetBus`

A pointer to the virtual miniport driver's [**HwStorResetBus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus) routine, which is a required entry point for all virtual miniport drivers.

### `HwDmaStarted`

Not used. Virtual miniport drivers do not perform DMA.

### `HwAdapterState`

The Storport driver does not support legacy drivers. Therefore, this member must be **NULL**.

### `DeviceExtensionSize`

Specifies the size, in bytes, that is required by the virtual miniport driver for its per-adapter non-paged device extension. A virtual miniport driver uses its device extension as storage for driver-determined adapter information. The operating system-specific port driver initializes each device extension that it allocates with zeros, and passes a pointer to the adapter-specific device extension in most calls to the virtual miniport driver. The given size does not include any virtual miniport driver-requested per-logical-unit storage.

### `SpecificLuExtensionSize`

Specifies the size, in bytes, that is required by the virtual miniport driver for its per-logical-unit non-paged storage, if any. A virtual miniport driver can use its logical unit (LU) extensions as storage for driver-determined LU information about peripherals on the virtual bus. The operating system-specific port driver initializes each LU extension that it allocates with zeros. Leave this member set to zero if the virtual miniport driver does not maintain per-LU information for which it requires storage.

### `SrbExtensionSize`

Specifies the size, in bytes, that is required by the virtual miniport driver for its per-request non-paged storage, if any. Because virtual miniport drivers that work with the Storport driver must support scatter/gather lists, and the per-SRB scatter/gather lists are usually allocated in the SRB extension, this member is rarely zero.

### `NumberOfAccessRanges`

Not used. Virtual miniport drivers do not support hardware.

### `Reserved`

Reserved for system use.

### `MapBuffers`

| Name | Description |
| -- | -- |
| STOR_MAP_NO_BUFFERS | Only maps buffer for SRB_FUNCTION_IO_CONTROL and SRB_FUNCTION_WMI. |
| STOR_MAP_ALL_BUFFERS | Obsolete, same behavior as STOR_MAP_NON_READ_WRITE_BUFFERS. |
| STOR_MAP_NON_READ_WRITE_BUFFERS | Maps buffer for IO requests except READ and WRITE. |
| STOR_MAP_ALL_BUFFERS_INCLUDING_READ_WRITE | Maps buffer for all IO requests including READ and WRITE. Miniport drivers will typically use this setting. |

### `NeedPhysicalAddresses`

Not used. Virtual miniport drivers do not support hardware.

### `TaggedQueuing`

Must be set to **TRUE**. A value of **TRUE** indicates that the virtual miniport driver supports tagged queuing.

### `AutoRequestSense`

Must be set to **TRUE**. A value of **TRUE** indicates that the HBA can perform a request-sense operation without requiring an explicit request to do so.

### `MultipleRequestPerLu`

Must be set to **TRUE**. A value of **TRUE** indicates that the virtual miniport driver can queue multiple requests per logical unit (LU).

### `ReceiveEvent`

This value is no longer used, and can be set to either **TRUE** or **FALSE**.

### `VendorIdLength`

The length, in bytes, of the vendor identifier.

### `VendorId`

The vendor identifier.

### `ReservedUshort`

Reserved.

### `PortVersionFlags`

A bitmap of flags that indicate the features that the port driver supports. Currently, the only flag available is SP_VER_TRACE_SUPPORT, which indicates that the port driver supports tracing.

### `DeviceIdLength`

The length, in bytes, of the device identifier.

### `DeviceId`

The device identifier.

### `HwAdapterControl`

A pointer to the virtual miniport driver's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine.

### `HwBuildIo`

This member is not used.

### `HwFreeAdapterResources`

A pointer to the virtual miniport driver's [**HwStorFreeAdapterResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_free_adapter_resources) routine, which is a required entry point for all virtual miniport drivers.

### `HwProcessServiceRequest`

A pointer to the virtual miniport driver's [**HwStorProcessServiceRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request) routine.

### `HwCompleteServiceIrp`

A pointer to the virtual miniport driver's [**HwStorCompleteServiceIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_complete_service_irp) routine.

### `HwInitializeTracing`

A pointer to the virtual miniport driver's [**HwStorInitializeTracing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize_tracing) routine.

### `HwCleanupTracing`

A pointer to the virtual miniport driver's [**HwStorCleanupTracing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_cleanup_tracing) routine.

## Remarks

If a virtual miniport driver will execute only on Windows 8 or later, the driver should use the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1) structure instead of **VIRTUAL_HW_INITIALIZATION_DATA**.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorCleanupTracing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_cleanup_tracing)

[**HwStorCompleteServiceIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_complete_service_irp)

[**HwStorFreeAdapterResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_free_adapter_resources)

[**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)

[**HwStorInitializeTracing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize_tracing)

[**HwStorProcessServiceRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request)

[**HwStorResetBus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus)

[**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio)

[**VirtualHwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-virtual_hw_find_adapter)