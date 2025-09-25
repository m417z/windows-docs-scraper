# SpatialAudioMetadataCopyMode enumeration

## Description

Specifies the copy mode used when calling [ISpatialAudioMetadataCopier::CopyMetadataForFrames](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-copymetadataforframes).

## Constants

### `SpatialAudioMetadataCopy_Overwrite:0`

Creates a direct copy of the number of metadata items specified with the *copyFrameCount* parameter into destination buffer, overwriting any previously existing data.

### `SpatialAudioMetadataCopy_Append`

Performs an append operation which will fail if the resulting [ISpatialAudioMetadataItemsBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitemsbuffer) has too many items.

### `SpatialAudioMetadataCopy_AppendMergeWithLast`

Performs an append operation, and if overflow occurs, extra items are merged into last item, adopting last merged item's offset value.

### `SpatialAudioMetadataCopy_AppendMergeWithFirst`

Performs an append operation, and if overflow occurs, extra items are merged, assigning the offset to the offset of the first non-overflow item.