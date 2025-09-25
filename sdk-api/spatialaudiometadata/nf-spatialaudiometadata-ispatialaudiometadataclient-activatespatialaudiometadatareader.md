# ISpatialAudioMetadataClient::ActivateSpatialAudioMetadataReader

## Description

Creates an [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter) object for reading spatial audio metadata items from an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object.

## Parameters

### `metadataReader` [out]

Receives a pointer to an instance of [ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The provided pointer is not valid. |

## See also

[ISpatialAudioMetadataClient](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataclient)