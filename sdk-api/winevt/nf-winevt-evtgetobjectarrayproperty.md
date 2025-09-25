# EvtGetObjectArrayProperty function

## Description

Gets a provider metadata property from the specified object in the array.

## Parameters

### `ObjectArray` [in]

A handle to an array of objects that the [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function returns.

### `PropertyId` [in]

The property identifier of the metadata property that you want to get from the specified object. For possible values, see the Remarks section of [EVT_PUBLISHER_METADATA_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_publisher_metadata_property_id).

### `ArrayIndex` [in]

The zero-based index of the object in the array.

### `Flags` [in]

Reserved. Must be zero.

### `PropertyValueBufferSize` [in]

The size of the *PropertyValueBuffer* buffer, in bytes.

### `PropertyValueBuffer` [in]

A caller-allocated buffer that will receive the metadata property. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `PropertyValueBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

When you call the [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function with the following IDs, the function returns a handle to an array of objects of that type:

* EvtPublisherMetadataChannelReferences
* EvtPublisherMetadataLevels
* EvtPublisherMetadataTasks
* EvtPublisherMetadataOpcodes
* EvtPublisherMetadataKeywords

For example, if you pass **EvtPublisherMetadataKeywords** to [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty), the function returns a handle to an array of keyword objects.

To determine the size of the array, call the [EvtGetObjectArraySize](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetobjectarraysize) function.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EVT_PUBLISHER_METADATA_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_publisher_metadata_property_id)

[EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty)