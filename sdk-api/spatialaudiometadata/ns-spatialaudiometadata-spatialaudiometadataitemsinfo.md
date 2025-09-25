# SpatialAudioMetadataItemsInfo structure

## Description

Provides information about an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object. Get a copy of this structure by calling [GetInfo](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadataitems-getinfo).

## Members

### `FrameCount`

The total frame count, which defines valid item offsets.

### `ItemCount`

The current number of items stored.

#### MaxItemCount

The maximum number of items allowed.

##### MaxValueBufferLength

The size of the largest command value defined by the metadata format.

### `MaxItemCount`

### `MaxValueBufferLength`