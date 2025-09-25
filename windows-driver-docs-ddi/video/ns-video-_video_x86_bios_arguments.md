# _VIDEO_X86_BIOS_ARGUMENTS structure

## Description

The VIDEO_x86_BIOS_ARGUMENTS structure is used to support full-screen MS-DOS application INT10 calls. It contains seven of the high-end x86 microprocessor registers.

## Members

### `Eax`

### `Ebx`

### `Ecx`

### `Edx`

### `Esi`

### `Edi`

### `Ebp`

Are the seven x86 microprocessor registers.

## Remarks

MS-DOS INT10s are usually "set mode" requests for the video adapter. Each value is put in the appropriate register and an INT10 call is performed by [VideoPortInt10](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportint10).

A miniport driver should *not* set a segment:offset-type pointer in any member of this structure. Such an address is interpreted as an unsigned DWORD value.

## See also

[VideoPortInt10](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportint10)