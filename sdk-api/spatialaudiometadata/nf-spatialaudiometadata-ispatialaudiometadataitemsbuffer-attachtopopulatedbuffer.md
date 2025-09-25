# ISpatialAudioMetadataItemsBuffer::AttachToPopulatedBuffer

## Description

Attaches a previously populated buffer for storage of [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) objects. The metadata items already in the buffer are retained.

## Parameters

### `buffer` [in]

A pointer to memory to use for storage.

### `bufferLength`

The length of the supplied buffer. This size must match the length required for the metadata format and maximum metadata item count.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for copying with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-close). |
| **SPTLAUD_MD_CLNT_E_BUFFER_ALREADY_ATTACHED** | The supplied buffer has already been attached. |
| **SPTLAUD_MD_CLNT_E_ATTACH_FAILED_INTERNAL_BUFFER** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) was created to use a media pipeline internal buffer, so an external buffer can't be attached. |
| **SPTLAUD_MD_CLNT_E_FORMAT_MISMATCH** | The supplied populated buffer uses a format that is different from the current format. |
| **E_INVALIDARG** | One of the provided pointers is not valid.<br><br>The supplied buffer is not large enough to hold the maximum number of metadata items. Call [GetSpatialAudioMetadataItemsBufferLength](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadataclient-getspatialaudiometadataitemsbufferlength) to determine the required buffer size. |

## See also

[ISpatialAudioMetadataItemsBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitemsbuffer)