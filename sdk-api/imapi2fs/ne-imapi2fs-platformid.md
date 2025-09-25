# PlatformId enumeration

## Description

Defines values for the operating system architecture that the boot image supports

## Constants

### `PlatformX86:0`

 Intel Pentium™ series of chip sets. This entry implies a Windows operating system.

### `PlatformPowerPC:1`

Apple PowerPC family.

### `PlatformMac:2`

Apple Macintosh family.

### `PlatformEFI:0xef`

EFI Family.

## Remarks

Other values not defined here may exist. Consumers of this enumeration should not presume this list to be the only set of valid values.

## See also

[IBootOptions::get_PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-get_platformid)

[IBootOptions::put_PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-put_platformid)