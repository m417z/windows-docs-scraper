# HW_INITIALIZATION_DATA structure

## Description

The **HW_INITIALIZATION_DATA (Storport)** structure contains information particular to each miniport driver and the hardware that the miniport driver manages.

## Members

### `HwInitializationDataSize`

Specifies the size of this structure in bytes, as returned by **sizeof**(HW_INITIALIZATION_DATA). In effect, this member indicates the version of this structure being used by the miniport driver. A miniport driver's DriverEntry routine should set this member's value for the port driver.

### `AdapterInterfaceType`

The Storport driver does not support legacy buses. Therefore, most of the adapter interface types used with the SCSI Port driver are invalid for Storport. In particular, **Isa**, **Eisa**, **MicroChannel**, and **TurboChannel** are not supported. Furthermore, unlike the SCSI Port case, a miniport driver that works with the Storport driver is not required to supply values for the **VendorIdLength**, **VendorId**, **DeviceIdLength**, and **DeviceId** members.

### `HwInitialize`

Pointer to the miniport driver's [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine, which is a required entry point for all miniport drivers.

### `HwStartIo`

Pointer to the miniport driver's [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine, which is a required entry point for all miniport drivers.

### `HwInterrupt`

Pointer to the miniport driver's [**HwStorInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt) routine, which is a required entry point for all miniport drivers.

### `HwFindAdapter`

Pointer to the miniport driver's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine, which is a required entry point for all miniport drivers.

### `HwResetBus`

Pointer to the miniport driver's [**HwStorResetBus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus) routine, which is a required entry point for all miniport drivers.

### `HwDmaStarted`

The Storport driver does not support subordinate-mode DMA. Therefore, this member must be **NULL**.

### `HwAdapterState`

The Storport driver does not support legacy drivers. Therefore, this member must be **NULL**.

### `DeviceExtensionSize`

Specifies the size, in bytes, required by the miniport driver for its per-adapter device extension. A miniport driver uses its device extension as storage for driver-determined host bus adapter (HBA) information. The operating system-specific port driver initializes each device extension one time, when it first allocates the extension and fills it with zeros. It passes a pointer to the HBA-specific device extension in every call to a miniport driver. The given size does not include any miniport driver-requested per-logical-unit storage. The size of per-logical-unit storage is specified via the **SpecificLuExtensionSize** field, described later in this topic.

Although SCSIPort re-initializes the device extension whenever the adapter is stopped and thus subsequent calls to [**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) receive a zeroed-out device extension, Storport does not follow that model. Rather, Storport resets the device extension to zero only when it is first allocated, so only the first call to [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) for a given adapter receives a zeroed-out device extension. Subsequent calls to **HwStorFindAdapter** and other miniport functions receive the device extension as last modified by the miniport. This allows the miniport driver to maintain knowledge about the state of the adapter between Plug and Play (PnP) stops and restarts, possibly enabling the miniport driver to optimize its initialization procedure.

### `SpecificLuExtensionSize`

Specifies the size in bytes required by the miniport driver for its per-logical-unit storage, if any. A miniport driver can use its LU extensions as storage for driver-determined logical-unit information about peripherals on the bus. The Storport driver initializes each LU extension it allocates with zeros. Leave this member set to zero if the miniport driver does not maintain per-LU information for which it requires storage. This value is based on the assumption that the HBA is able to receive 32-bit addresses, regardless of what the controller can actually support. If additional space is needed in the LUN or SRB extensions to handle 64-bit addresses, then appropriate adjustments must be made to this value before using it with routines such as [**StorPortGetUncachedExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetuncachedextension).

### `SrbExtensionSize`

Specifies the size, in bytes, required by the miniport driver for its per-request storage, if any. A miniport driver can use SRB extensions as storage for driver-determined, request-specific information, such as data necessary to process a particular request. The Storport driver does not initialize SRB extensions, but sets a pointer to this storage in each SRB it sends to the miniport driver. An SRB extension can be safely accessed by the HBA hardware. Because miniport drivers that work with the Storport driver must support scatter/gather lists, and the per-SRB scatter/gather lists are usually allocated in the SRB extension, this member is rarely zero. Leave this member set to zero if the miniport driver does not maintain per-SRB information for which it requires storage.

This value is based on the assumption that the HBA is able to receive 32-bit addresses, regardless of what the controller can actually support. If additional space is needed in the LUN or SRB extensions to handle 64-bit addresses, then appropriate adjustments must be made to this value before using it with routines such as [**StorPortGetUncachedExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetuncachedextension).

### `NumberOfAccessRanges`

Specifies how many access ranges the adapter uses. Each is a range either of memory addresses or I/O port addresses.

### `Reserved`

Reserved for system use and not available for use by miniport drivers.

### `MapBuffers`

Indicates whether the Storport driver maps SRB data buffer addresses to system virtual addresses. The **MapBuffers** member can have one of the following values.

| Value | Meaning |
| ----- | ------- |
| **STOR_MAP_NO_BUFFERS** (0) | Do not map for any SRB except SRB_FUNCTION_IO_CONTROL and SRB_FUNCTION_WMI. |
| **STOR_MAP_ALL_BUFFERS** (1) | Obsolete. This value has the same effect as STOR_MAP_NON_READ_WRITE_BUFFERS. |
| **STOR_MAP_NON_READ_WRITE_BUFFERS** (2) | Map the buffer for all I/O except for read or write requests. |
| **STOR_MAP_ALL_BUFFERS_INCLUDING_READ_WRITE** (3) | Map the buffer for all I/O including read and write requests. This value is valid starting with Windows 8. |

### `NeedPhysicalAddresses`

Must be set to **TRUE**. A value of **TRUE** indicates that the miniport driver must translate certain types of addresses to physical addresses. Miniport drivers that work with the Storport driver must support bus-master DMA, so they will always be required to do address translation.

### `TaggedQueuing`

Must be set to **TRUE**. A value of **TRUE** indicates that the miniport driver supports SCSI tagged queuing. All miniport drivers that work with the Storport driver must support tagged queuing.

### `AutoRequestSense`

Must be **TRUE**. A value of **TRUE** indicates that the HBA can perform a request-sense operation without requiring an explicit request to do so. All miniport drivers that work with the Storport driver must support SCSI Auto-Request Sense.

### `MultipleRequestPerLu`

Must be set to **TRUE**. A value of **TRUE** indicates that the miniport driver can queue multiple requests per logical unit. Miniport drivers that work with the Storport driver must support multiple requests per logical unit.

### `ReceiveEvent`

The Storport driver ignores this member.

### `VendorIdLength`

The Storport driver ignores this member, because miniport drivers that work with the Storport driver must support PnP.

### `VendorId`

The Storport driver ignores this member, because miniport drivers that work with the Storport driver must support PnP.

### `ReservedUshort`

### `PortVersionFlags`

Flags to indicate supported features.

### `DeviceIdLength`

The Storport driver ignores this member, because miniport drivers that work with the Storport driver must support PnP.

### `DeviceId`

The Storport driver ignores this member, because miniport drivers that work with the Storport driver must support PnP.

### `HwAdapterControl`

Pointer to the miniport driver's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine. This is a required routine because miniport drivers that work with the Storport driver require PnP support.

### `HwBuildIo`

Pointer to an optional [**HwStorBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) routine that the port driver calls to do unsynchronized processing prior to calling the miniport driver's [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine. This callback is specific to physical miniports and should be set to NULL by virtual miniports.

### `HwFreeAdapterResources`

A pointer to the virtual miniport driver's [**HwStorFreeAdapterResources**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_free_adapter_resources) routine, which is a required entry point for all virtual miniport drivers. This callback is specific to virtual miniports and is set to **NULL** for physical miniports.

This callback is added in Windows 8. Virtual miniports for previous versions of Windows should use [**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data) instead of this structure.

### `HwProcessServiceRequest`

A pointer to the virtual miniport driver's [**HwStorProcessServiceRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_process_service_request) routine. This callback is specific to virtual miniports and is set to **NULL** for physical miniports.

This callback is added in Windows 8. Virtual miniports for previous versions of Windows should use [**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data) instead of this structure.

### `HwCompleteServiceIrp`

A pointer to the virtual miniport driver's [**HwStorCompleteServiceIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_complete_service_irp) routine. This callback is specific to virtual miniports and is set to **NULL** for physical miniports.

This callback is added in Windows 8. Virtual miniports for previous versions of Windows should use [**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data) instead of this structure.

### `HwInitializeTracing`

A pointer to the virtual miniport driver's [**HwStorInitializeTracing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize_tracing) routine. This callback is specific to virtual miniports and is set to **NULL** for physical miniports.

This callback is added in Windows 8. Virtual miniports for previous versions of Windows should use [**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data) instead of this structure.

### `HwCleanupTracing`

A pointer to the virtual miniport driver's [**HwStorCleanupTracing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_cleanup_tracing) routine. This callback is specific to virtual miniports and is set to **NULL** for physical miniports.

This callback is added in Windows 8. Virtual miniports for previous versions of Windows should use [**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data) instead of this structure.

### `HwTracingEnabled`

A pointer to an optional [**HwStorTracingEnabled**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_tracing_enabled) routine that the port driver calls to notify the miniport of whether tracing is enabled or not.

### `FeatureSupport`

Flags indicating features that are supported by the miniport. **FeatureSupport** is set to a combination of these values:

| Value | Meaning |
| ----- | ------- |
| **STOR_FEATURE_VIRTUAL_MINIPORT** (0x00000001) | This is a virtual miniport driver. |
| **STOR_FEATURE_ATA_PASS_THROUGH** (0x00000002) | The miniport supports ATA pass through. |
| **STOR_FEATURE_FULL_PNP_DEVICE_CAPABILITIES** (0x00000004) | The miniport provides complete settings in its **STOR_DEVICE_CAPABILITIES_EX** structure. |
| **STOR_FEATURE_DUMP_POINTERS** (0x00000008) | The miniport supports the dump pointer SRBs. |
| **STOR_FEATURE_DEVICE_NAME_NO_SUFFIX** (0x00000010) | The miniport driver does not want the suffix "SCSI *type* Device" as part of the device friendly name. |
| **STOR_FEATURE_DUMP_RESUME_CAPABLE** (0x00000020) | The miniport's dump capability is functional for resume from hibernation. |
| **STOR_FEATURE_DEVICE_DESCRIPTOR_FROM_ATA_INFO_VPD** (0x00000040) | The Storport driver initializes the [**STORAGE_DEVICE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_descriptor) from the ATA Information VPD page instead of from INQUIRY data. |
| **STOR_FEATURE_EXTRA_IO_INFORMATION** (0x00000080) | The miniport driver wants SRBEX_DATA_IO_INFO in a SRBEX if available. |
| **STOR_FEATURE_ADAPTER_CONTROL_PRE_FINDADAPTER** (0x00000100) | The miniport driver can safely process AdapterControl call from Storport before receiving HwFindAdapter. |
| **STOR_FEATURE_ADAPTER_NOT_REQUIRE_IO_PORT** (0x00000200) | The miniport driver doesn't require IO Port resource for its adapter. |
| **STOR_FEATURE_DUMP_16_BYTE_ALIGNMENT** (0x00000400) | The miniport driver wants its HwDeviceExtension to be 16 byte aligned in dump mode. |
| **STOR_FEATURE_SET_ADAPTER_INTERFACE_TYPE** (0x00000800) | The miniport wants Storport to set the adapter interface type. |
| **STOR_FEATURE_DUMP_INFO** (0x00001000) | The miniport driver supports the dump info SRBs. |
| **STOR_FEATURE_DMA_ALLOCATION_NO_BOUNDARY** (0x00002000) | The miniport driver supports to allocate DMA to physical memory without boundaries. |
| **STOR_FEATURE_SUPPORTS_NVME_ADAPTER** (0x00004000) | The miniport driver supports NVMe based Storage Adapters. |
| **STOR_FEATURE_REPORT_INTERNAL_DATA** (0x00008000) | The miniport driver supports reporting internal data. |
| **STOR_FEATURE_EARLY_DUMP** (0x00010000) | The miniport driver supports early crash dump generation. |
| **STOR_FEATURE_NVME_ICE** (0x00020000) | The miniport driver supports NVMe ICE. |

### `SrbTypeFlags`

Flags indicating the SRB types supported by the miniport. **SrbTypeFlags** is set to 0 or a combination of the following values:

| Value | Meaning |
| ----- | ------- |
| **SRB_TYPE_FLAG_SCSI_REQUEST_BLOCK** (0x1) | The miniport uses standard SRBs. |
| **SRB_TYPE_FLAG_STORAGE_REQUEST_BLOCK** (0x2) | The miniport supports extended SRBs. |

### `AddressTypeFlags`

The address schemes supported by the miniport. Currently, the only one address scheme is supported and the miniport must set this member to ADDRESS_TYPE_FLAG_BTL8.

| Value | Meaning |
| ----- | ------- |
| **ADDRESS_TYPE_FLAG_BTL8** (0x1) | Bus, Target, and LUN (BTL) 8-bit addressing. |

### `Reserved1`

Reserved, set to 0.

### `HwUnitControl`

A pointer the miniport driver's **HwStorUnitControl** routine. The port driver calls this routine with a control request for a storage unit device.

## Remarks

Every Storport miniport driver's **DriverEntry** routine must call [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize) after the miniport driver has first zeroed and then set the members of **HW_INITIALIZATION_DATA**.