# IMAPI_FEATURE_PAGE_TYPE enumeration

## Description

Defines values for the feature that are supported by the logical unit (CD and DVD device).

## Constants

### `IMAPI_FEATURE_PAGE_TYPE_PROFILE_LIST:0`

 Identifies profiles supported by the logical unit.

### `IMAPI_FEATURE_PAGE_TYPE_CORE:0x1`

 Identifies a logical unit that supports functionality common to all devices.

### `IMAPI_FEATURE_PAGE_TYPE_MORPHING:0x2`

Identifies the ability of the logical unit to notify an initiator about operational changes
and accept initiator requests to prevent operational changes.

### `IMAPI_FEATURE_PAGE_TYPE_REMOVABLE_MEDIUM:0x3`

Identifies a logical unit that has a medium that is removable.

### `IMAPI_FEATURE_PAGE_TYPE_WRITE_PROTECT:0x4`

 Identifies reporting capability and changing capability for write protection status of the
logical unit.

### `IMAPI_FEATURE_PAGE_TYPE_RANDOMLY_READABLE:0x10`

 Identifies a logical unit that is able to read data from logical blocks specified by Logical
Block Addresses.

### `IMAPI_FEATURE_PAGE_TYPE_CD_MULTIREAD:0x1d`

Identifies a logical unit that conforms to the OSTA Multi-Read specification 1.00, with the exception of CD
Play capability (the CD Audio Feature is not required).

### `IMAPI_FEATURE_PAGE_TYPE_CD_READ:0x1e`

 Identifies a logical unit that is able to read CD specific information from the media and
is able to read user data from all types of CD blocks.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_READ:0x1f`

 Identifies a logical unit that is able to read DVD specific information from the media.

### `IMAPI_FEATURE_PAGE_TYPE_RANDOMLY_WRITABLE:0x20`

Identifies a logical unit that is able to write data to logical blocks specified by Logical
Block Addresses.

### `IMAPI_FEATURE_PAGE_TYPE_INCREMENTAL_STREAMING_WRITABLE:0x21`

 Identifies a logical unit that is able to write data to a contiguous region, and is able to
append data to a limited number of locations on the media.

### `IMAPI_FEATURE_PAGE_TYPE_SECTOR_ERASABLE:0x22`

 Identifies a logical unit that supports erasable media and media that requires an erase
pass before overwrite, such as some magneto-optical technologies.

### `IMAPI_FEATURE_PAGE_TYPE_FORMATTABLE:0x23`

 Identifies a logical unit that can format media into logical blocks.

### `IMAPI_FEATURE_PAGE_TYPE_HARDWARE_DEFECT_MANAGEMENT:0x24`

Identifies a logical unit that has defect management available to provide a
defect-free contiguous address space.

### `IMAPI_FEATURE_PAGE_TYPE_WRITE_ONCE:0x25`

Identifies a logical unit that has the ability to record to any previously unrecorded
logical block.

### `IMAPI_FEATURE_PAGE_TYPE_RESTRICTED_OVERWRITE:0x26`

 Identifies a logical unit that has the ability to overwrite logical blocks only in fixed
sets at a time.

### `IMAPI_FEATURE_PAGE_TYPE_CDRW_CAV_WRITE:0x27`

Identifies a logical unit that has the ability to write CD-RW media that is designed for
CAV recording.

### `IMAPI_FEATURE_PAGE_TYPE_MRW:0x28`

 Indicates that the logical unit is capable of reading a disc with the
MRW format.

### `IMAPI_FEATURE_PAGE_TYPE_ENHANCED_DEFECT_REPORTING:0x29`

 Identifies a logical unit that has the ability to perform media
certification and recovered error reporting for logical unit assisted software defect
management.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_PLUS_RW:0x2a`

 Indicates that the logical unit is capable of reading a
recorded DVD+RW disc.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_PLUS_R:0x2b`

 Indicates that the logical unit is capable of reading a recorded
DVD+R disc.

### `IMAPI_FEATURE_PAGE_TYPE_RIGID_RESTRICTED_OVERWRITE:0x2c`

Identifies a logical unit that has the ability to perform writing only on Blocking
boundaries.

### `IMAPI_FEATURE_PAGE_TYPE_CD_TRACK_AT_ONCE:0x2d`

Identifies a logical unit that is able to write data to a CD track.

### `IMAPI_FEATURE_PAGE_TYPE_CD_MASTERING:0x2e`

Identifies a logical unit that is able to write a CD in Session at Once mode or Raw mode.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_DASH_WRITE:0x2f`

 Identifies a logical unit that has the ability to write data to DVD-R/-RW in Disc at Once
mode.

### `IMAPI_FEATURE_PAGE_TYPE_DOUBLE_DENSITY_CD_READ:0x30`

Identifies a logical unit that has the ability to read double density CD specific information from the media.

**Note** This value has been deprecated.

### `IMAPI_FEATURE_PAGE_TYPE_DOUBLE_DENSITY_CD_R_WRITE:0x31`

Identifies a logical unit that has the ability to write to double density CD media.

**Note** This value has been deprecated.

### `IMAPI_FEATURE_PAGE_TYPE_DOUBLE_DENSITY_CD_RW_WRITE:0x32`

Identifies a logical unit that has the ability to write to double density CD-RW media.

**Note** This value has been deprecated.

### `IMAPI_FEATURE_PAGE_TYPE_LAYER_JUMP_RECORDING:0x33`

Identifies a drive that is able to write data to contiguous regions that are allocated on multiple
layers, and is able to append data to a limited number of locations on the media.

### `IMAPI_FEATURE_PAGE_TYPE_CD_RW_MEDIA_WRITE_SUPPORT:0x37`

 Identifies a logical unit that has the ability to perform writing CD-RW media.

### `IMAPI_FEATURE_PAGE_TYPE_BD_PSEUDO_OVERWRITE:0x38`

Identifies a drive that provides Logical Block overwrite service on BD-R discs that are
formatted as SRM+POW.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_PLUS_R_DUAL_LAYER:0x3b`

 Indicates that the drive is capable of reading a
recorded DVD+R Double Layer disc

### `IMAPI_FEATURE_PAGE_TYPE_BD_READ:0x40`

Identifies a logical unit that is able to read control structures and user data from the Blu-ray
disc.

### `IMAPI_FEATURE_PAGE_TYPE_BD_WRITE:0x41`

Identifies a drive that is able to write control structures and user data to writable Blu-ray discs.

### `IMAPI_FEATURE_PAGE_TYPE_HD_DVD_READ:0x50`

Identifies a drive that is able to read HD DVD specific information from the media.

### `IMAPI_FEATURE_PAGE_TYPE_HD_DVD_WRITE:0x51`

Indicates the ability to write to HD DVD-R/-RW media.

### `IMAPI_FEATURE_PAGE_TYPE_POWER_MANAGEMENT:0x100`

 Identifies a logical unit that is able to perform initiator and logical unit directed power
management.

### `IMAPI_FEATURE_PAGE_TYPE_SMART:0x101`

Identifies a logical unit that is able to perform Self-Monitoring Analysis and Reporting
Technology (S.M.A.R.T.).

### `IMAPI_FEATURE_PAGE_TYPE_EMBEDDED_CHANGER:0x102`

 Identifies a logical unit that is able to move media from a storage area to a mechanism
and back.

### `IMAPI_FEATURE_PAGE_TYPE_CD_ANALOG_PLAY:0x103`

 Identifies a logical unit that is able to play CD Audio data directly to an external output.

### `IMAPI_FEATURE_PAGE_TYPE_MICROCODE_UPDATE:0x104`

Identifies a logical unit that is able to upgrade its internal microcode via the interface.

### `IMAPI_FEATURE_PAGE_TYPE_TIMEOUT:0x105`

 Identifies a logical unit that is able to always respond to commands within a set time
period.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_CSS:0x106`

Identifies a logical unit that is able to perform DVD CSS/CPPM authentication and key
management. This feature also indicates that the logical unit supports CSS for DVD-Video and CPPM for
DVD-Audio.

### `IMAPI_FEATURE_PAGE_TYPE_REAL_TIME_STREAMING:0x107`

Identifies a logical unit that is able to perform reading and writing within initiator
specified (and logical unit verified) performance ranges. This Feature also indicates whether the
logical unit supports the stream playback operation.

### `IMAPI_FEATURE_PAGE_TYPE_LOGICAL_UNIT_SERIAL_NUMBER:0x108`

 Identifies a logical unit that has a unique serial number.

### `IMAPI_FEATURE_PAGE_TYPE_MEDIA_SERIAL_NUMBER:0x109`

Identifies a logical unit that is capable of reading a media serial number of the currently
installed media.

### `IMAPI_FEATURE_PAGE_TYPE_DISC_CONTROL_BLOCKS:0x10a`

 Identifies a logical unit that is able to read and/or write Disc Control Blocks from or to
the media.

### `IMAPI_FEATURE_PAGE_TYPE_DVD_CPRM:0x10b`

 Identifies a logical unit that is able to perform DVD CPRM and is able to perform CPRM
authentication and key management.

### `IMAPI_FEATURE_PAGE_TYPE_FIRMWARE_INFORMATION:0x10c`

 Indicates that the logical unit provides the date and time of the creation of the
current firmware revision loaded on the device.

### `IMAPI_FEATURE_PAGE_TYPE_AACS:0x10d`

Identifies a drive that supports AACS and is able to perform AACS authentication process.

### `IMAPI_FEATURE_PAGE_TYPE_VCPS:0x110`

Identifies a Drive that is able to process disc data structures that are specified in the
VCPS.

## Remarks

Note that the range of feature type values is 0x0000 to 0xFFFF. This enumeration contains those features defined in the Multimedia Commands - 5 (MMC) specification. For a complete definition of each feature, see Feature Definitions in the latest release of the MMC specification at ftp://ftp.t10.org/t10/drafts/mmc5.

Other values not defined here may exist. Consumers of this enumeration should not presume this list to be the only set of valid values.

## See also

[IDiscRecorder2::get_SupportedFeaturePages](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_supportedfeaturepages)

[IDiscRecorder2Ex::GetFeaturePage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getfeaturepage)

[IDiscRecorder2Ex::GetSupportedFeaturePages](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getsupportedfeaturepages)