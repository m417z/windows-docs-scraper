# ISpatialAudioMetadataClient::ActivateSpatialAudioMetadataItems

## Description

Creates an [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object for storing spatial audio metadata items.

## Parameters

### `maxItemCount` [in]

The maximum number of metadata items that can be stored in the returned [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems).

### `frameCount` [in]

The valid range of frame offset positions for metadata items stored in the returned [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems).

### `metadataItemsBuffer` [out, optional]

If a pointer is supplied, returns an [ISpatialAudioMetadataItemsBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitemsbuffer) interface which provides methods for attaching caller-provided memory for storage of metadata items. If this parameter is NULL, the object will allocate internal storage for the items. This interface cannot be obtained via [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

### `metadataItems` [out]

Receives an instance [ISpatialAudioMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataitems) object which can be populated with metadata items using an by [ISpatialAudioMetadataWriter](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatawriter) or [ISpatialAudioMetadataCopier](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatacopier) and can be read with an [ISpatialAudioMetadataReader](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadatareader).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The pointer provided in the *metadataItems* parameter is not valid.<br><br>The value of *maxItemCount* or *frameCount* is 0. |

## See also

[ISpatialAudioMetadataClient](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudiometadataclient)