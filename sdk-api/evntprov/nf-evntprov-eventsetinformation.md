# EventSetInformation function

## Description

Configures an ETW event provider.

## Parameters

### `RegHandle` [in]

Event provider registration handle. This is a handle returned by
[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister).

### `InformationClass` [in]

[EVENT_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/evntprov/ne-evntprov-event_info_class)
value that specifies the configuration operation to be performed on the event
provider.

### `EventInformation` [in]

Pointer to a buffer that contains data to be used when configuring the event
provider. The format of the data in this buffer depends on the value specified
in the _InformationClass_ parameter.

This value may be `NULL` if _InformationLength_ is zero.

### `InformationLength` [in]

The size (in bytes) of the data in the _EventInformation_ buffer.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes.

- **ERROR_INVALID_PARAMETER**: The parameter is incorrect. For example, this
error is returned if the _RegHandle_ parameter is not a valid provider
registration handle, if _EventInformation_ is **NULL** but _InformationLength_
is nonzero, or if the specified _InformationLength_ is not valid for the given
_InformationClass_.
- **ERROR_NOT_SUPPORTED**: The request is not supported. This error is returned
if the _InformationClass_ parameter is not a recognized value.
- **Other**: Use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to
obtain the message string for the returned error.

## See also

[EVENT_INFO_CLASS](https://learn.microsoft.com/windows/desktop/api/evntprov/ne-evntprov-event_info_class)

[EventRegister](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventregister)