# IMFSpatialAudioObjectBuffer::GetMetadataItems

## Description

Retrieves a pointer to a buffer that may
contain spatial audio metadata.

## Parameters

### `ppMetadataItems` [out]

A pointer to an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object in which the collection
of metadata items will be stored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied pointer is invalid. |

## Remarks

The metadata is written to the [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) collection in a format identified by the [MF_MT_SPATIAL_AUDIO_OBJECT_METADATA_FORMAT_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-spatial-audio-object-metadata-format-id) media type attribute specified during media type negotiation phase of Media Foundation topology construction.

## See also

[IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer)