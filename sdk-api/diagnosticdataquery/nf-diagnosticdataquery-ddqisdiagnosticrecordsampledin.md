## Description

Fetches the sampled-in state of the device for an event.

## Parameters

### `hSession`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Handle to the Diagnostic Data Query session.

### `providerGroup`

Type: **[GUID\*](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**
Pointer to the provider group GUID.

### `providerId`

Type: **[GUID\*](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**
Pointer to the provider GUID.

### `providerName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The name of the provider.

### `eventId`

Type: **[UNI32\*](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
Pointer to the event ID.

### `eventName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The name of the event.

### `eventVersion`

Type: **[UINT32\*](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The version of the event.

### `eventKeywords`

Type: **[UINT64\*](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
Pointer to the event keywords.

### `isSampledIn`

Type: **[BOOL\*](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
This output parameter is a pointer to a boolean value that is TRUE if the event is sampled in and FALSE otherwise.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**
Returns S_OK on successful completion.

## Remarks

For more information about events and providers, see [**Event Tracing**](https://learn.microsoft.com/windows/win32/etw/event-tracing-portal).

## See also