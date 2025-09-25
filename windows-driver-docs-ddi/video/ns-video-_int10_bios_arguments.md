# _INT10_BIOS_ARGUMENTS structure

## Description

The INT10_BIOS_ARGUMENTS structure is used to support full-screen MS-DOS application INT10 calls. It contains nine of the high-end x86 microprocessor registers.

## Members

### `Eax`

### `Ebx`

### `Ecx`

### `Edx`

### `Esi`

### `Edi`

### `Ebp`

Are seven of the x86 microprocessor registers.

### `SegDs`

### `SegEs`

Are two of the x86 microprocessor segment registers.

## Remarks

The first seven members of the INT10_BIOS_ARGUMENTS structure are identical to those of the [VIDEO_x86_BIOS_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_x86_bios_arguments) structure.

## See also

[Int10CallBios](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pint10_call_bios)

[VIDEO_x86_BIOS_ARGUMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_x86_bios_arguments)