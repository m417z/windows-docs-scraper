# EvtGetPublisherMetadataProperty function

## Description

Gets the specified provider metadata property.

## Parameters

### `PublisherMetadata` [in]

A handle to the metadata that the [EvtOpenPublisherMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublishermetadata) function returns.

### `PropertyId` [in]

The identifier of the metadata property to retrieve. For a list of property identifiers, see the [EVT_PUBLISHER_METADATA_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_publisher_metadata_property_id) enumeration.

### `Flags` [in]

Reserved. Must be zero.

### `PublisherMetadataPropertyBufferSize` [in]

The size of the *PublisherMetadataPropertyBuffer* buffer, in bytes.

### `PublisherMetadataPropertyBuffer` [in]

A caller-allocated buffer that will receive the metadata property. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `PublisherMetadataPropertyBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

**Caution**

[EvtGetEventMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgeteventmetadataproperty) can return many different kinds of values in the *EventMetadataPropertyBuffer* variable. If *EventMetadataPropertyBuffer*->Type == **EvtVarTypeEvtHandle** then *EventMetadataPropertyBuffer* contains a handle that needs to be freed. When you are done with the handle, call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EvtOpenPublisherMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublishermetadata)