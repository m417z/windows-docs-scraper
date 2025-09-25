# EvtOpenPublisherEnum function

## Description

Gets a handle that you use to enumerate the list of registered providers on the computer.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to enumerate the registered providers on the local computer.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a handle to the list of registered providers; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

To enumerate the registered providers, call the [EvtNextPublisherId](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnextpublisherid) function in a loop.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the enumerator handle when done.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EvtNextPublisherId](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnextpublisherid)