# IPrintAsyncNotifyCallback::OnEventNotify

## Description

Alerts a listener that a notification is available on a specified channel. This method is called by the print system.

## Parameters

### `pChannel` [in]

A pointer to the channel used by the sender and the listener.

### `pData` [in]

A pointer to the object that contains the notification data and its size and type.

## Return value

| HRESULT | Severity | Meaning |
| --- | --- | --- |
| S_OK | SUCCESS | The function completed successfully. |
| INTERNAL_NOTIFICATION_QUEUE_IS_FULL | ERROR | The Print Spooler cannot hold any more queued notifications. By default, the maximum size of the queue is 10 notifications. When this error is returned, the listening application is not processing the notifications as fast as they are being sent. This notification should either be resent or discarded. |

The return values are COM error codes. Because this function might complete the operation successfully yet return an HRESULT other than S_OK you should use the SUCCEEDED or FAILED macro to determine the success of the call. To get the specific HRESULT that was returned by the function, use the HRESULT_CODE macro.

See [PrintAsyncNotifyError](https://learn.microsoft.com/windows/desktop/api/prnasnot/ne-prnasnot-printasyncnotifyerror) for other possible return values.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

The following code example shows how these macros can be used to evaluate the return value.

```cpp
if (SUCCEEDED(hr)){
  // Call was successful
}

if (FAILED(hr)) {
  // Call failed
}

if (FAILED(hr)) {
  // Call failed, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case INTERNAL_NOTIFICATION_QUEUE_IS_FULL:
      // Some action
      break;
    default:
      // Default action
      break;
  }
} else {
  // Call succeeded
}

```

## Remarks

To deliver a notification, the print spooler will call the **OnEventNotify** method of the [IPrintAsyncNotifyCallback](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifycallback) object provided by the listening application at the time it registered for notifications. For unidirectional notifications, *pChannel* is **NULL**. For bidirectional channels, *pChannel* points to an [IPrintAsyncNotifyChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifychannel) to be used by a listening application to send a notification in response. The listener will do this by calling the [SendNotification](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifychannel-sendnotification) method of the **IPrintAsyncNotifyChannel**.

## See also

[Asynchronous Printing Notification Interfaces](https://learn.microsoft.com/windows/desktop/printdocs/asynchronous-notification-interfaces)

[Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling)

[IPrintAsyncNotifyCallback](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifycallback)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)