# ISpatialAudioMetadataWriter::Open

## Description

Opens an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object for writing.

## Parameters

### `metadataItems` [in]

A pointer to an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object to be opened for writing.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_ITEMS_ALREADY_OPEN** | **Open** has already been called on the supplied [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) since the object was created or since the last call to [Close](https://learn.microsoft.com/windows/desktop/CoreAudio/ispatialaudiometadatawriter-close). |
| **E_INVALIDARG** | The provided pointer is not valid. |

## See also

[ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter)