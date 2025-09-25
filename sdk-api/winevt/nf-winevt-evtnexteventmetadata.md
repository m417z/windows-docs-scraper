# EvtNextEventMetadata function

## Description

Gets an event definition from the enumerator.

## Parameters

### `EventMetadataEnum` [in]

A handle to the event definition enumerator that the [EvtOpenEventMetadataEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopeneventmetadataenum) function returns.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a handle to the event's metadata; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

Call this function in a loop until the function returns **NULL** and the error code is ERROR_NO_MORE_ITEMS.

To get a property from the event definition, call the [EvtGetEventMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgeteventmetadataproperty) function.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the event definition handle when done.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EvtGetEventMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgeteventmetadataproperty)