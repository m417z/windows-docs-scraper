# PDRIVER_IO_PORT_ULONG_STRING callback function

## Description

*SvgaHwIoPortUlongString* traps an I/O port range to which a full-screen MS-DOS application in an x86-based machine is sending a sequence of ULONG-sized data.

## Parameters

### `Context`

Specifies the miniport driver-determined context value that was set in the **EmulatorAccessEntriesContext** member of VIDEO_PORT_CONFIG_INFO.

### `Port`

Specifies the mapped I/O port to be trapped.

### `AccessMode`

Specifies the type of access allowed, which can be one or a combination (ORed) of the following values:

EMULATOR_READ_ACCESS

EMULATOR_WRITE_ACCESS

### `Data`

Pointer to the ULONG data string to be transferred. The string is hooked out one value at a time until it is all used.

### `DataLength`

Specifies the number of ULONG values in the string.

## Return value

*SvgaHwIoPortUlongString* returns the final status of the operation.

## Remarks

Only miniport drivers of VGA-compatible SVGA adapters have *SvgaHwIoPortXxx* functions. (See [SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/).)

*SvgaHwIoPortUlongString* intercepts any range access attempted by a full-screen MS-DOS application issuing either or both of the instructions **REP OUTSD DX, ESI** and **REP INSD EDI, DX**.

If the miniport driver enables the *Port* range for direct access by calling **VideoSetTrappedEmulatorPorts**, its *SvgaHwIoPortUlongString* function will not be called. Such an application then will have direct access to the I/O port range, unless the miniport driver disables the *Port* range with another call to **VideoSetTrappedEmulatorPorts**.

If one or more application-issued x86 **INSD** or **OUTSD** instructions might affect the state of the VGA-compatible adapter sequencer register, miscellaneous output register, or any adapter-specific register and, thereby, cause the machine to hang, the miniport driver must *not* enable the port for direct access by calling **VideoPortSetTrappedEmulatorPorts**.

*SvgaHwIoPortUlongString* must buffer subsequent instructions from the application and check that none can hang the machine. If the application issues any sequence of instructions that might hang the machine, *SvgaHwIoPortUlongString* must discard the buffered instructions. Otherwise, it should output them, a ULONG at a time, to the specified, mapped I/O port.

*SvgaHwIoPortUlongString* should be made pageable.

## See also

[EMULATOR_ACCESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_emulator_access_entry)

[SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[SvgaHwIoPortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pdriver_io_port_ulong)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports)