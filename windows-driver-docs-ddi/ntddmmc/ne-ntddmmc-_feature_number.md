# FEATURE_NUMBER enumeration

## Description

The **FEATURE_NUMBER** enumeration provides a list of the features that are defined by the *Multimedia Commands - 4 (MMC-4)* specification.

## Constants

### `FeatureProfileList`

Indicates the feature named "Profile List" by the *MMC-3* specification. This feature provides a list of all profiles supported by the device.

### `FeatureCore`

Indicates the feature named "Core" by the *MMC-3* specification. This feature encompasses the basic functionality which is mandatory for all devices that support the *MMC-3* standard. See the *MMC-3* specification for a description of the capabilities included in the Core feature.

### `FeatureMorphing`

Indicates the feature named "Morphing" by the *MMC-3* specification. Devices that support this feature can notify the initiator of operational changes and allow the initiator to prevent operational changes.

### `FeatureRemovableMedium`

Indicates the feature named "Removable Medium" by the *MMC-3* specification. Devices that support this feature allow the medium to be removed from the device. They also can communicate to the initiator that the user wants to eject the medium or has inserted a new medium.

### `FeatureWriteProtect`

Indicates the feature named "Write Protect" by the *MMC-3* specification. Devices that support this feature allow the initiator to change the write-protection state of the media programmatically.

### `FeatureRandomReadable`

Indicates the feature named "Random Readable" by the *MMC-3* specification. Devices that support this feature allow the initiator to read blocks of data on the disk at random locations. These devices do not require that the initiator address disk locations in any particular order.

### `FeatureMultiRead`

Indicates the feature named "MultiRead," originally defined by the Optical Storage Technology Association (OSTA) and incorporated into the *MMC-3* specification. Devices that support this feature can read all CD media types.

### `FeatureCdRead`

Indicates the feature named "CD Read" by the *MMC-3* specification. Devices that support this feature can read CD-specific information from the media and can read user data from all types of CD blocks.

### `FeatureDvdRead`

Indicates the feature named "DVD Read" by the *MMC-3* specification. Devices that support this feature can read DVD-specific information from the media.

### `FeatureRandomWritable`

Indicates the feature named "Random Writable" by the *MMC-3* specification. Devices that support this feature can write blocks of data to random locations on the disk. These devices do not require that the initiator address disk locations in any particular order.

### `FeatureIncrementalStreamingWritable`

Indicates the feature named "Incremental Streaming Writable" by the *MMC-3* specification. Devices that support this feature can append data to a limited number of locations on the media.

### `FeatureSectorErasable`

Indicates the feature named "Sector Erasable" by the *MMC-3* specification. Devices that support this feature require an erase pass before overwriting existing data.

### `FeatureFormattable`

Indicates the feature named "Formattable" by the *MMC-3* specification. Devices that support this feature can format media into logical blocks.

### `FeatureDefectManagement`

Indicates the feature named "Defect Management" by the *MMC-3* specification. Devices that support this feature are able to provide contiguous address space that is guaranteed to be defect free.

### `FeatureWriteOnce`

Indicates the feature named "Write Once" by the *MMC-3* specification. Devices that support this feature can write to any previously unused logical block.

### `FeatureRestrictedOverwrite`

Indicates the feature named "Restricted Overwrite" by the *MMC-3* specification. Devices that support this feature are limited in regard to which logical blocks they can overwrite at any given time.

### `FeatureCdrwCAVWrite`

Indicates the feature named "CD-RW CAV Write" by the *MMC-3* specification. Devices that support this feature can perform writes on CD-RW media in CAV mode.

### `FeatureMrw`

Indicates the feature named "MRW" by the *MMC-3* specification. Devices that support this feature can recognize, read and optionally write MRW formatted media.

### `FeatureEnhancedDefectReporting`

### `FeatureDvdPlusRW`

Indicates the feature named "DVD+RW" by the *MMC-3* specification. Devices that support this feature can recognize, read and optionally write DVD+RW media.

### `FeatureDvdPlusR`

### `FeatureRigidRestrictedOverwrite`

Indicates the feature named "DVD-RW Restricted Overwrite" by the *MMC-3* specification. Devices that support this feature can only write on block boundaries. These devices cannot perform read or write operations that transfer less than a block of data.

### `FeatureCdTrackAtOnce`

Indicates the feature named "CD Track at Once" by the *MMC-3* specification. Devices that support this feature can write data to a CD track.

### `FeatureCdMastering`

Indicates the feature named "CD Mastering" by the *MMC-3* specification. Devices that support this feature can write to a CD in either "Session-at-Once" mode or raw mode.

### `FeatureDvdRecordableWrite`

Indicates the feature named "DVD-R Write" by the *MMC-3* specification. Devices that support this feature can write data to a write-once DVD media in "Disc-at-Once" mode.

### `FeatureDDCDRead`

Indicates the feature named "DDCD Read" by the *MMC-3* specification. Devices that support this feature can read user data from DDCD blocks.

### `FeatureDDCDRWrite`

Indicates the feature named "DDCD-R Write" by the *MMC-3* specification. Devices that support this feature can read and write DDCD-R media.

### `FeatureDDCDRWWrite`

Indicates the feature named "DDCD-RW Write" by the *MMC-3* specification. Devices that support this feature can read and write DDCD-RW media.

### `FeatureLayerJumpRecording`

Reserved 0x0034 - 0x0036

### `FeatureCDRWMediaWriteSupport`

Indicates the feature named "CD-RW Media Write Support" by the *MMC-4* specification. Devices that support this feature can write CD-RW media.

### `FeatureBDRPseudoOverwrite`

Reserved 0x0039

### `FeatureDvdPlusRWDualLayer`

Indicates the feature named "DVD+RW Dual Layer".

### `FeatureDvdPlusRDualLayer`

Indicates the feature named "DVD+R Dual Layer".

### `FeatureBDRead`

Indicates the feature named "BD Read".

### `FeatureBDWrite`

Indicates the feature named "BD Write".

### `FeatureTSR`

Indicates the feature named "TSR".

### `FeatureHDDVDRead`

Indicates the feature named "HD-DVD Read".

### `FeatureHDDVDWrite`

Indicates the feature named "HD-DVD Write".

### `FeatureHybridDisc`

Indicates the feature named "Hybrid Disc".

### `FeaturePowerManagement`

Indicates the feature named "Power Management" by the *MMC-3* specification. Devices that support this feature can perform both initiator and logical-unit directed power management.

### `FeatureSMART`

Indicates the feature named "S.M.A.R.T." by the *MMC-3* specification. Devices that support this feature support Self-Monitoring Analysis and Reporting Technology (SMART).

### `FeatureEmbeddedChanger`

Indicates the feature named "Embedded Changer" by the *MMC-3* specification. Devices that support this feature can move media back and forth between a media storage area and the mechanism that actually accesses the media.

### `FeatureCDAudioAnalogPlay`

Indicates the feature named "CD Audio External Play" by the *MMC-3* specification. Devices that support this feature can play CD audio data and channel it directly to an external output.

### `FeatureMicrocodeUpgrade`

Indicates the feature named "Microcode Upgrade" by the *MMC-3* specification. Devices that support this feature can upgrade their internal microcode by means of a published interface.

### `FeatureTimeout`

Indicates the feature named "Time-Out" by the *MMC-3* specification. Devices that have this feature must respond to commands within a set time period. When these devices cannot complete commands in the allotted time, they complete the commands with an error.

### `FeatureDvdCSS`

Indicates the feature named "DVD-CSS" by the *MMC-3* specification. Devices that support this feature can perform DVD Content Scrambling System (DVD-CSS) authentication and key management.

### `FeatureRealTimeStreaming`

Indicates the feature named "Real Time Streaming" by the *MMC-3* specification. Devices that support this feature allow the initiator to specify the performance level of the device within certain limits allowed by the device. These devices must also indicate to the initiator whether they support stream playback operations.

### `FeatureLogicalUnitSerialNumber`

Indicates the feature named "Device Serial Number" by the *MMC-3* specification. Devices that support this feature can furnish the initiator with a serial number that uniquely identifies the device.

### `FeatureMediaSerialNumber`

Indicates the feature named "Media Serial Number".

### `FeatureDiscControlBlocks`

Indicates the feature named "Disc Control Blocks" by the *MMC-3* specification. Devices that support this feature can read or write Disc Control Blocks.

### `FeatureDvdCPRM`

Indicates the feature named "DVD CPRM" by the *MMC-3* specification. Devices that support this feature can perform DVD Content Protection for Recordable Media (CPRM) authentication and key management.

### `FeatureFirmwareDate`

Indicates the feature named "Firmware Date".

### `FeatureAACS`

Indicates the feature named "AACS".

### `FeatureVCPS`

Indicates the feature named "VCPS".

## See also

[**FEATURE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddmmc/ns-ntddmmc-_feature_header)