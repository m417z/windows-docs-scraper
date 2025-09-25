# EvtNextPublisherId function

## Description

Gets the identifier of a provider from the enumerator.

## Parameters

### `PublisherEnum` [in]

A handle to the registered providers enumerator that the [EvtOpenPublisherEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublisherenum) function returns.

### `PublisherIdBufferSize` [in]

The size of the *PublisherIdBuffer* buffer, in characters.

### `PublisherIdBuffer` [in]

A caller-allocated buffer that will receive the name of the registered provider. You can set this parameter to **NULL** to determine the required buffer size.

### `PublisherIdBufferUsed` [out]

The size, in characters, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

Call this function in a loop until the function returns **FALSE** and the error code is ERROR_NO_MORE_ITEMS.

This list of provider names is not sorted alphabetically.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EvtOpenPublisherMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublishermetadata)