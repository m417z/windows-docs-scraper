# IPrintAsyncNotifyCallback::ChannelClosed

## Description

Advises one member of a communication channel to notify the other member that the channel is being closed.

## Parameters

### `pChannel` [in]

A pointer to the channel used by the sender and the listener.

### `pData` [in]

A pointer to the object that contains the notification data or response.

## Return value

| HRESULT | Severity | Meaning |
| --- | --- | --- |
| S_OK | SUCCESS | This function completed successfully. |
| CHANNEL_ALREADY_CLOSED | ERROR | The channel has already been closed. |

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
    case CHANNEL_ALREADY_CLOSED:
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

When a component that is hosted by the print spooler closes a communication channel with a listening application, the component should call the **ChannelClosed** method of the [IPrintAsyncNotifyCallback](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifycallback) object, which the listening application provided at the time it registered for notifications. If the print server crashes, the print spooler will attempt to call the [OnEventNotify](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifycallback-oneventnotify) method of the **IPrintAsyncNotifyCallback** object provided by the listening application. It will send a notification of type NOTIFICATION_RELEASE.

If the listening application closes a bidirectional communication channel, it should call the **ChannelClosed** method of the [IPrintAsyncNotifyCallback](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifycallback) object provided by the component when it created the channel. If the listening application crashes, the print spooler will call the [OnEventNotify](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifycallback-oneventnotify) method of the **IPrintAsyncNotifyCallback** object provided by the component that is hosted by the print spooler. It will send a notification of type NOTIFICATION_RELEASE.

## See also

[Asynchronous Printing Notification Interfaces](https://learn.microsoft.com/windows/desktop/printdocs/asynchronous-notification-interfaces)

[Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling)

[IPrintAsyncNotifyCallback](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifycallback)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)