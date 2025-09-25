# EmulationType enumeration

## Description

Defines values for media types that the boot image is intended to emulate.

## Constants

### `EmulationNone:0`

No emulation. The BIOS will not emulate any device type or special sector size for the CD during boot from the CD.

### `Emulation12MFloppy:1`

Emulates a 1.2 MB floppy disk.

### `Emulation144MFloppy:2`

Emulates a 1.44 MB floppy disk.

### `Emulation288MFloppy:3`

Emulates a 2.88 MB floppy disk.

### `EmulationHardDisk:4`

Emulates a hard disk.

## Remarks

Other values not defined here may exist. Consumers of this enumeration should not presume this list to be the only set of valid values.

For complete details of these emulation types, see the "El Torito" Bootable CD-ROM format specification at [http://www.phoenix.com/docs/specscdrom.pdf](https://www.microsoft.com/?ref=go).

## See also

[IBootOptions::get_Emulation](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-get_emulation)

[IBootOptions::put_Emulation](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-put_emulation)