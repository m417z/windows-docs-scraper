# ISpatialAudioMetadataWriter::Close

## Description

Completes any needed operations on the metadata buffer and releases the specified [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The supplied [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open). |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_WRITTEN** | No metadata items have been written to the supplied [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems). |
| **SPTLAUD_MD_CLNT_E_ITEM_MUST_HAVE_COMMANDS** | No metadata commands have been written to the supplied [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems). |

## See also

[ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter)