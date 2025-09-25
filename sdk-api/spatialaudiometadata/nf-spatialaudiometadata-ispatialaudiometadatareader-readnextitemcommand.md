# ISpatialAudioMetadataReader::ReadNextItemCommand

## Description

Reads metadata commands and value data for the current item.

## Parameters

### `commandID` [out]

Receives the command ID for the current command.

### `valueBuffer` [in]

A pointer to a buffer which receives data specific to the command as specified by the
metadata format definition. The buffer must be at least *maxValueBufferLength* to ensure all commands can be successfully retrieved.

### `maxValueBufferLength` [in]

The maximum size of a command value.

### `valueBufferLength` [out]

The size, in bytes, of the data written to the *valueBuffer* parameter.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for reading with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-close). |
| **E_INVALIDARG** | One of the provided pointers is not valid. |

## Remarks

Before calling **ReadNextItem**, you must open the [ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader) for reading by calling [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open) after the object is created and after [Close](https://learn.microsoft.com/windows/desktop/CoreAudio/ispatialaudiometadatawriter-close) has been called. You must also call [ReadItemCountInFrames](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/mt798194(v=vs.85)) and then call [ReadNextItem](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-readnextitem) before calling **ReadNextItem**.

The [ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader) keeps an internal pointer to the current position within the total range of frames contained by the [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) with which the reader is associated. Each call to this method causes the pointer to be advanced by the number of frames specified in the *readFrameCount* parameter.

The process for reading commands and the associated values is recursive. After each call to **ReadItemCountInFrames**, call [ReadNextItem](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatareader-readnextitem) to get the number of commands in the next item. After every call to **ReadNextItem**, call **ReadNextItemCommand** to read each command for the item. Repeat this process until the entire frame range of the **ISpatialAudioMetadataItems** has been read.

## See also

[ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader)