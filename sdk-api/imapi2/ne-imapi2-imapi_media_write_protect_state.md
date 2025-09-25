# IMAPI_MEDIA_WRITE_PROTECT_STATE enumeration

## Description

Defines values that indicate the media write protect status. One or more write protect values can be set on a given drive.

## Constants

### `IMAPI_WRITEPROTECTED_UNTIL_POWERDOWN:0x1`

 Power to the drive needs to be cycled before allowing writes to the media.

### `IMAPI_WRITEPROTECTED_BY_CARTRIDGE:0x2`

The media is in a cartridge with the write protect tab set.

### `IMAPI_WRITEPROTECTED_BY_MEDIA_SPECIFIC_REASON:0x4`

The drive is disallowing writes for a media-specific reason. For example:

* The media was originally in a cartridge and was set to disallow writes when the media is not in a cartridge.
* The media has used all available spare areas for defect management and is preventing writes to protect the existing data.

### `IMAPI_WRITEPROTECTED_BY_SOFTWARE_WRITE_PROTECT:0x8`

A write-protect flag on the media is set. Various media types, such as DVD-RAM and DVD-RW, support a special area on the media to indicate the disc's write protect status.

### `IMAPI_WRITEPROTECTED_BY_DISC_CONTROL_BLOCK:0x10`

A write-protect flag in the disc control block of a DVD+RW disc is set. DVD+RW media can persistently alter the write protect state of media by writing a device control block (DCB) to the media.

This value has limited usefulness because some DVD+RW drives do not recognize or honor this setting.

### `IMAPI_WRITEPROTECTED_READ_ONLY_MEDIA:0x4000`

The drive does not recognize write capability of the media.

## See also

[IDiscFormat2Data::get_WriteProtectStatus](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_writeprotectstatus)