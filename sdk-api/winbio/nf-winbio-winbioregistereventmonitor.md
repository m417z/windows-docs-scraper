# WinBioRegisterEventMonitor function

## Description

The **WinBioRegisterEventMonitor** function Registers a callback function to receive event notifications from the service provider associated with an open session.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies the open biometric session. Open the session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession).

### `EventMask` [in]

A value that specifies the types of events to monitor. Only the fingerprint provider is currently supported. You must specify one of the following flags.

* **WINBIO_EVENT_FP_UNCLAIMED**

The sensor detected a finger swipe that was not requested by the application, or the requesting application does not have window focus. The Windows Biometric Framework calls into your callback function to indicate that a finger swipe has occurred but does not try to identify the fingerprint.

* **WINBIO_EVENT_FP_UNCLAIMED_IDENTIFY**

The sensor detected a finger swipe that was not requested by the application, or the requesting application does not have window focus. The Windows Biometric Framework attempts to identify the fingerprint and passes the result of that process to your callback function.

### `EventCallback` [in]

Address of a callback function that receives the event notifications sent by the Windows Biometric Framework. You must define this function.

### `EventCallbackContext` [in]

An optional application-defined value that is returned in the *pvContext* parameter of the callback function. This value can contain any data that the custom callback function is designed to handle.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| ****E_HANDLE**** | The session handle is not valid. |
| ****E_POINTER**** | The address of the callback function specified by the *EventCallback* parameter cannot be **NULL**. |
| ****E_INVALIDARG**** | The *EventMask* parameter cannot be zero and you cannot specify both **WINBIO_EVENT_FP_UNCLAIMED** and **WINBIO_EVENT_FP_UNCLAIMED_IDENTIFY** at the same time. |
| ****WINBIO_E_EVENT_MONITOR_ACTIVE**** | An active event monitor has already been registered. |
| ****WINBIO_E_INVALID_OPERATION**** | The service provider does not support event notification. |

## Remarks

This function is only valid for sessions connected to a System sensor pool.

Event callbacks are delivered to the client application serially. Therefore, subsequent event notifications will not be delivered until the client returns from the current callback. Events that occur while a callback is still executing may be discarded by the system. To avoid losing events, you should not perform any time-consuming work in your callback routine.

The client application should be prepared to receive events as soon as **WinBioRegisterEventMonitor** is called. The application must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the structure returned in the *Event* argument of the callback. Failure to do so will result in a memory leak in the calling process.

After an event monitor has been started, the session with which the monitor is associated will not be able to process other Windows Biometric Framework API calls until the event monitor has been stopped. If your application needs to perform other API calls while still receiving event monitor notifications, you should open two sessions - one for the event monitor and another for other operations.

Call [WinBioUnregisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiounregistereventmonitor) to stop sending event notifications to your callback function.

If an application registers a **WinBio** event monitor and leaves that monitor active during a sleep/wake cycle, systems that implement biometric pre-boot authentication (PBA)/single sign-on features may not always work. The problem is that the PBA biometric call is intercepted by the event monitor before the system's biometric credential provider has a chance to perform its first [WinBioIdentify](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioidentify) operation. Apps that use the **WinBio** event monitoring feature should unregister their monitors before the system sleeps, and re-register them after system wakeup. For more information on handling events during power state changes, see [About Power Management](https://learn.microsoft.com/windows/desktop/Power/about-power-management).

The callback routine must have the following signature:

```cpp

VOID CALLBACK EventCallback(
__in_opt PVOID EventCallbackContext,
__in HRESULT OperationStatus,
__in PWINBIO_EVENT Event
);
```

#### Examples

The following function registers an event monitor by calling the
**WinBioRegisterEventMonitor** function and passing the address
of a callback routine. The callback, also included, receives event notifications
from the Windows biometric framework. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT RegisterSystemEventMonitor(BOOL bCancel)
{
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    WINBIO_UNIT_ID unitId = 0;

    // Connect to the system pool.
    hr = WinBioOpenSession(
            WINBIO_TYPE_FINGERPRINT,    // Service provider
            WINBIO_POOL_SYSTEM,         // Pool type
            WINBIO_FLAG_DEFAULT,        // Configuration and access
            NULL,                       // Array of biometric unit IDs
            0,                          // Count of biometric unit IDs
            NULL,                       // Database ID
            &sessionHandle              // [out] Session handle
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioOpenSession failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Call the WinBioRegisterEventMonitor function.
    wprintf_s(L"\n Calling WinBioRegisterEventMonitor.\n");
    hr = WinBioRegisterEventMonitor(
            sessionHandle,              // Open session handle
            WINBIO_EVENT_FP_UNCLAIMED,  // Events to monitor
            EventMonitorCallback,       // Callback function
            NULL                        // Optional context.
            );
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioRegisterEventMonitor failed.");
        wprintf_s(L"hr = 0x%x\n", hr);
        goto e_Exit;
    }
    wprintf_s(L"\n Waiting for an event.\n");

    // Cancel the identification if the bCancel flag is set.
    if (bCancel)
    {
        wprintf_s(L"\n Starting CANCEL timer...\n");
        Sleep( 7000 );

        wprintf_s(L"\n Calling WinBioCancel\n");
        hr = WinBioCancel( sessionHandle );
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioCancel failed. hr = 0x%x\n", hr);
            goto e_Exit;
        }
    }

    // Wait for an event to happen.
    //wprintf_s(L"\n Swipe the sensor to receive an event notice ");
    //wprintf_s(L"\n or press any key to stop waiting...\n");
    wprintf_s(L"\n Swipe the sensor one or more times ");
    wprintf_s(L"to generate events.");
    wprintf_s(L"\n When done, press a key to exit...\n");
    _getch();

    // Unregister the event monitor.
    wprintf_s(L"\n Calling WinBioUnregisterEventMonitor\n");
    hr = WinBioUnregisterEventMonitor( sessionHandle);
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioUnregisterEventMonitor failed.");
        wprintf_s(L"hr = 0x%x\n", hr);
    }

e_Exit:

    if (sessionHandle != NULL)
    {
       wprintf_s(L"\n Closing the session.\n");

        hr = WinBioCloseSession(sessionHandle);
        if (FAILED(hr))
        {
            wprintf_s(L"\n WinBioCloseSession failed. hr = 0x%x\n", hr);
        }
        sessionHandle = NULL;
    }

    wprintf_s(L"\n Press any key to exit...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function is the callback for WinBioRegisterEventMonitor.
// The function filters any event notice from the biometric subsystem and
// writes a result to the console window.
//
VOID CALLBACK EventMonitorCallback(
    __in_opt PVOID EventCallbackContext,
    __in HRESULT OperationStatus,
    __in PWINBIO_EVENT Event
    )
{
    UNREFERENCED_PARAMETER(EventCallbackContext);

    wprintf_s(L"\n EventMonitorCallback executing.");

    // Failure.
    if (FAILED(OperationStatus))
    {
        wprintf_s(L"\n EventMonitorCallback failed. ");
        wprintf_s(L" OperationStatus = 0x%x\n", OperationStatus);
        goto e_Exit;
    }

    // An event notice was received.
    if (Event != NULL)
    {
        wprintf_s(L"\n MonitorEvent: ");
        switch (Event->Type)
        {
            case WINBIO_EVENT_FP_UNCLAIMED:
                wprintf_s(L"WINBIO_EVENT_FP_UNCLAIMED");
                wprintf_s(L"\n Unit ID: %d",
                          Event->Parameters.Unclaimed.UnitId);
                wprintf_s(L"\n Reject detail: %d\n",
                          Event->Parameters.Unclaimed.RejectDetail);
                break;

            case WINBIO_EVENT_FP_UNCLAIMED_IDENTIFY:
                wprintf_s(L"WINBIO_EVENT_FP_UNCLAIMED_IDENTIFY");
                wprintf_s(L"\n Unit ID: %d",
                          Event->Parameters.UnclaimedIdentify.UnitId);
                wprintf_s(L"\n Reject detail: %d\n",
                          Event->Parameters.UnclaimedIdentify.RejectDetail);
                break;

            case WINBIO_EVENT_ERROR:
                wprintf_s(L"WINBIO_EVENT_ERROR\n");
                break;

            default:
                wprintf_s(L"(0x%08x - Invalid type)\n", Event->Type);
                break;
        }
    }

e_Exit:

    if (Event != NULL)
    {
        //wprintf_s(L"\n Press any key to continue...\n");
        WinBioFree(Event);
        Event = NULL;
    }
}

```

## See also

[WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession)

[WinBioUnregisterEventMonitor](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiounregistereventmonitor)