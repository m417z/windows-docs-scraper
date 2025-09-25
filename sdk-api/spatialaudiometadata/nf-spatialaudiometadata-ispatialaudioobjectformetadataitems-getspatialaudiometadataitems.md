# ISpatialAudioObjectForMetadataItems::GetSpatialAudioMetadataItems

## Description

Gets a pointer to the [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object which stores metadata items for the [ISpatialAudioObjectForMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadataitems).

## Parameters

### `metadataItems` [out]

Receives a pointer to the [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) associated with the [ISpatialAudioObjectForMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadataitems).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The supplied pointer is invalid. |

## Remarks

The client must free this object when it is no longer being used by calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## See also

[ISpatialAudioObjectForMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadataitems)