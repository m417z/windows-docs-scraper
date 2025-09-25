# PORT_CONFIGURATION_INFORMATION structure (storport.h)

## Description

**PORT_CONFIGURATION_INFORMATION** contains configuration information for a host bus adapter (HBA).

## Members

### `Length`

Size, in bytes, of the **PORT_CONFIGURATION_INFORMATION** structure. Initialized by the Storport driver, this member also serves as the structure version.

### `SystemIoBusNumber`

System-assigned number of the I/O bus to which the HBA is connected. Miniport drivers must not modify this member. Its value is system-assigned because the platform might have several I/O buses of the specified **AdapterInterfaceType**.

### `AdapterInterfaceType`

The I/O bus interface. Storport initializes this member to the value specified by the miniport driver in the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1) structure. Miniport drivers must not modify this member.

### `BusInterruptLevel`

The bus-relative interrupt request level. Storport makes no assumptions about the HBA's interrupt usage, so the default value is zero. Storport initializes this member and miniport drivers must not modify it.

### `BusInterruptVector`

The bus-relative vector returned by the HBA. Storport makes no assumptions about the HBA's interrupt usage, so the default value is zero. This member is irrelevant to drivers that set up the **BusInterruptLevel** member for their HBAs. It is pertinent for HBAs on types of I/O buses that use interrupt vectors, such as **PCIBus**. Storport initializes this member and miniport drivers must not modify it.

### `InterruptMode`

Specifies whether the HBA uses **LevelSensitive** or **Latched** (sometimes called "edge-triggered") interrupts. Storport initializes this member to an appropriate value for the bus and the device--for example, **LevelSensitive** for **PCIBus**. Storport initializes this member and miniport drivers must not modify it.

### `MaximumTransferLength`

Maximum number of bytes the HBA can transfer in a single transfer operation. By default, the value of this member is SP_UNINITIALIZED_VALUE, which indicates an unlimited maximum transfer size. If its HBA has more limited transfer support, a miniport driver must reset this member according to the HBA's transfer capacity. If a miniport driver's [*HwStorInterrupt*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt) routine cannot disable interrupts on the HBA, this member can be adjusted during driver development to ensure that time spent in that miniport driver's ISR does not degrade overall system performance.

### `NumberOfPhysicalBreaks`

Maximum number of physical pages the storage adapter can manage in a single transfer (in other words, the extent of its scatter/gather support). By default, the value of this member is 0x11. The miniport driver must reset this member according to the storage adapter's capability.

### `DmaChannel`

The DMA channel used by a subordinate HBA. By default, the value of this member is SP_UNINITIALIZED_VALUE. Storport initializes this member and miniport drivers must not modify it.

### `DmaPort`

The DMA port used by a subordinate HBA. By default, the value of this member is SP_UNINITIALIZED_VALUE. Storport initializes this member and miniport drivers must not modify it.

### `DmaWidth`

Width of DMA transfers if the HBA uses DMA. By default, the value of this member is zero. Storport initializes this member and miniport drivers must not modify it.

### `DmaSpeed`

The DMA data-transfer speed for **Eisa** HBAs. Storport initializes this member and miniport drivers must not modify it.

### `AlignmentMask`

Mask indicating the alignment restrictions for buffers required by the HBA for transfer operations. Some example valid mask values are 0 (byte aligned), 1 (word aligned), 3 (DWORD aligned) and 7 (double DWORD aligned). The miniport driver should set this mask if the HBA supports scatter/gather. The following allowed alignment mask values are defined in wdm.h:

| Value | Meaning |
| ----- | ------- |
| FILE_BYTE_ALIGNMENT (0x00000000) | Data is byte aligned (no alignment requirements for the device) |
| FILE_WORD_ALIGNMENT (0x00000001) | Data must be aligned on a 2-byte boundary. |
| FILE_LONG_ALIGNMENT (0x00000003) | Data must be aligned on a 4-byte boundary. |
| FILE_QUAD_ALIGNMENT (0x00000007) | Data must be aligned on an 8-byte boundary. |
| FILE_OCTA_ALIGNMENT (0x0000000f) | Data must be aligned on a 16-byte boundary. |
| FILE_32_BYTE_ALIGNMENT (0x0000001f) | Data must be aligned on a 32-byte boundary. |
| FILE_64_BYTE_ALIGNMENT (0x0000003f) | Data must be aligned on a 64-byte boundary. |
| FILE_128_BYTE_ALIGNMENT (0x0000007f) | Data must be aligned on a 128-byte boundary. |
| FILE_256_BYTE_ALIGNMENT (0x000000ff) | Data must be aligned on a 256-byte boundary. |
| FILE_512_BYTE_ALIGNMENT (0x000001ff) | Data must be aligned on a 512-byte boundary. |

### `NumberOfAccessRanges`

Specifies the number of **AccessRanges** elements in the array.

### `AccessRanges`

Pointer to an array of [**ACCESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_access_range)-type elements. Storport allocates memory for the access ranges and initializes this member. Miniport drivers must not modify this member.

### `MiniportDumpData`

Pointer to a dump context used during a crashdump or a hibernation.

### `Reserved`

Reserved for system use (pre-Windows 8).

### `NumberOfBuses`

Number of buses controlled by the adapter. By default, the value of this member is zero. This member has a maximum value of SCSI_MAXIMUM_BUSES_PER_ADAPTER. This member is available starting in Windows 8.

### `InitiatorBusId`

The initiator bus ID. If the input **InitiatorBusId[0]** has the value SP_UNINITIALIZED_VALUE, the miniport driver can assign a default value if its HBA does not require the use of particular value(s) determined by querying the HBA. Otherwise, the miniport driver should use any nonzero value assigned by the port driver if possible. Typically, this value is bounded by the value set for **MaximumNumberOfTargets**.

### `ScatterGather`

When **TRUE**, the HBA supports scatter/gather. Storport initializes this member to **TRUE** because its miniport drivers must support scatter/gather. Miniport drivers that work with Storport must not modify this value. (NOTE: in Windows versions prior to Windows Server 2008 R2 and Windows 7, this member is set to FALSE. In this case, miniport drivers must set this member to **TRUE**. Not setting this member to **TRUE** will cause the HBA device to fail to start.)

### `Master`

When **TRUE**, the HBA is a master bus. Storport initializes this member to **TRUE** because its miniport drivers must support bus-mastering DMA. Miniport drivers that work with Storport must not modify this value. (NOTE: in Windows versions prior to Windows Server 2008 R2 and Windows 7, this member is set to FALSE. In this case, miniport drivers must set this member to **TRUE**. Not setting this member to **TRUE** will cause the HBA device to fail to start.)

### `CachesData`

When **TRUE**, the HBA caches data or maintains cached state on the peripherals. When **FALSE**, the HBA does not cache data or maintain cached state on the peripherals. By default, the value of this member is **FALSE**. If this is reset to **TRUE**, Storport notifies the miniport driver when certain system events occur, such as file system cache flushes.

### `AdapterScansDown`

Storport ignores this member.

### `AtdiskPrimaryClaimed`

Storport does not use this member, and its miniport drivers must not set it.

### `AtdiskSecondaryClaimed`

Storport does not use this member, and its miniport drivers must not set it.

### `Dma32BitAddresses`

When **TRUE**, the HBA has 32 address lines and can access memory with physical addresses greater than 0x00FFFFFF. Storport initializes this member to **TRUE**, because its miniport drivers must support bus-width DMA. Miniport drivers must not modify this value since this is the default DMA addressing if a value for **Dma64BitAddresses** is not set. NOTE: If only 32-bit addresses are supported by the device hardware, then **Dma64BitAddresses** must be set to 0.

### `DemandMode`

Indicates whether the system DMA controller should be programmed for demand-mode rather than single-cycle operations. Storport initializes this member to **FALSE**, because it does not support subordinate-mode DMA. Miniport drivers must not modify this value.

### `MapBuffers`

Indicates whether Storport maps SRB data buffer addresses to system virtual addresses. The miniport driver sets this member to one of the following values to control mapping for SRB data buffer addresses.

| Value | Meaning |
| ----- | ------- |
| STOR_MAP_NO_BUFFERS | Maps the buffer only for SRB_FUNCTION_IO_CONTROL and SRB_FUNCTION_WMI. |
| STOR_MAP_ALL_BUFFERS | Obsolete. This value has the same effect as STOR_MAP_NON_READ_WRITE_BUFFERS. |
| STOR_MAP_NON_READ_WRITE_BUFFERS | Maps the buffer for all IO except for read and write requests. |
| STOR_MAP_ALL_BUFFERS_INCLUDING_READ_WRITE | Maps the buffer for all IO including read and write requests. Miniports supporting boot must handle a read or write request of PAGE_SIZE in length. These read or write requests must always complete successfully. Storport may fail to map the buffer under low system memory conditions. In this case, the DataBuffer member in the SRB will be NULL. |

### `NeedPhysicalAddresses`

When **TRUE**, the miniport driver must translate virtual addresses to physical addresses, as required by the HBA. Storport initializes this member to TRUE, because its miniport drivers must support scatter/gather lists. Miniport must not modify this value.

### `TaggedQueuing`

When **TRUE**, the HBA supports queuing of multiple requests with SCSI tags. Storport initializes this member to **TRUE** because its miniport drivers must support tagged-queuing. Miniport drivers must not modify this value.

### `AutoRequestSense`

When **TRUE**, the HBA supports auto request sense. Storport initializes this member to **TRUE** because its miniport drivers must support auto-request sense. Miniport drivers must not modify this value.

### `MultipleRequestPerLu`

When **TRUE**, the HBA supports multiple requests per logical unit. Storport initializes this member to **TRUE** because its miniport drivers must support multiple requests issued to a logical unit at time. Miniport drivers must not modify this value.

### `ReceiveEvent`

Storport does not use this member, and its miniport drivers must not set it.

### `RealModeInitialized`

Storport does not use this member, and its miniport drivers must not set it.

### `BufferAccessScsiPortControlled`

Storport does not use this member, and its miniport drivers must not set it.

### `MaximumNumberOfTargets`

Number of target peripherals the adapter can control. By default, the value of this member is SCSI_MAXIMUM_TARGETS_PER_BUS. A miniport driver can reset this member to a lesser value if the HBA has more limited capabilities or to a greater value, indicating that the HBA has extended bus capabilities. The maximum value for this member is 255.

### `SrbType`

Type of SRBs to be sent to the miniport driver. Available starting in Windows 8. This is set to one of the following values:

| Value | Meaning |
| ----- | ------- |
| SRB_TYPE_SCSI_REQUEST_BLOCK | The miniport driver receives standard SRBs. |
| SRB_TYPE_STORAGE_REQUEST_BLOCK | The miniport driver receives extended SRBs. |

### `AddressType`

Address type used between Storport and the miniport driver. Available starting in Windows 8. This can be set to the following value:

| Value | Meaning |
| ----- | ------- |
| STORAGE_ADDRESS_TYPE_BTL8 | Bus, Target, and LUN (BTL) 8-bit addressing. |

### `ReservedUchars`

Reserved for system use (pre-Windows 8).

### `SlotNumber`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `BusInterruptLevel2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `BusInterruptVector2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `InterruptMode2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `DmaChannel2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `DmaPort2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `DmaWidth2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `DmaSpeed2`

Reserved for use by Storport. Miniport drivers must not modify this member.

### `DeviceExtensionSize`

Size, in bytes, required by the miniport driver for its per-adapter device extension. A miniport driver uses its device extension as storage for driver-determined HBA information. The operating system-specific port driver initializes each device extension one time, when it first allocates the extension, and fills it with zeros. It passes a pointer to the HBA-specific device extension in every call to a miniport driver. The given size does not include any miniport driver-requested per-logical-unit storage. The size of per-logical-unit storage is specified via the **SpecificLuExtensionSize** field, described later in this topic.

Storport does not follow SCSIPort's model (which re-initializes the device extension whenever the adapter is stopped and thus subsequent calls to [*HwScsiFindAdapter*](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) receive a zeroed-out device extension). Rather, Storport resets the device extension to zero only when it is first allocated, so only the first call to [*HwStorFindAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) for a given adapter receives a zeroed-out device extension. Subsequent calls to *HwStorFindAdapter* and other miniport functions receive the device extension as last modified by the miniport driver. This allows the miniport driver to maintain knowledge about the state of the adapter between Plug and Play (PnP) stops and restarts, possibly enabling the miniport driver to optimize its initialization procedure.

### `SpecificLuExtensionSize`

Size in bytes required by the miniport driver for its per-logical-unit-storage, if any, to handle data transfers larger than 64K. Storport initializes this member to the value in the same member of the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1) structure sent in the [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize) routine.

Set this member to zero if the miniport driver does not maintain per-LU information for which it requires storage. This value is based on the assumption that the HBA is able to receive 32-bit addresses, regardless of what the controller can actually support. If additional space is needed in the LUN or SRB extensions to handle 64-bit addresses, then appropriate adjustments must be made to this value before using it with routines such as [**StorPortGetUncachedExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetuncachedextension).

### `SrbExtensionSize`

Size in bytes required by the miniport driver for its per-request storage, if any, to handle data transfers larger than 64K. Storport initializes this member to the value in the same member of the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1) structure sent in the [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize) routine.

Set this member before calling [**StorPortGetUncachedExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetuncachedextension) to change the size of per-request storage based on **NumberOfPhysicalBreaks**. Set this member to zero if the miniport driver does not maintain per-SRB information for which it requires storage. This value is based on the assumption that the HBA is able to receive 32-bit addresses, regardless of what the controller can actually support. If additional space is needed in the LUN or SRB extensions to handle 64-bit addresses, then appropriate adjustments must be made to this value before using it with routines such as **ScsiPortGetUncachedExtension**.

### `Dma64BitAddresses`

If the device hardware supports only 32 bit addresses, then **Dma64BitAddresses** must be set to 0. If the device supports 64 bit addresses, this field indicates whether the HBA is able to access addresses greater than 4 GB.

Storport adapters are required to support bus-width DMA. Therefore, on a 64-bit or PAE machine, Storport initializes **Dma64BitAddresses** to SCSI_DMA64_SYSTEM_SUPPORTED indicating that the adapter can access the full range of addresses. When miniport drivers detect this value, they must return one of the values in the following table in the same member to indicate to the port driver that the miniport driver supports 64-bit DMA. If the miniport fails to do this, it might severely degrade the performance of the adapter.

| Value | Meaning |
| ----- | ------- |
| SCSI_DMA64_MINIPORT_SUPPORTED | The miniport driver supports 64-bit physical addresses for I/O transfers. |
| SCSI_DMA64_MINIPORT_FULL64BIT_SUPPORTED | The miniport driver supports full 64-bit addressing. This indicates that I/O requests may have physical addresses > 4GB. The uncached extension, SenseInfo, and Srb Extension may exist above 4GB. Allocations are restricted to 4GB boundary alignment in order to prevent them from crossing a 4GB boundary. |
| SCSI_DMA64_MINIPORT_FULL64BIT_NO_BOUNDARY_REQ_SUPPORTED | The miniport driver supports full 64-bit addressing. This indicates that I/O requests may have physical addresses > 4GB. The uncached extension, SenseInfo, and Srb Extension may exist above 4GB. Allocations have no boundary alignment requirement. |
| SCSI_DMA64_MINIPORT_64BIT_ONE_4GB_SUPPORTED | The miniport driver support 64-bit addressing in a single 4GB region. This indicates that I/O requests, uncached extension, SenseInfo, and Srb Extension may have physical addresses > 4GB in a single 4GB region. |

### `ResetTargetSupported`

Obsolete. Do not use this member.

### `MaximumNumberOfLogicalUnits`

Maximum number of logical units per target that the HBA can control. By default, the value of this member is SCSI_MAXIMUM_LOGICAL_UNITS. A miniport driver can reset this member to a lesser value if the HBA has more limited capabilities or to a greater value, indicating that the HBA has extended capabilities. The maximum value for this member is SCSI_MAXIMUM_LUNS_PER_TARGET.

### `WmiDataProvider`

When **TRUE**, the miniport driver responds to Windows Management Instrumentation (WMI) requests. Storport initializes this member to **TRUE** because its miniport drivers must support WMI. Additionally, miniport drivers for fibre channel adapters are expected to support the SAN Management HBA API through WMI, and miniport drivers for host-based RAID adapters are required to support the RAID Management Interface.

Miniport drivers must not modify this value.

### `SynchronizationModel`

The I/O synchronization model that the miniport driver supports. Possible values are as follows:

| Value | Meaning |
| ----- | ------- |
| **StorSynchronizeFullDuplex** | The miniport supports full-duplex mode. |
| **StorSynchronizeHalfDuplex** | The miniport supports half-duplex mode. |

### `HwMSInterruptRoutine`

Pointer to the miniport driver's [*HwMSInterruptRoutine*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine) routine, which is required for any miniport driver of an HBA that generates message signaled interrupts (MSIs). A miniport driver sets this member to **NULL** if the HBA does not generate MSIs.

### `InterruptSynchronizationMode`

An [**INTERRUPT_SYNCHRONIZATION_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_interrupt_synchronization_mode) value that specifies the interrupt synchronization mode. The interrupt synchronization mode determines how the port driver synchronizes message signaled interrupts.

### `DumpRegion`

A [**MEMORY_REGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_memory_region) structure that describes a region of physically contiguous memory that miniport drivers can use during a crash dump or hibernation.

### `RequestedDumpBufferSize`

Size in bytes of the uncached extension to be allocated for use during dump/hibernation.

### `VirtualDevice`

When TRUE, there is no real hardware behind this device (for example, no DMA object, interrupt, I/O ports). Storport behaves differently in some circumstances when it supports a "virtual" miniport instead of a miniport that is controlling real hardware.

### `DumpMode`

Indicates the use of the miniport during dump mode. It can have one of the following values.

| Value | Meaning |
| ----- | ------- |
| DUMP_MODE_CRASH | The miniport in dump mode is used for a crashdump. |
| DUMP_MODE_HIBER | The miniport in dump mode is used for a hibernation. |
| DUMP_MODE_MARK_MEMORY | The miniport in dump mode is used for marking required memory. |
| DUMP_MODE_RESUME | The miniport in dump mode is used for a resume from hibernation. |

### `DmaAddressWidth`

The width of an adapter's DMA address. Miniports must specify STOR_ADAPTER_DMA_ADDRESS_WIDTH_SPECIFIED in **FeatureSupport** when providing this value. The specified value must be (0 < **DmaAddressWidth** <= 64). This field can be used starting in Windows 10, version 2004.

### `ExtendedFlags1`

Reserved for system use.

### `MaxNumberOfIO`

Maximum number of outstanding I/O operations supported by the HBA. The default is set to 1000 by Storport. If the HBA does not support 1000 outstanding I/O operations, the miniport should adjust this to an appropriate smaller value.

