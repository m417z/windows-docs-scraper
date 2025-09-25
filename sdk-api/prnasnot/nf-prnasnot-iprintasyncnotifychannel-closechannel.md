# IPrintAsyncNotifyChannel::CloseChannel

## Description

Closes the channel.

## Parameters

### `pData` [in]

Pointer to a notification that specifies why the channel closed. This pointer can be **NULL**.

## Return value

| HRESULT | Severity | Meaning |
| --- | --- | --- |
| S_OK | SUCCESS | The function completed successfully. |
| CHANNEL_ACQUIRED | ERROR<br><br>or<br><br>SUCCESS | Another listener on this channel has already responded. Only the first respondent can continue the communication with the sender.<br><br> If this HRESULT has an ERROR severity, the calling function should handle the error condition. |
| CHANNEL_ALREADY_CLOSED | ERROR<br><br>or<br><br>SUCCESS | The channel has already closed. IPrintAsyncNotifyChannel::Release must not be called if this HRESULT is returned because the channel has already been closed and released.<br><br> If this HRESULT has an ERROR severity, the calling function should handle the error condition. |
| CHANNEL_CLOSED_BY_ANOTHER_LISTENER | ERROR | A listening application, other than the caller, closed the communication channel. |
| CHANNEL_CLOSED_BY_SAME_LISTENER | ERROR | The caller has already closed the communication channel. |
| INVALID_NOTIFICATION_TYPE | ERROR | The specified notification type is invalid. |

The return values are COM error codes. Because this function might complete the operation successfully yet return an HRESULT other than S_OK you should use the SUCCEEDED or FAILED macro to determine the success of the call. To get the specific HRESULT that was returned by the function, use the HRESULT_CODE macro. The following code example shows how these macros can be used.

See [PrintAsyncNotifyError](https://learn.microsoft.com/windows/desktop/api/prnasnot/ne-prnasnot-printasyncnotifyerror) for other possible return values.

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

```cpp
if (SUCCEEDED(hr)) {
  // Call succeeded, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case CHANNEL_ACQUIRED:
      // Some action
      break;
    case CHANNEL_ALREADY_CLOSED:
      // Some action
      break;
    default:
      // Default action
      break;
  }
} else {
  // Call failed, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case CHANNEL_CLOSED_BY_ANOTHER_LISTENER:
      // Some action
      break;
    case CHANNEL_CLOSED_BY_SAME_LISTENER:
      // Some action
      break;
    case INVALID_NOTIFICATION_TYPE:
      // Some action
      break;
    case CHANNEL_ACQUIRED:
      // This can be an error and a successful return
      //  some action
      break;
    case CHANNEL_ALREADY_CLOSED:
      // This can be an error and a successful return
      //  some action
      break;
    default:
      // Default action
      break;
  }
}

```

## Remarks

**CloseChannel** can be called by either side of the communication channel—the component that is hosted by the print spooler or the listening application.

If an [IPrintAsyncNotifyChannel::SendNotification](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifychannel-sendnotification) call is made while the print spooler is processing an earlier call to **SendNotification**, the print spooler will queue the notifications. Queued notifications are discarded if either the component that is hosted by the print spooler or the application calls **CloseChannel**.

**CloseChannel** cannot be called immediately after the call to [CreatePrintAsyncNotifyChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-createprintasyncnotifychannel).

## See also

[Asynchronous Printing Notification Interfaces](https://learn.microsoft.com/windows/desktop/printdocs/asynchronous-notification-interfaces)

[IPrintAsyncNotifyChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifychannel)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)