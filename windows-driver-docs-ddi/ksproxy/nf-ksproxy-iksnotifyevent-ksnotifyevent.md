# IKsNotifyEvent::KsNotifyEvent

## Description

**DirectX 9.0 and later versions only.**

The **KsNotifyEvent** method requests that the KS object that owns the given DirectShow event notify the calling application with the given parameters whenever action related to the event occurs.

## Parameters

### `Event` [in]

Identifies the type of DirectShow event.

### `lParam1` [in]

Specifies the first data parameter for the event.

### `lParam2` [in]

Specifies the second data parameter for the event.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## See also

[IMediaEvent](https://learn.microsoft.com/windows/win32/api/control/nn-control-imediaevent)