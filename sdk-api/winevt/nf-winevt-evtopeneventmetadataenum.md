# EvtOpenEventMetadataEnum function

## Description

Gets a handle that you use to enumerate the list of events that the provider defines.

## Parameters

### `PublisherMetadata` [in]

A handle to the provider's metadata that the [EvtOpenPublisherMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublishermetadata) function returns.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a handle to the list of events that the provider defines; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

To enumerate the events, call the [EvtNextEventMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnexteventmetadata) function in a loop.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the enumerator handle when done.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EvtGetEventMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgeteventmetadataproperty)

[EvtNextEventMetadata](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnexteventmetadata)