# IPrintAsyncNotifyChannel::SendNotification

## Description

Sends a notification from a component that is hosted by the print spooler to one or more listening applications, or sends a response from an application back to a component.

## Parameters

### `pData` [in]

A pointer to the content of the notification and its size and type.

## Return value

| HRESULT | Severity | Meaning |
| --- | --- | --- |
| S_OK | SUCCESS | The function completed successfully. |
| ASYNC_CALL_ALREADY_PARKED | ERROR | A notification cannot be sent because the recipient has not consumed the previous notification. |
| ASYNC_CALL_IN_PROGRESS | ERROR | The channel is busy with another notification or response. |
| ASYNC_NOTIFICATION_FAILURE | ERROR | None of the listeners on this channel are configured to receive this notification type or there was a problem allocating the resources necessary to complete this call. |
| CHANNEL_ACQUIRED | ERROR | Another listener has acquired this channel. The notification was not sent. The original listener will no longer receive notifications. |
| CHANNEL_ALREADY_CLOSED | ERROR | The notification could not be sent because the channel was closed prior to this call. |
| CHANNEL_NOT_OPENED | ERROR | The notification could not be sent because the channel was not opened prior to this call. |
| CHANNEL_WAITING_FOR_CLIENT_NOTIFICATION | ERROR | A notification cannot be sent because a response to the last notification has not been received. |
| INVALID_NOTIFICATION_TYPE | ERROR | The specified notification type is invalid. |
| MAX_NOTIFICATION_SIZE_EXCEEDED | ERROR | The maximum size of the notification data has been exceeded. By default, the maximum data size allowed is 10 megabytes. |
| NO_LISTENERS | SUCCESS | Indicates that there are no registered listening applications. |
| UNIRECTIONAL_NOTIFICATION_LOST | SUCCESS | One or more listeners did not receive this notification, but at least one listener did receive this notification. |

The return values are COM error codes. Because this function might complete the operation successfully yet return an HRESULT other than S_OK you should use the SUCCEEDED or FAILED macro to determine the success of the call. To get the specific HRESULT that was returned by the function, use the HRESULT_CODE macro. The following code example shows how these macros can be used.

See [PrintAsyncNotifyError](https://learn.microsoft.com/windows/desktop/api/prnasnot/ne-prnasnot-printasyncnotifyerror) for other possible return values.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

```cpp
if (SUCCEEDED(hr)) {
  // Call succeeded, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case S_OK:
      // Some action
      break;
    case NO_LISTENERS:
      // Some action
      break;
    case UNIRECTIONAL_NOTIFICATION_LOST:
      // Some action
      break;
    default:
      // Default action
      break;
  }
} else {
  // Call failed, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case ASYNC_NOTIFICATION_FAILURE:
      // Some action
      break;
    case CHANNEL_ALREADY_CLOSED:
      // Some action
      break;
    case CHANNEL_NOT_OPENED:
      // Some action
      break;
    //
    // ... Test for other error cases
    //
    default:
      // Default action
      break;
  }
}

```

## Remarks

For a unidirectional channel, if a **SendNotification** call is made while the print spooler is processing an earlier **SendNotification** call, the print spooler queues the pending notification. Queued notifications are discarded if either the component that is hosted by the print spooler or the application calls [IPrintAsyncNotifyChannel::CloseChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifychannel-closechannel).

For a bidirectional channel, if a **SendNotification** call is made while the Print-Spooler is processing an earlier **SendNotification** call, then the pending call will fail. In that case, if the caller is a sender inside print spooler, **SendNotification** returns CHANNEL_WAITING_FOR_CLIENT_NOTIFICATION. If the caller is a listener sending a reply, then **SendNotification** returns ASYNC_CALL_IN_PROGRESS.

When multiple listeners exist for the same bidirectional channel, the initial notification sent on the channel will be delivered to all listeners. The first listener to reply will acquire the channel. Listeners calling **SendNotification** after the channel was acquired will fail with error CHANNEL_ACQUIRED.

A listener receiving an initial notification on a bidirectional channel might not be interested in acquiring the channel. In this case the listener can call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method can be called. The **IUnknown::Release** method does not need to be called if **SendNotification** or [IPrintAsyncNotifyChannel::CloseChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifychannel-closechannel) methods are called.

## See also

[Asynchronous Printing Notification Interfaces](https://learn.microsoft.com/windows/desktop/printdocs/asynchronous-notification-interfaces)

[IPrintAsyncNotifyChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifychannel)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)