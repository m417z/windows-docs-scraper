# UnRegisterForPrintAsyncNotifications function

## Description

Enables an application that has registered to receive notifications from Print Spooler-hosted printing components to unregister.

## Parameters

### `unnamedParam1` [in]

The registration handle to be unregistered.

## Return value

| HRESULT | Severity | Meaning |
| --- | --- | --- |
| S_OK | SUCCESS | The function completed successfully. |
| ALREADY_UNREGISTERED | SUCCESS<br><br>ERROR | The registration handler has already been unregistered. If this HRESULT has an ERROR severity, the calling function should handle the error condition. |
| NOT_REGISTERED | SUCCESS | The registration handler was not registered. |

The return values are COM error codes. Because this function might complete the operation successfully yet return an **HRESULT** other than S_OK you should use the SUCCEEDED or FAILED macro to determine the success of the call. To get the specific **HRESULT** that was returned by the function, use the HRESULT_CODE macro.

The following code example shows how these macros can be used to evaluate the return value.

```cpp
if (SUCCEEDED(hr)) {
  // Call succeeded, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case S_OK:
      // Some action
      break;
    case NOT_REGISTERED:
      // Some action
      break;
    case ALREADY_UNREGISTERED:
      // Some action
      break;
    default:
      // Default action
      break;
  }
} else {
  // Call failed, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    // This can be error and a successful return
    case ALREADY_UNREGISTERED:
      // Some action
      break;
    default:
      // Default action
      break;
  }
}

```

For more information about COM error codes, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

See [PrintAsyncNotifyError](https://learn.microsoft.com/windows/desktop/api/prnasnot/ne-prnasnot-printasyncnotifyerror) for other possible return values.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

A call to [RegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-registerforprintasyncnotifications) must return *hRegistrationHandler*.

If the channel is bidirectional, a call to **UnRegisterForPrintAsyncNotifications** only prevents notifications from communication channels created after that point. To end notifications from the existing channel, the listening application must close the channel with [IPrintAsyncNotifyChannel::CloseChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifychannel-closechannel).

A call to **UnRegisterForPrintAsyncNotifications** will decrement the reference count of the *pCallback* object passed to [RegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-registerforprintasyncnotifications).

After this function succeeds, *hRegistrationHandler* is invalid and must not be used again.

## See also

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)