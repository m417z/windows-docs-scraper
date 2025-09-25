# EvtOpenPublisherMetadata function

## Description

Gets a handle that you use to read the specified provider's metadata.

## Parameters

### `Session` [in, optional]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to get the metadata for a provider on the local computer.

### `PublisherId` [in]

The name of the provider. To enumerate the names of the providers registered on the computer, call the [EvtOpenPublisherEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublisherenum) function.

### `LogFilePath` [in, optional]

The full path to an archived log file that contains the events that the provider logged. An archived log file also contains the provider's metadata. Use this parameter when the provider is not registered on the local computer. Set to **NULL** when reading the metadata from a registered provider..

### `Locale` [in]

The locale identifier to use when accessing the localized metadata from the provider. To create the locale identifier, use the MAKELCID macro. Set to 0 to use the locale identifier of the calling thread.

### `Flags` [in]

Reserved. Must be zero.

## Return value

If successful, the function returns a handle to the provider's metadata; otherwise, **NULL**. If **NULL**, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

 If you specify an archived log file, this function will check for the specified provider's metadata in the log file. If the provider's metadata is not found in the log file, the function will search for the provider in the list of registered providers on the local computer.

To read the provider's metadata, call the [EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty) function. To enumerate the events that the provider defines, call the [EvtOpenEventMetadataEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopeneventmetadataenum) function.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the metadata handle when done.

#### Examples

For an example that shows how to use this function, see [Getting a Provider's Metadata](https://learn.microsoft.com/windows/desktop/WES/getting-a-provider-s-metadata-).

## See also

[EvtGetPublisherMetadataProperty](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetpublishermetadataproperty)

[EvtOpenEventMetadataEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopeneventmetadataenum)

[EvtOpenPublisherEnum](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenpublisherenum)