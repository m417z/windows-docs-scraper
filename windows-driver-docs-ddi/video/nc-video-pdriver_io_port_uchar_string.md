# PDRIVER_IO_PORT_UCHAR_STRING callback function

## Description

*SvgaHwIoPortUcharString* traps an I/O port to which a full-screen MS-DOS application in an x86-based machine is sending a sequence of UCHAR-sized data.

## Parameters

### `Context`

Specifies the miniport driver-determined context value that was set in the **EmulatorAccessEntriesContext** member of VIDEO_PORT_CONFIG_INFO.

### `Port`

Specifies the mapped I/O port.

### `AccessMode`

Specifies the type of access allowed, which can be one or a combination (ORed) of the following values:

EMULATOR_READ_ACCESS

EMULATOR_WRITE_ACCESS

### `Data`

Pointer to the UCHAR string to be transferred. One character at a time is hooked out until the whole string is transferred.

### `DataLength`

Specifies the number of UCHAR values in the string.

## Return value

*SvgaHwIoPortUcharString* returns the final status of the operation.

## Remarks

Only miniport drivers of VGA-compatible SVGA adapters have *SvgaHwIoPortXxx* functions. (See [SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/).)

*SvgaHwIoPortUcharString* intercepts any byte access attempted by a full-screen MS-DOS application issuing either or both of the instructions **REP OUTSB DX, ESI** and **REP INSB EDI, DX**.

If the miniport driver enables the *Port* for direct access by calling **VideoSetTrappedEmulatorPorts**, its *SvgaHwIoPortUcharString* function will not be called. Such an application then will have direct access to the I/O port, unless the miniport driver disables the port with another call to **VideoSetTrappedEmulatorPorts**.

If one or more application-issued x86 **INSB** or **OUTSB** instructions might affect the state of the VGA-compatible adapter sequencer register, miscellaneous output register, or any adapter-specific register and, thereby, cause the machine to hang, the miniport driver must *not* enable the port for direct access by calling **VideoPortSetTrappedEmulatorPorts**.

*SvgaHwIoPortUcharString* must buffer subsequent instructions from the application and check that none can hang the machine. If the application issues any sequence of instructions that might hang the machine, *SvgaHwIoPortUcharString* must discard the buffered instructions. Otherwise, it should output them, a UCHAR at a time, to the specified, mapped I/O port.

*SvgaHwIoPortUcharString* should be made pageable.

## See also

[EMULATOR_ACCESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_emulator_access_entry)

[SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[SvgaHwIoPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pdriver_io_port_uchar)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports)