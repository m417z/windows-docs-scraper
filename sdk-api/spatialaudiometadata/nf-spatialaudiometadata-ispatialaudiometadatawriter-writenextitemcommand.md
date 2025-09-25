# ISpatialAudioMetadataWriter::WriteNextItemCommand

## Description

Writes metadata commands and value data to the current item.

## Parameters

### `commandID` [in]

A command supported by the metadata format of the object. The call will fail if the command not defined by metadata format. Each command can
only be written once per item.

### `valueBuffer` [in]

A pointer to a buffer which stores data specific to the command as specified by the
metadata format definition.

### `valueBufferLength` [in]

The size, in bytes, of the command data supplied in the *valueBuffer* parameter. The size must match command definition specified by the metadata format or the call will fail.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for writing with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/CoreAudio/ispatialaudiometadatawriter-close). |
| **SPTLAUD_MD_CLNT_E_NO_ITEMOFFSET_WRITTEN** | [WriteNextItem](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-writenextitem) was not called after [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open) was called and before the call to **WriteNextItemCommand**. |

## Remarks

You must open the [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter) for writing by calling [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-open), and set the current metadata item offset by calling [WriteNextItem](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatawriter-writenextitem) before calling **WriteNextItemCommand**.

## See also

[ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter)