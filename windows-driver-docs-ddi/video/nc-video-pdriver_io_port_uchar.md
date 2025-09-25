# PDRIVER_IO_PORT_UCHAR callback function

## Description

*SvgaHwIoPortUchar* traps an I/O port to which a full-screen MS-DOS application in an x86-based machine is sending UCHAR-sized data.

## Parameters

### `Context`

Specifies the miniport driver-defined context value that was set in the **EmulatorAccessEntriesContext** member of [VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info).

### `Port`

Specifies the mapped I/O port to be trapped.

### `AccessMode`

Specifies the type of access to be trapped, which can be one or a combination (ORed) of the following values:

EMULATOR_READ_ACCESS

EMULATOR_WRITE_ACCESS

### `Data`

Pointer to the byte to be transferred.

## Return value

*SvgaHwIoPortUchar* returns the final status of the operation.

## Remarks

Only miniport drivers of VGA-compatible SVGA adapters have *SvgaHwIoPortXxx* functions. (See [SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/).)

*SvgaHwIoPortUchar* intercepts any byte access attempted by a full-screen MS-DOS application issuing either or both of the instructions **OUT DX, AL** and **IN AL, DX**.

If the miniport driver enables the *Port* for direct access by calling [VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports), its *SvgaHwIoPortUchar* function will not be called. Such an application then will have direct access to the *Port*, unless the miniport driver disables the *Port* with another call to **VideoPortSetTrappedEmulatorPorts**.

If one or more application-issued x86 **IN** or **OUT** instructions might affect the state of the VGA-compatible adapter sequencer register, miscellaneous output register, or any adapter-specific register and, thereby, cause the machine to hang, the miniport driver must *not* enable the port for direct access by calling **VideoPortSetTrappedEmulatorPorts**.

*SvgaHwIoPortUchar* must buffer subsequent instructions from the application to the *Port* and check that none can hang the machine. If the application issues any sequence of instructions that might hang the machine, *SvgaHwIoPortUchar* must discard the buffered instructions. Otherwise, it should output them, a UCHAR at a time, to the specified, mapped I/O port.

*SvgaHwIoPortUchar* should be made pageable.

## See also

[EMULATOR_ACCESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_emulator_access_entry)

[SVGA Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[SvgaHwIoPortUcharString](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pdriver_io_port_uchar_string)

[VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range)

[VIDEO_PORT_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_port_config_info)

[VideoPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetdevicebase)

[VideoPortSetTrappedEmulatorPorts](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsettrappedemulatorports)