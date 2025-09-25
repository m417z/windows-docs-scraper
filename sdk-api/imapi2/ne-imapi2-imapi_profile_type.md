# IMAPI_PROFILE_TYPE enumeration

## Description

Defines values for the possible profiles of a CD and DVD device. A profile defines the type of media and features that the device supports.

## Constants

### `IMAPI_PROFILE_TYPE_INVALID:0`

The profile is not valid.

### `IMAPI_PROFILE_TYPE_NON_REMOVABLE_DISK:0x1`

The hard disk it not removable.

### `IMAPI_PROFILE_TYPE_REMOVABLE_DISK:0x2`

The hard disk is removable.

### `IMAPI_PROFILE_TYPE_MO_ERASABLE:0x3`

An Magneto-Optical Erasable drive.

### `IMAPI_PROFILE_TYPE_MO_WRITE_ONCE:0x4`

A write once optical drive.

### `IMAPI_PROFILE_TYPE_AS_MO:0x5`

An advance storage Magneto-Optical drive.

### `IMAPI_PROFILE_TYPE_CDROM:0x8`

A CD-ROM drive.

### `IMAPI_PROFILE_TYPE_CD_RECORDABLE:0x9`

A CD-R drive.

### `IMAPI_PROFILE_TYPE_CD_REWRITABLE:0xa`

A CD-RW or CD+RW drive.

### `IMAPI_PROFILE_TYPE_DVDROM:0x10`

A DVD-ROM drive.

### `IMAPI_PROFILE_TYPE_DVD_DASH_RECORDABLE:0x11`

A DVD-R sequential recording drive.

### `IMAPI_PROFILE_TYPE_DVD_RAM:0x12`

A DVD-RAM drive.

### `IMAPI_PROFILE_TYPE_DVD_DASH_REWRITABLE:0x13`

A DVD-RW restricted overwrite drive.

### `IMAPI_PROFILE_TYPE_DVD_DASH_RW_SEQUENTIAL:0x14`

A DVD-RW sequential recording drive.

### `IMAPI_PROFILE_TYPE_DVD_DASH_R_DUAL_SEQUENTIAL:0x15`

A DVD-R dual layer sequential recording drive.

### `IMAPI_PROFILE_TYPE_DVD_DASH_R_DUAL_LAYER_JUMP:0x16`

A DVD-R dual layer jump recording drive.

### `IMAPI_PROFILE_TYPE_DVD_PLUS_RW:0x1a`

A DVD+RW drive.

### `IMAPI_PROFILE_TYPE_DVD_PLUS_R:0x1b`

A DVD+R drive.

### `IMAPI_PROFILE_TYPE_DDCDROM:0x20`

A double density CD drive.

**Note** This profile has been deprecated.

### `IMAPI_PROFILE_TYPE_DDCD_RECORDABLE:0x21`

A double density CD-R drive.

**Note** This profile has been deprecated.

### `IMAPI_PROFILE_TYPE_DDCD_REWRITABLE:0x22`

A double density CD-RW drive.

**Note** This profile has been deprecated.

### `IMAPI_PROFILE_TYPE_DVD_PLUS_RW_DUAL:0x2a`

A DVD+RW dual layer drive.

### `IMAPI_PROFILE_TYPE_DVD_PLUS_R_DUAL:0x2b`

A DVD+R dual layer drive.

### `IMAPI_PROFILE_TYPE_BD_ROM:0x40`

A Blu-ray read only drive.

### `IMAPI_PROFILE_TYPE_BD_R_SEQUENTIAL:0x41`

A write once Blu-ray drive with sequential recording.

### `IMAPI_PROFILE_TYPE_BD_R_RANDOM_RECORDING:0x42`

A write once Blu-ray drive with random-access recording capability.

### `IMAPI_PROFILE_TYPE_BD_REWRITABLE:0x43`

A rewritable Blu-ray drive.

### `IMAPI_PROFILE_TYPE_HD_DVD_ROM:0x50`

A read only high density DVD drive.

### `IMAPI_PROFILE_TYPE_HD_DVD_RECORDABLE:0x51`

A write once high density DVD drive.

### `IMAPI_PROFILE_TYPE_HD_DVD_RAM:0x52`

A high density DVD drive with random access positioning.

### `IMAPI_PROFILE_TYPE_NON_STANDARD:0xffff`

Nonstandard drive.

## Remarks

Note that the range of feature type values is 0x0000 to 0xFFFF. This enumeration contains those features defined in the Multimedia Commands - 5 (MMC) specification. For a complete definition of each profile, see Profile Definitions in the latest release of the MMC specification at ftp://ftp.t10.org/t10/drafts/mmc5.

Other values not defined here may exist. Consumers of this enumeration should not presume this list to be the only set of valid values.

## See also

[IDiscRecorder2::get_SupportedProfiles](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_supportedprofiles)

[IDiscRecorder2Ex::GetSupportedProfiles](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getsupportedprofiles)