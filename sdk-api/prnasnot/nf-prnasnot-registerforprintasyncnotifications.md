# RegisterForPrintAsyncNotifications function

## Description

Enables an application to register for notifications from Print Spooler-hosted printing components such as printer drivers, print processors, and port monitors.

## Parameters

### `pszName` [in]

A pointer to the name of a print server or print queue.

### `pNotificationType` [in]

A pointer to the GUID of the data schema for the type of notifications that the application must receive.

### `eUserFilter` [in]

A value specifying whether notifications will be sent to:

* Only applications that are running as the same user as the Print Spooler-hosted plug-in sender.
* A broader set of listening applications.

### `eConversationStyle` [in]

A value specifying whether communication is bidirectional or unidirectional.

### `pCallback` [in]

A pointer to an object that the Print Spooler-hosted component will use to call back the application. This should never be **NULL**.

### `phNotify` [out]

A pointer to a structure that represents the registration.

## Return value

| HRESULT | Severity | Meaning |
| --- | --- | --- |
| S_OK | SUCCESS | The function completed successfully. |
| ALREADY_REGISTERED | ERROR | The registration object has already been registered. |
| LOCAL_ONLY_REGISTRATION | SUCCESS | Registration for local notification was successful. Registration for remote notifications was not. |
| MAX_REGISTRATION_COUNT_EXCEEDED | ERROR | The maximum number of registrations has been reached. No more registrations are permitted. |
| REMOTE_ONLY_REGISTRATION | SUCCESS | Registration for remote notifications was successful. Registration for local notifications was not. |

The return values are COM error codes. Because this function might complete the operation successfully yet return an HRESULT other than S_OK you should use the SUCCEEDED or FAILED macro to determine the success of the call. To get the specific HRESULT that was returned by the function, use the HRESULT_CODE macro.

The following code example shows how these macros can be used to evaluate the return value.

```cpp
if (SUCCEEDED(hr)) {
  // Call succeeded, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case S_OK:
      // Some action
      break;
      case LOCAL_ONLY_REGISTRATION:
      // Some action
      break;
    case REMOTE_ONLY_REGISTRATION:
      // Some action
      break;
    default:
      // Default action
      break;
  }
} else {
  // Call failed, check HRESULT value returned
  switch (HRESULT_CODE(hr)){
    case ALREADY_REGISTERED:
      // Some action
      break;
    case MAX_REGISTRATION_COUNT_EXCEEDED:
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

To stop notifications through a unidirectional channel, the listening application passes the *pRegistrationHandler* value returned by **RegisterForPrintAsyncNotifications** to [UnRegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-unregisterforprintasyncnotifications). For a bidirectional channel, call **UnRegisterForPrintAsyncNotifications** to block notifications in any new channels that were created after that call. To block notifications on existing bidirectional channels, the listening application must close the channel with [IPrintAsyncNotifyChannel::CloseChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-iprintasyncnotifychannel-closechannel).

As a result of a **RegisterForPrintAsyncNotifications** call, the [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method is called for the *pCallback* object. Calling [UnRegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-unregisterforprintasyncnotifications) will release the *pCallback* object. The reference count of *pCallback* object will be also incremented when a channel is created and decremented when the channel is closed.

The *pSchema* parameter is a GUID pointer that the spooler accepts and uses to filter the listener clients. Any client of the spooler asynchronous notification mechanism can define its own notification type. Even though the spooler is unaware of the notification type that is sent, it still filters the listener clients based on the notification type. The notification schema that *pSchema* references is the schema that is used by the notification object that exposes [IPrintAsyncNotifyDataObject](https://learn.microsoft.com/windows/desktop/api/prnasnot/nn-prnasnot-iprintasyncnotifydataobject). Clients of the spooler notification pipe can define their own data schema and can send any data type back and forth and the GUID referenced by *pSchema* is unique to that data schema.

## See also

[Client Impersonation](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-impersonation)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)