If the HBA can support more than 1000 outstanding I/O operations, the miniport can increase this member to any value supported by the adapter hardware. To allow more than 1000 outstanding I/O operations, the HBA must support one of the following 64-bit DMA addressing methods, set in the **Dma64BitAddresses** field:

- SCSI_DMA64_MINIPORT_FULL64BIT_SUPPORTED
- SCSI_DMA64_MINIPORT_FULL64BIT_NO_BOUNDARY_REQ_SUPPORTED
- SCSI_DMA64_MINIPORT_64BIT_ONE_4GB_SUPPORTED

### `MaxIOsPerLun`

Maximum number of I/O requests supported on a LUN. Storport will set this to a default value of 255. If a LUN does not support 255 outstanding I/O requests, the miniport should adjust this member to an appropriate smaller value. This member must be <= **MaxNumberOfIO**. To support **MaxIOsPerLun** > 255, the **SrbType** field must be set to **SRB_TYPE_STORAGE_REQUEST_BLOCK**. Available starting in Windows 8.

### `InitialLunQueueDepth`

The initial LUN I/O queue depth. Storport set this to a default value of 20 for physical miniports and to 250 for virtual miniports. This member adjusts the initial queue depth for all LUNs on the adapter. The queue depth for an individual LUN is set by calling [**StorPortSetDeviceQueueDepth**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetdevicequeuedepth). This member is typically set to the same value as **MaxIOsPerLun**. Available starting in Windows 8.

### `BusResetHoldTime`

The amount of time, in microseconds, to pause the adapter after a reset is detected. Set this value to 0 if no wait time is needed after a bus reset. Available starting in Windows 8.

### `FeatureSupport`

Storport features requested for the adapter. Available starting in Windows 8. A miniport driver can set this member to be a bitwise mask of any of the following values:

| Value | Meaning |
| ----- | ------- |
| STOR_ADAPTER_FEATURE_DEVICE_TELEMETRY 0x00000001 | The miniport driver supports storage device telemetry. |
| STOR_ADAPTER_FEATURE_STOP_UNIT_DURING_POWER_DOWN 0x00000002 | The miniport requests to receive the STOP_UNIT command during system shutdown. |
| STOR_ADAPTER_UNCACHED_EXTENSION_NUMA_NODE_PREFERRED 0x00000004 | The miniport driver wants UncachedExtension to be allocated from adapter NUMA node. |
| STOR_ADAPTER_DMA_V3_PREFERRED 0x00000008 | The miniport driver prefers to use DMA V3 kernel API for the adapter. |
| STOR_ADAPTER_FEATURE_ABORT_COMMAND 0x00000010 | The miniport driver supports the ability to abort an outstanding command via SRB_FUNCTION_ABORT_COMMAND. |
| STOR_ADAPTER_FEATURE_RICH_TEMPERATURE_THRESHOLD 0x00000020 | The adapter supports richer temperature threshold information than defined in SCSI SPC4 spec. |
| STOR_ADAPTER_DMA_ADDRESS_WIDTH_SPECIFIED 0x00000040 | The miniport driver specified the DMA address width in **DmaAddressWidth** for the adapter. This value can be used starting in Windows 10, version 2004.|

## Remarks

The Storport driver allocates and initializes this structure, supplies as much HBA-specific configuration information as possible, and passes the structure to the miniport driver's [*HwStorFindAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine. Storport does not support non-PnP devices, so *HwStorFindAdapter* does not search for the adapter. Its principal function is to initialize **PORT_CONFIGURATION_INFORMATION**.

## See also

[**ACCESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_access_range)

[**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1)

[*HwMSInterruptRoutine*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine)

[*HwStorFindAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[*HwStorInterrupt*](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt)

[**INTERRUPT_SYNCHRONIZATION_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_interrupt_synchronization_mode)

[**MEMORY_REGION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_memory_region)

[**StorPortGetUncachedExtension**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetuncachedextension)

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)

[**StorPortSetDeviceQueueDepth**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetdevicequeuedepth)