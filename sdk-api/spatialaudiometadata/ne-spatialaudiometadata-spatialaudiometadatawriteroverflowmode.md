# SpatialAudioMetadataWriterOverflowMode enumeration

## Description

Specifies the desired behavior when an [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter) attempts to write more items into the metadata buffer than was specified when the client was initialized.

## Constants

### `SpatialAudioMetadataWriterOverflow_Fail:0`

The write operation will fail.

### `SpatialAudioMetadataWriterOverflow_MergeWithNew`

The write operation will succeed, the overflow item will be merged with previous item and adopt the frame offset of newest item.

### `SpatialAudioMetadataWriterOverflow_MergeWithLast`

The write operation will succeed, the overflow item will be merged with previous item and keep the existing frame offset.