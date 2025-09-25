# TdhEnumerateManifestProviderEvents function

## Description

The **TdhEnumerateManifestProviderEvents** function retrieves the list of events present in the provider manifest.

## Parameters

### `ProviderGuid` [in]

A GUID that identifies the manifest provider whose list of events you want to retrieve.

### `Buffer` [out]

A user-allocated buffer to receive the list of events. For details, see the [PROVIDER_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_event_info) structure.

### `BufferSize` [in, out]

The size, in bytes, of the buffer pointed to by the *ProviderInfo* parameter. If the function succeeds, this parameter receives the size of the buffer used. If the buffer is too small, the function returns **ERROR_INSUFFICIENT_BUFFER** and sets this parameter to the required buffer size. If the buffer size is zero on input, no data is returned in the buffer and this parameter receives the required buffer size.

## Return value

Returns **ERROR_SUCCESS** if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_EMPTY** | There are no events defined for the provider GUID in the manifest. |
| **ERROR_FILE_NOT_FOUND** | The metadata for the provider was not found. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the *ProviderInfo* buffer is too small. Use the required buffer size set in the *BufferSize* parameter to allocate a new buffer. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_NOT_FOUND** | The schema information for supplied provider GUID was not found. |

## See also
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)

[PROVIDER_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_event_info)

[TdhGetManifestEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetmanifesteventinformation)