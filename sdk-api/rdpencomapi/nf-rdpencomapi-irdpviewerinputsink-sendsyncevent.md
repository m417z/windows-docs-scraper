# IRDPViewerInputSink::SendSyncEvent

## Description

[The [IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Sends an event message to indicate a change in the state of the keyboard, such as when the Caps Lock key is pressed.

## Parameters

### `syncFlags`

For possible values, see the [RDPSRAPI_KBD_SYNC_FLAG](https://learn.microsoft.com/windows/win32/api/rdpencomapi/ne-rdpencomapi-rdpsrapi_kbd_sync_flag) enumeration.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPViewerInputSink](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpviewerinputsink)