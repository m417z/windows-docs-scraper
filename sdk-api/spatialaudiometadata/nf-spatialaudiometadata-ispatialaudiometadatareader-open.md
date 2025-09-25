# ISpatialAudioMetadataReader::Open

## Description

Opens an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object for reading.

## Parameters

### `metadataItems` [in]

A pointer to an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object to be opened for reading

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_ITEMS_ALREADY_OPEN** | **Open** has already been called on the supplied [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) since the object was created or since the last call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-close). |
| **E_INVALIDARG** | The provided pointer is not valid. |

## See also

[ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader)