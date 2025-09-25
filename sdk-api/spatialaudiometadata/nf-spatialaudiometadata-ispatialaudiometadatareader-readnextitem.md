# ISpatialAudioMetadataReader::ReadNextItem

## Description

Gets the number of commands and the sample offset for the metadata item being read.

## Parameters

### `commandCount` [out]

Receives the number of command/value pairs in the metadata item being read.

### `frameOffset` [out]

Gets the frame offset associated with the metadata item being read.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for reading with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-close). |
| **SPTLAUD_MD_CLNT_E_NO_MORE_ITEMS** | There are no more metadata items in the frame range specified in the call to [ReadItemCountInFrames](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt798194(v=vs.85)). |
| **E_INVALIDARG** | One of the provided pointers is not valid. |

## Remarks

Before calling **ReadNextItem**, you must open the [ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader) for reading by calling [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open) after the object is created and after [Close](https://learn.microsoft.com/windows/desktop/CoreAudio/ispatialaudiometadatawriter-close) has been called. You must also call [ReadItemCountInFrames](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt798194(v=vs.85)) before calling **ReadNextItem**.

The [ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader) keeps an internal pointer to the current position within the total range of frames contained by the [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) with which the reader is associated. Each call to this method causes the pointer to be advanced by the number of frames specified in the *readFrameCount* parameter.

The process for reading commands and the associated values is recursive. After each call to **ReadItemCountInFrames**, call **ReadNextItem** to get the number of commands in the next item. After every call to **ReadNextItem**, call [ReadNextItemCommand](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-readnextitemcommand) to read each command for the item. Repeat this process until the entire frame range of the **ISpatialAudioMetadataItems** has been read.

## See also

[ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader)