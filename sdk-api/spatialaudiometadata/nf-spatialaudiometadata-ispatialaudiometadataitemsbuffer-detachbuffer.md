# ISpatialAudioMetadataItemsBuffer::DetachBuffer

## Description

Detaches the buffer. Memory can only be attached to a single metadata item at a time.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for copying with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-close). |
| **SPTLAUD_MD_CLNT_E_ATTACH_FAILED_INTERNAL_BUFFER** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) was created to use a media pipeline internal buffer which can't be detached. |
| **SPTLAUD_MD_CLNT_E_BUFFER_NOT_ATTACHED** | The supplied buffer is not attached. |
| **E_INVALIDARG** | One of the provided pointers is not valid.<br><br>The supplied buffer is not large enough to hold the maximum number of metadata items. |

## See also

[ISpatialAudioMetadataItemsBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitemsbuffer)