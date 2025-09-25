## Description

The **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure specifies one or more system hardware resources, of a single type, assigned to a device. This structure is used to create an array within a [CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list) structure.

## Members

### `Type`

Identifies the resource type. The constant value specified for **Type** indicates which structure within the **u** union is valid, as indicated in the following table. (These flags are used within both **CM_PARTIAL_RESOURCE_DESCRIPTOR** and [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structures, except where noted.)

| Type value | u member substructure |
|---|---|
| **CmResourceTypePort** | **u.Port** |
| **CmResourceTypeInterrupt** | **u.Interrupt** or **u.MessageInterrupt**.If the CM_RESOURCE_INTERRUPT_MESSAGE flag of **Flags** is set, use **u.MessageInterrupt**; otherwise, use **u.Interrupt**. |
| **CmResourceTypeMemory** | **u.Memory** |
| **CmResourceTypeMemoryLarge** | One of **u.Memory40**, **u.Memory48**, or **u.Memory64**.The CM_RESOURCE_MEMORY_LARGE\_*XXX* flags set in the **Flags** member determines which structure is used. |
| **CmResourceTypeDma** | **u.Dma** (if CM_RESOURCE_DMA_V3 is not set) or **u.DmaV3** (if CM_RESOURCE_DMA_V3 flag is set) |
| **CmResourceTypeDevicePrivate** | **u.DevicePrivate** |
| **CmResourceTypeBusNumber** | **u.BusNumber** |
| **CmResourceTypeDeviceSpecific** | **u.DeviceSpecificData**(Not used within **IO_RESOURCE_DESCRIPTOR**.) |
| **CmResourceTypePcCardConfig** | **u.DevicePrivate** |
| **CmResourceTypeMfCardConfig** | **u.DevicePrivate** |
| **CmResourceTypeConnection** | **u.Connection** |
| **CmResourceTypeConfigData** | *Reserved for system use.* |
| **CmResourceTypeNonArbitrated** | *Not used.* |

### `ShareDisposition`

Indicates whether the described resource can be shared. Valid constant values are listed in the following table:

| Value | Meaning |
|---|---|
| **CmResourceShareDeviceExclusive** | The device requires exclusive use of the resource. |
| **CmResourceShareDriverExclusive** | The driver requires exclusive use of the resource. Not supported for WDM drivers. |
| **CmResourceShareShared** | The resource can be shared without restriction. |

### `Flags`

Contains flag bits that are specific to the resource type, as indicated in the following tables (flags can be bitwise-ORed together as appropriate):

#### CmResourceTypePort resource type

| Flag | Definition |
|---|---|
| CM_RESOURCE_PORT_MEMORY | The device is accessed in memory address space. |
| CM_RESOURCE_PORT_IO | The device is accessed in I/O address space. |
| CM_RESOURCE_PORT_10_BIT_DECODE | The device decodes 10 bits of the port address. |
| CM_RESOURCE_PORT_12_BIT_DECODE | The device decodes 12 bits of the port address. |
| CM_RESOURCE_PORT_16_BIT_DECODE | The device decodes 16 bits of the port address. |
| CM_RESOURCE_PORT_POSITIVE_DECODE | The device uses "positive decode" instead of "subtractive decode". (In general, PCI devices use positive decode and ISA buses use subtractive decode.) |
| CM_RESOURCE_PORT_PASSIVE_DECODE | The device decodes the port but the driver does not use it. |
| CM_RESOURCE_PORT_WINDOW_DECODE | Reserved for system use. |

#### CmResourceTypeInterrupt resource type

| Flag | Definition |
|---|---|
| CM_RESOURCE_INTERRUPT_LEVEL_SENSITIVE | The IRQ line is level-triggered. (These IRQs are usually sharable.) |
| CM_RESOURCE_INTERRUPT_LATCHED | The IRQ line is edge-triggered. |
| CM_RESOURCE_INTERRUPT_MESSAGE | If this flag is set, the interrupt is a message-signaled interrupt. Otherwise, the interrupt is a line-based interrupt. |
| CM_RESOURCE_INTERRUPT_POLICY_INCLUDED | Not used with the **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure. For more information about this flag, see [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor). |
| CM_RESOURCE_INTERRUPT_SECONDARY_INTERRUPT | The interrupt is a secondary interrupt. This flag can be set starting with Windows 8. For more information about secondary interrupts, see [GPIO Interrupts](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-interrupts). |
| CM_RESOURCE_INTERRUPT_WAKE_HINT | The interrupt is capable of waking the operating system from a low-power idle state or a system sleep state. This flag can be set starting with Windows 8. For more information about wake capabilities, see [Enabling Device Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/kernel/enabling-device-wake-up). |

#### CmResourceTypeMemory resource type

| Flag | Definition |
|---|---|
| CM_RESOURCE_MEMORY_READ_WRITE | The memory range is readable and writable. |
| CM_RESOURCE_MEMORY_READ_ONLY | The memory range is read-only. |
| CM_RESOURCE_MEMORY_WRITE_ONLY | The memory range is write-only. |
| CM_RESOURCE_MEMORY_PREFETCHABLE | The memory range is prefetchable. |
| CM_RESOURCE_MEMORY_COMBINEDWRITE | Combined-write caching is allowed. |
| CM_RESOURCE_MEMORY_24 | The device uses 24-bit addressing. |
| CM_RESOURCE_MEMORY_CACHEABLE | The memory range is cacheable. |

#### CmResourceTypeMemoryLarge resource type

| Flag | Definition |
|---|---|
| CM_RESOURCE_MEMORY_LARGE_40 | The memory descriptor uses the **u.Memory40** member. |
| CM_RESOURCE_MEMORY_LARGE_48 | The memory descriptor uses the **u.Memory48** member. |
| CM_RESOURCE_MEMORY_LARGE_64 | The memory descriptor uses the **u.Memory64** member. |

#### CmResourceTypeDma resource type

| Flag | Definition |
|---|---|
| CM_RESOURCE_DMA_8 | 8-bit DMA channel |
| CM_RESOURCE_DMA_16 | 16-bit DMA channel |
| CM_RESOURCE_DMA_32 | 32-bit DMA channel |
| CM_RESOURCE_DMA_8\_AND_16 | 8-bit and 16-bit DMA channel |
| CM_RESOURCE_DMA_BUS_MASTER | The device supports bus master DMA transfers. |
| CM_RESOURCE_DMA_TYPE_A | Type A DMA |
| CM_RESOURCE_DMA_TYPE_B | Type B DMA |
| CM_RESOURCE_DMA_TYPE_F | Type F DMA |
| CM_RESOURCE_DMA_V3 | Use the **DmaV3** member instead of the **Dma** member. The **DmaV3** member is available starting with Windows 8. |

### `u`

Defines the **u** union.

### `u.Generic`

Not used.

### `u.Generic.Start`

Not used.

### `u.Generic.Length`

Not used.

### `u.Port`

Specifies a range of I/O port addresses, using the following members.

Drivers for Windows Vista and later versions of the Windows operating system can use [RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource) and [RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource) to read and update the **u.Port** member, rather than updating it directly.

### `u.Port.Start`

For raw resources: Specifies the bus-relative physical address of the lowest of a range of contiguous I/O port addresses allocated to the device.

For translated resources: Specifies the system physical address of the lowest of a range of contiguous I/O port addresses allocated to the device.

For more information about raw and translated resources, see Remarks.

### `u.Port.Length`

The length, in bytes, of the range of allocated I/O port addresses.

### `u.Interrupt`

Specifies an interrupt vector and level, using the following members:

### `u.Interrupt.Group`

Specifies the processor group number. This member exists only if the NT_PROCESSOR_GROUPS constant is defined at compile time. This member can be nonzero only on Windows 7 and later versions of Windows. The **Group** and **Affinity** members together specify a group affinity that indicates which processors the device can interrupt. To specify an affinity for any group, set **Group** to ALL_PROCESSOR_GROUPS.

### `u.Interrupt.Level`

For raw resources: Specifies the device's bus-specific IRQL (if appropriate for the platform and bus).

For translated resources: Specifies the DIRQL assigned to the device.

For more information about raw and translated resources, see Remarks.

### `u.Interrupt.Vector`

For raw resources: Specifies the device's bus-specific interrupt vector (if appropriate for the platform and bus).

For translated resources: Specifies the global system interrupt vector assigned to the device.

For more information about raw and translated resources, see Remarks.

### `u.Interrupt.Affinity`

Contains a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed bitmask value indicating the set of processors the device can interrupt. To indicate that the device can interrupt any processor, this member is set to -1.

### `u.MessageInterrupt`

Specifies a message-signaled interrupt. This member is a union. Use **u.MessageInterrupt.Raw** for raw resources, and **u.MessageInterrupt.Translated** for translated resources. This type of resource is only returned on Windows Vista and later versions of the Windows operating system.

For more information about raw and translated resources, see Remarks.

### `u.MessageInterrupt.DUMMYUNIONNAME`

Defines the **DUMMYUNIONNAME** union.

### `u.MessageInterrupt.DUMMYUNIONNAME.Raw`

Defines the **Raw** structure.

### `u.MessageInterrupt.DUMMYUNIONNAME.Raw.Group`

Specifies a processor group number. This member exists only if NT_PROCESSOR_GROUPS is defined at compile time. This member can be nonzero only on Windows 7 and later versions of Windows. The **Group** and **Affinity** members together specify a group affinity that indicates which processors can receive the device's interrupts. To specify an affinity for any group, set **Group** to ALL_PROCESSOR_GROUPS.

### `u.MessageInterrupt.DUMMYUNIONNAME.Raw.Reserved`

Not used.

### `u.MessageInterrupt.DUMMYUNIONNAME.Raw.MessageCount`

Specifies the number of message-signaled interrupts generated for this driver.

### `u.MessageInterrupt.DUMMYUNIONNAME.Raw.Vector`

Specifies the device's interrupt vector.

### `u.MessageInterrupt.DUMMYUNIONNAME.Raw.Affinity`

Specifies a KAFFINITY value that indicates the processors that receive the device's interrupts.

### `u.MessageInterrupt.DUMMYUNIONNAME.Translated`

The **u.MessageInterrupt.Translated** member has the following members:

### `u.MessageInterrupt.DUMMYUNIONNAME.Translated.Group`

Specifies a processor group number. This member exists only if NT_PROCESSOR_GROUPS is defined at compile time. This member can be nonzero only on Windows 7 and later versions of Windows. The **Translated.Group** and **Translated.Affinity** members together specify a group affinity that indicates which processors can receive the device's interrupts. To specify an affinity for any group, set **Translated.Group** to ALL_PROCESSOR_GROUPS.

### `u.MessageInterrupt.DUMMYUNIONNAME.Translated.Level`

Specifies the device IRQL (DIRQL) assigned to the device's interrupts.

Specifies the device IRQL (DIRQL) assigned to the device's interrupts.

### `u.MessageInterrupt.DUMMYUNIONNAME.Translated.Vector`

Specifies the device's interrupt vector.

### `u.MessageInterrupt.DUMMYUNIONNAME.Translated.Affinity`

Specifies a KAFFINITY value that identifies the processors that receive the device's interrupts.

### `u.Memory`

Specifies a range of memory addresses, using the following members.

Drivers for Windows Vista and later versions of the Windows operating system can use [RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource) and [RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource) to read and update the **u.Memory** member, rather than updating it directly.

### `u.Memory.Start`

For raw resources: Specifies the bus-relative physical address of the lowest of a range of contiguous memory addresses allocated to the device.

For translated resources: Specifies the system physical address of the lowest of a range of contiguous memory addresses allocated to the device.

For more information about raw and translated resources, see Remarks.

### `u.Memory.Length`

Specifies the length, in bytes, of the range of allocated memory addresses.

### `u.Dma`

Specifies a DMA setting, using one of the following members:

### `u.Dma.Channel`

Specifies the number of the DMA channel on a system DMA controller that the device can use.

### `u.Dma.Port`

Specifies the number of the DMA port that an MCA-type device can use.

### `u.Dma.Reserved1`

Not used.

### `u.DmaV3`

Specifies the DMA settings for a driver that uses version 3 of the [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure.

The **u.DmaV3** member is available starting with Windows 8.

### `u.DmaV3.Channel`

Specifies the number of the DMA channel on the system DMA controller that is allocated to the device.

### `u.DmaV3.RequestLine`

Specifies the number of the request line on the system DMA controller that is allocated to the device.

### `u.DmaV3.TransferWidth`

Specifies the width, in bits, of the data bus that the system DMA controller that is allocated to the device uses to transfer data to or from the device.

### `u.DmaV3.Reserved1`

Not used.

### `u.DmaV3.Reserved2`

Not used.

### `u.DmaV3.Reserved3`

Not used.

### `u.DevicePrivate`

Reserved for system use.

### `u.DevicePrivate.Data`

### `u.BusNumber`

Specifies bus numbers, using the following members:

### `u.BusNumber.Start`

Specifies the lowest-numbered of a range of contiguous buses allocated to the device.

### `u.BusNumber.Length`

Specifies the number of buses allocated to the device.

### `u.BusNumber.Reserved`

Not used.

### `u.DeviceSpecificData`

Specifies the size of a device-specific, private structure that is appended to the end of the **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure. If **u.DeviceSpecificData** is used, the **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure must be the last one in the [CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list) array.

Examples of device-specific structures include [CM_FLOPPY_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_floppy_device_data), [CM_KEYBOARD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_keyboard_device_data), [CM_SCSI_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_scsi_device_data), and [CM_SERIAL_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_serial_device_data).

### `u.DeviceSpecificData.DataSize`

Specifies the number of bytes appended to the end of the **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure.

### `u.DeviceSpecificData.Reserved1`

Not used.

### `u.DeviceSpecificData.Reserved2`

Not used.

### `u.Memory40`

Specifies a range of memory addresses, using the following members.

The **u.Memory40** member is available only on Windows Vista and later versions of the Windows operating system. Drivers must use [RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource) and [RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource) to read and update this member, rather than updating it directly.

### `u.Memory40.Start`

For raw resources: Specifies the bus-relative physical address of the lowest of a range of contiguous memory addresses that are allocated to the device.

For translated resources: Specifies the system physical address of the lowest of a range of contiguous memory addresses that are allocated to the device.

For more information about raw and translated resources, see Remarks.

### `u.Memory40.Length40`

Contains the high 32 bits of the 40-bit length, in bytes, of the range of allocated memory addresses. The lowest 8 bits are treated as zero.

### `u.Memory48`

Specifies a range of memory addresses, using the following members.

The **u.Memory48** member is available only on Windows Vista and later versions of the Windows operating system. Drivers must use [RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource) and [RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource) to read and update this member, rather than updating it directly.

### `u.Memory48.Start`

For raw resources: Specifies the bus-relative physical address of the lowest of a range of contiguous memory addresses that are allocated to the device.

For translated resources: Specifies the system physical address of the lowest of a range of contiguous memory addresses that are allocated to the device.

For more information about raw and translated resources, see Remarks.

### `u.Memory48.Length48`

Contains the high 32 bits of the 48-bit length, in bytes, of the range of allocated memory addresses. The lowest 16 bits are treated as zero.

### `u.Memory64`

Specifies a range of memory addresses, using the following members.

The **u.Memory64** member is available only on Windows Vista and later versions of the Windows operating system. Drivers must use [RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource) and [RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource) to read and update this member, rather than updating it directly.

### `u.Memory64.Start`

For raw resources: Specifies the bus-relative physical address of the lowest of a range of contiguous memory addresses that are allocated to the device.

For translated resources: Specifies the system physical address of the lowest of a range of contiguous memory addresses that are allocated to the device.

For more information about raw and translated resources, see Remarks.

### `u.Memory64.Length64`

Contains the high 32 bits of the 64-bit length, in bytes, of the range of allocated memory addresses. The lowest 32 bits are treated as zero.

### `u.Connection`

Specifies a connection to a [serial bus](https://learn.microsoft.com/previous-versions/hh450903(v=vs.85)) or [serial port](https://learn.microsoft.com/windows-hardware/drivers/serports/), or to a set of one or more [general-purpose I/O](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-driver-support-overview) (GPIO) pins. The following members describe this connection.

The **u.Connection** member is available starting with Windows 8.

### `u.Connection.Class`

Specifies the connection class. This member is set to one of the following values:

| Value | Meaning |
|---|---|
| **CM_RESOURCE_CONNECTION_CLASS_GPIO** | Access the device through one or more pins on a GPIO controller. |
| **CM_RESOURCE_CONNECTION_CLASS_SERIAL** | Access the device through a serial bus or serial port. |

### `u.Connection.Type`

Specifies the connection type.

If **Class** = CM_RESOURCE_CONNECTION_CLASS_GPIO, **Type** is set to the following value:

| Value | Meaning |
|---|---|
| **CM_RESOURCE_CONNECTION_TYPE_GPIO_IO** | Access the device through GPIO pins that are configured for I/O. |

A GPIO pin that is configured as an interrupt request input is accessed as an ordinary interrupt resource (**CmResourceTypeInterrupt**).

If **Class** = CM_RESOURCE_CONNECTION_CLASS_SERIAL, **Type** is set to one of the following values:

| Value | Meaning |
|---|---|
| **CM_RESOURCE_CONNECTION_TYPE_SERIAL_I2C** | The device is connected to an I2C bus. |
| **CM_RESOURCE_CONNECTION_TYPE_SERIAL_SPI** | The device is connected to an SPI bus. |
| **CM_RESOURCE_CONNECTION_TYPE_SERIAL_UART** | The device is connected to a serial port. |

### `u.Connection.Reserved1`

Not used.

### `u.Connection.Reserved2`

Not used.

### `u.Connection.IdLowPart`

Contains the lower 32 bits of the 64-bit connection ID.

### `u.Connection.IdHighPart`

Contains the upper 32 bits of the 64-bit connection ID.

## Remarks

A **CM_PARTIAL_RESOURCE_DESCRIPTOR** structure can describe either a raw (bus-relative) resource or a translated (system physical) resource, depending on the routine or IRP with which it is being used. For more information, see [Raw and Translated Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources) and [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device).

There can only be *1* **DeviceSpecificData** block. It must be located at the end of all resource descriptors in a full descriptor block.

## See also

[CM_FLOPPY_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_floppy_device_data)

[CM_FULL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_full_resource_descriptor)

[CM_KEYBOARD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_keyboard_device_data)

[CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list)

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[CM_SCSI_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_scsi_device_data)

[CM_SERIAL_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_serial_device_data)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty)

[IoReportResourceForDetection](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreportresourcefordetection)

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[RtlCmDecodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmdecodememioresource)

[RtlCmEncodeMemIoResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcmencodememioresource)