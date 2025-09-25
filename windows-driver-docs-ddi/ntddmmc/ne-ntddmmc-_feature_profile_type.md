# _FEATURE_PROFILE_TYPE enumeration

## Description

The FEATURE_PROFILE_TYPE enumeration provides a list of the profile names that are defined by the *SCSI Multimedia - 4 (MMC-4)* specification.

## Constants

### `ProfileInvalid`

Does not indicate a valid profile.

### `ProfileNonRemovableDisk`

Indicates the profile named "Nonremovable disk" by the *SCSI-3 Multimedia (MMC-3)* specification. This profile is used with devices that manage rewritable media and are capable of changing behavior.

### `ProfileRemovableDisk`

Indicates the profile named "Removable disk" by the *MMC-3* specification. This profile is used with devices that manage rewritable, removable media.

### `ProfileMOErasable`

Indicates the profile named "MO Erasable" by the *MMC-3* specification. This profile is used with devices that manage magneto-optical media and that have a sector-erase capability.

### `ProfileMOWriteOnce`

Indicates the profile named "MO Write Once" by the *MMC-3* specification. This profile is used with devices that manage magneto-optical write-once media.

### `ProfileAS_MO`

Indicates the profile named "AS-MO" by the *MMC-3* specification. This profile is used with devices that implement Advance Storage technology and manage magneto-optical media.

### `ProfileCdrom`

Indicates the profile named "CD-ROM" by the *MMC-3* specification. This profile is used with devices that manage read-only compact disc media.

### `ProfileCdRecordable`

Indicates the profile named "CD-R" by the *MMC-3* specification. This profile is used with devices that manage write-once compact disc media.

### `ProfileCdRewritable`

Indicates the profile named "CD-RW" by the *MMC-3* specification. This profile is used with devices that manage rewritable compact disc media.

### `ProfileDvdRom`

Indicates the profile named "DVD-ROM" by the *MMC-3* specification. This profile is used with devices that manage read-only DVD media.

### `ProfileDvdRecordable`

Indicates the profile named "DVD-R" by the *MMC-3* specification. This profile is used with devices that manage write-once DVD media and operate in sequential recording mode.

### `ProfileDvdRam`

Indicates the profile named "DVD-RAM or DVD+RW" by the *MMC-3* specification. This profile is used with devices that manage rewritable DVD media.

### `ProfileDvdRewritable`

Indicates the profile named "DVD-RW Restricted Overwrite" by the *MMC-3* specification. This profile is used with devices that manage rerecordable DVD media and operate in packet-writing mode.

### `ProfileDvdRWSequential`

Indicates the profile named "DVD-RW Sequential Recording" by the *MMC-3* specification. This profile is used with devices that implement a series of features associated with sequential recording, such as the features "Incremental Streaming Writable" and "Real-Time Streaming". For a full list of the features supported with this profile, see the *MMC-3* specification.

### `ProfileDvdDashRDualLayer`

### `ProfileDvdDashRLayerJump`

Reserved 0x0017 - 0x0019

### `ProfileDvdPlusRW`

Indicates the profile named "DVD+RW" by the *MMC-3* specification. This profile is used with devices that implement a series of features required to manage DVD media that is both readable and writable. For a full list of the features supported with this profile, see the *MMC-3* specification.

### `ProfileDvdPlusR`

Reserved 0x001C - 001F

### `ProfileDDCdrom`

Indicates the profile named "DDCD-ROM" by the *MMC-3* specification. This profile is used with devices that can read "DDCD specific structure." For a full list of the features supported with this profile, see the *MMC-3* specification.

### `ProfileDDCdRecordable`

Indicates the profile named "DDCD-R" by the *MMC-3* specification. This profile is used with devices that can read "DDCD-R specific structure." For a full list of the features supported with this profile, see the *MMC-3* specification.

### `ProfileDDCdRewritable`

Indicates the profile named "DDCD-RW" by the *MMC-3* specification. This profile is used with devices that can read "DDCD-RW specific structure." For a full list of the features supported with this profile, see the *MMC-3* specification.

### `ProfileDvdPlusRWDualLayer`

### `ProfileDvdPlusRDualLayer`

Reserved 0x002C - 0x003F

### `ProfileBDRom`

### `ProfileBDRSequentialWritable`

BD-R 'SRM'

### `ProfileBDRRandomWritable`

BD-R 'RRM'

### `ProfileBDRewritable`

Reserved 0x0044 - 0x004F

### `ProfileHDDVDRom`

### `ProfileHDDVDRecordable`

### `ProfileHDDVDRam`

### `ProfileHDDVDRewritable`

Reserved 0x0054 - 0x0057

### `ProfileHDDVDRDualLayer`

Reserved 0x0059 - 0x0059

### `ProfileHDDVDRWDualLayer`

Reserved 0x005B - 0xfffe

### `ProfileNonStandard`

Indicates that the device does not conform to any profile.

## See also

[FEATURE_DATA_PROFILE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_data_profile_list)