## Description

The EMULATOR_ACCESS_ENTRY structure specifies an element in the **EmulatorAccessEntries** array set up in the VIDEO_PORT_CONFIG_INFO structure by drivers of VGA-compatible (SVGA) adapters on x86-based NT-based operating system platforms.

## Members

### `BasePort`

Specifies the bus-relative physical address of the I/O port or ports to be hooked out by the V86 emulator. This value and the range of ports must fall within an access range of I/O ports already claimed in the registry by **VideoPortGetAccessRanges** or **VideoPortVerifyAccessRanges**.

### `NumConsecutivePorts`

Specifies the number of consecutive ports to be hooked by the V86 emulator, starting at **BasePort**. This value is determined by the width of each hooked I/O port. For example, if port addresses 0x3C0 and 0x3C1 are hooked as a single USHORT-addressable port, this value should be 1.

### `AccessType`

Specifies the size of the data transferred through the given I/O port as one of **Uchar**, **Ulong**, or **Ushort**.

### `AccessMode`

Specifies how the given I/O port can be accessed as one or a combination (ORed) of the following values:

- EMULATOR_READ_ACCESS

- EMULATOR_WRITE_ACCESS

The I/O port range must be accessible in at least one of the preceding modes.

### `StringSupport`

Indicates whether the driver-supplied *SvgaHwIoPortXxx* function supports string accesses in cases where many values of the given **AccessType** are "pumped" through an I/O port consecutively. If this member is set to **TRUE**, the **Routine** member must specify the entry point of a miniport driver-supplied *SvgaHwIoPortXxxString* function.

### `Routine`

Pointer to the miniport driver's *SvgaHwIoPortXxx* that handles accesses to the port or ports described in this structure.

## Syntax

```cpp
typedef struct _EMULATOR_ACCESS_ENTRY {
  ULONG                     BasePort;
  ULONG                     NumConsecutivePorts;
  EMULATOR_PORT_ACCESS_TYPE AccessType;
  UCHAR                     AccessMode;
  UCHAR                     StringSupport;
  PVOID                     Routine;
} EMULATOR_ACCESS_ENTRY, *PEMULATOR_ACCESS_ENTRY;
```

## Remarks

VGA-compatible miniport drivers of SVGA video hardware in x86-based machines must define emulator access ranges, which a VGA-compatible miniport driver can set up with **VideoPortSetTrappedEmulatorPorts** to be accessed directly from full-screen MS-DOS applications for faster I/O. Such a driver must supply a set of *SvgaHwIoPortXxx* functions to validate any sequence of application-issued **IN**s, **INSB/INSW/INSD**s, **OUT**s, and/or **OUTSB/OUTSW/OUTSD**s to each such I/O port range.

Data in each EMULATOR_ACCESS_ENTRY-type element is used to determine which I/O ports (memory locations at which adapter registers are accessible) in the miniport driver's access ranges have been taken over (hooked out) by the V86 emulator on x86-based platforms. Values written to these locations by full-screen MS-DOS applications are trapped and forwarded to the miniport driver's corresponding *SvgaHwIoPortXxx* function for validation before they are written to or read from the video adapter. However, the miniport driver can enable the application to directly access particular I/O port ranges by calling **VideoPortSetTrappedEmulatorPorts** to improve performance.

## See also

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortVerifyAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportverifyaccessranges)

[VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VideoPortGetAccessRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetaccessranges)