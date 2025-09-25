# ISpatialAudioMetadataCopier::CopyMetadataForFrames

## Description

Copies metadata items from the source [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems), provided to the [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-open) method, object to the destination **ISpatialAudioMetadataItems** object, specified with the *dstMetadataItems* parameter. Each call advances the internal copy position by the number of frames in the *copyFrameCount* parameter.

## Parameters

### `copyFrameCount` [in]

The number of frames from the current copy position for which metadata items are copied. After the copy, the internal copy position within the source **SpatialAudioMetadataItems** is advanced the value specified in this parameter. Set this value to 0 to copy the entire frame range contained in the source **SpatialAudioMetadataItems**.

### `copyMode` [in]

A value that specifies the copy mode for the operation.

### `dstMetadataItems` [in]

A pointer to the destination **SpatialAudioMetadataItems** for the copy operation.

### `itemsCopied` [out]

Receives number of metadata items copied in the operation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUD_MD_CLNT_E_NO_ITEMS_OPEN** | The [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) has not been opened for copying with a call to [Open](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-open) or the object has been closed for writing with a call to [Close](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nf-spatialaudiometadata-ispatialaudiometadatacopier-close). |
| **E_INVALIDARG** | One of the provided pointers is not valid. |

## See also

[ISpatialAudioMetadataCopier](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatacopier)