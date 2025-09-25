# ISpatialAudioMetadataClient::ActivateSpatialAudioMetadataWriter

## Description

Creates an [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter) object for writing spatial audio metadata items to an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object.

## Parameters

### `overflowMode` [in]

A value that specifies the behavior when attempting to write more metadata items to the [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) than the maximum number of items specified when calling [ActivateSpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadataclient-activatespatialaudiometadataitems).

### `metadataWriter` [out]

Receives a pointer to an instance of [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The provided pointer is not valid. |

## See also

[ISpatialAudioMetadataClient](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataclient)