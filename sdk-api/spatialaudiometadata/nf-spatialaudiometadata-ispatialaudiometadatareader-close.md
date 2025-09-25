# ISpatialAudioMetadataReader::Close

## Description

Completes any necessary operations on the [SpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object and releases the object.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for reading with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-close). |

## See also

[ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader)