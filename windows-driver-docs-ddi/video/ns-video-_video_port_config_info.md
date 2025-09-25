# _VIDEO_PORT_CONFIG_INFO structure

## Description

The VIDEO_PORT_CONFIG_INFO structure contains bus-specific adapter configuration information. This structure is used to set up the video hardware and to supply the video port driver with configuration information. The video port driver can then allocate necessary system resources for the miniport driver and its adapter.

## Members

### `Length`

Is the size in bytes of this structure. The video port driver always initializes the **Length** member. In effect, its value indicates the version of VIDEO_PORT_CONFIG_INFO being used by the system. Because this structure might grow from one version of the system to the next, a miniport driver should check this member to determine whether it is at least **sizeof**(VIDEO_PORT_CONFIG_INFO) that the miniport driver uses to configure its adapter.

### `SystemIoBusNumber`

Specifies the system-assigned number of the I/O bus on which the miniport driver's adapter might be connected. The video port driver always initializes this member.

### `AdapterInterfaceType`

Specifies the type of bus interface. The video port driver always sets this member based on the bus on which the PnP manager detected the device.

### `BusInterruptLevel`

This member is irrelevant if the video hardware does not generate interrupts, indicated by setting the **HwInterrupt** member in the [VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data) structure to **NULL**. Otherwise, it specifies the bus-relative IRQL that corresponds to the interrupt request on **Isa** or **MicroChannel** type buses. The preset default value for this member is zero. A miniport driver must supply the correct value if it handles interrupts for a video adapter on an **Isa** or **MicroChannel** type bus, or for a video adapter configured for level-sensitive interrupts on an **Eisa** type bus.

If a miniport driver's [HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter) function finds that the video adapter does not generate interrupts or that it cannot determine a valid interrupt vector/level for the adapter, *HwVidFindAdapter* should set both **BusInterruptLevel** and **BusInterruptVector** to zero.

### `BusInterruptVector`

This member is irrelevant if the video hardware does not generate interrupts, indicated by setting the **HwInterrupt** member in the VIDEO_HW_INITIALIZATION_DATA structure to **NULL**. Otherwise, it specifies the bus-relative vector used by the video hardware on I/O buses that use interrupt vectors, such as PCI buses. The preset default value for this member is zero.

If a miniport driver's *HwVidFindAdapter* function finds that the video adapter does not generate interrupts or that it cannot determine a valid interrupt vector/level for the adapter, *HwVidFindAdapter* should set both **BusInterruptVector** and **BusInterruptLevel** to zero.

### `InterruptMode`

Indicates whether the video hardware uses **Latched** or **LevelSensitive** interrupts. The video port driver initializes this member if it is relevant, but a miniport driver with an ISR should check that it contains the correct value and reset it if necessary.

### `NumEmulatorAccessEntries`

This member and all subsequent members through **HardwareStateSize** are irrelevant to miniport drivers that do not declare themselves to be VGA-compatible miniport drivers on x86-based NT-based operating system platforms. For miniport drivers that do not support VGA-compatible SVGA adapters on x86-based machines, this member should be zero. Otherwise, it specifies the number of EMULATOR_ACCESS_RANGE-type elements in the following array.

### `EmulatorAccessEntries`

Pointer to an array of emulator access ranges set up by the VGA-compatible miniport driver. Each emulator access range must be a proper subset of the miniport driver's [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)-type array. Each element specifies a range of I/O ports to be hooked out by the V86 emulator and, possibly, monitored by a driver-supplied SvgaHwIoPortXxx function whenever an MS-DOS application, running full screen, attempts to write directly to the video adapter registers. Usually, this array describes all I/O port ranges in the corresponding access ranges array. If the miniport driver defines its array of emulator access entries statically in the driver itself, the port driver initializes this pointer to that array. If *NumEmulatorAccessEntries* is zero, this member is **NULL**.

### `EmulatorAccessEntriesContext`

Specifies a value passed with each call to an *SvgaHwIoPortXxx* function described in the **EmulatorAccessEntries** array. Usually, a VGA-compatible miniport driver sets the value of this member to the **HwDeviceExtension** pointer, or to an offset within the device extension, so the miniport driver can maintain state, such as batched application-issued instructions, in its *SvgaHwIoPortXxx* functions.

### `VdmPhysicalVideoMemoryAddress`

Specifies the base (mapped) logical address of a range of video memory to be mapped into a VDM's address space for x86 BIOS INT10 support. For miniport drivers that do not support VGA-compatible adapters on x86-based machines, this member should be **NULL**.

### `VdmPhysicalVideoMemoryLength`

Specifies the size in bytes of the range be mapped into a VDM's address space for x86 BIOS support. For miniport drivers that do not support VGA-compatible adapters on x86-based machines, this member should be zero.

### `HardwareStateSize`

Specifies the minimum size in bytes required to store hardware state information in response to an [IOCTL_VIDEO_SAVE_HARDWARE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_save_hardware_state) request, which must be supported only by VGA-compatible miniport drivers on x86-based machines. The initialized value for this member is zero. A VGA-compatible miniport driver must set this member to the number of bytes it requires to hold saved adapter state.

### `DmaChannel`

Reserved for system use.

### `DmaPort`

Reserved for system use.

### `DmaShareable`

Reserved for system use.

### `InterruptShareable`

If the miniport driver's device interrupts, this member should be set to zero if the interrupt cannot be shared with another device, or set to one if the interrupt can be shared. Otherwise, a miniport driver can ignore this member.

### `Master`

Reserved for system use.

### `DmaWidth`

Reserved for system use.

### `DmaSpeed`

Reserved for system use.

### `bMapBuffers`

Reserved for system use.

### `NeedPhysicalAddresses`

Reserved for system use.

### `DemandMode`

Reserved for system use.

### `MaximumTransferLength`

Reserved for system use.

### `NumberOfPhysicalBreaks`

Reserved for system use.

### `ScatterGather`

Reserved for system use.

### `MaximumScatterGatherChunkSize`

Reserved for system use.

### `VideoPortGetProcAddress`

Pointer to the [VideoPortGetProcAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_port_get_proc_address) callback routine. This member is used to find the address of a video port driver function that the video miniport driver can use without linking to it directly. This enables a driver binary to run on an earlier version of Windows. For details, see [Using VideoPortGetProcAddress](https://learn.microsoft.com/windows-hardware/drivers/display/using-videoportgetprocaddress).

### `DriverRegistryPath`

Pointer to the registry path containing the device's service. The display driver can use this information in any way it deems useful.

### `SystemMemorySize`

Indicates to a driver the amount, in bytes, of physical memory in the system.

## See also

[HwVidFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_find_adapter)

[IOCTL_VIDEO_SAVE_HARDWARE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_save_hardware_state)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_hw_initialization_data)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortGetDeviceData](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicedata)

[VideoPortGetProcAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_port_get_proc_address)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)