# ISpatialAudioMetadataClient::GetSpatialAudioMetadataItemsBufferLength

## Description

Gets the length of the buffer required to store the specified number of spatial audio metadata items. Use this method to determine the correct buffer size to use when attaching caller-provided memory through the [ISpatialAudioMetadataItemsBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitemsbuffer) interface.

## Parameters

### `maxItemCount` [in]

The maximum number of metadata items to be stored in an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object.

### `bufferLength` [out]

The length of the buffer required to store the number of spatial audio metadata items specified in the *maxItemCount* parameter.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The provided pointer is not valid.<br><br>The value of *maxItemCount* or *frameCount* is 0. |

## See also

[ISpatialAudioMetadataClient](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataclient)