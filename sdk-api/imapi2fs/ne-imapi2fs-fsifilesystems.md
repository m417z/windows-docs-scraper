# FsiFileSystems enumeration

## Description

Defines values for recognized file systems.

## Constants

### `FsiFileSystemNone:0`

The disc does not contain a recognized file system.

### `FsiFileSystemISO9660:1`

Standard CD file system.

### `FsiFileSystemJoliet:2`

Joliet file system.

### `FsiFileSystemUDF:4`

UDF file system.

### `FsiFileSystemUnknown:0x40000000`

The disc appears to have a file system, but the layout does not match any of the recognized types.

## See also

[IFileSystemImage::IdentifyFileSystemsOnDisc](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-identifyfilesystemsondisc)