# phoneInitializeExW function

## Description

The
**phoneInitializeEx** function initializes the application's use of TAPI for subsequent use of the phone abstraction. It registers the application's specified notification mechanism and returns the number of phone devices available to the application. A phone device is any device that provides an implementation for the phone-prefixed functions in the Telephony API.

## Parameters

### `lphPhoneApp`

Pointer to a location that is filled with the application's usage handle for TAPI.

### `hInstance`

Instance handle of the client application or DLL. The application or DLL can pass **NULL** for this parameter, in which case TAPI uses the module handle of the root executable of the process.

### `lpfnCallback`

Address of a callback function that is invoked to determine status and events on the line device, addresses, or calls, when the application is using the "hidden window" method of event notification (for more information see
[phoneCallbackFunc](https://learn.microsoft.com/windows/desktop/api/tapi/nc-tapi-phonecallback)). This parameter is ignored and should be set to **NULL** when the application chooses to use the "event handle" or "completion port" event notification mechanisms.

### `lpszFriendlyAppName`

Pointer to a **null**-terminated string that contains only displayable characters. If this parameter is not **NULL**, it contains an application-supplied name for the application. This name is provided in the
[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus) structure to indicate, in a user-friendly way, which application has ownership of the phone device. If *lpszFriendlyAppName* is **NULL**, the application's module filename is used instead (as returned by the function
[GetModuleFileName](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulefilenamea)).

### `lpdwNumDevs`

Pointer to a **DWORD**. Upon successful completion of this request, this location is filled with the number of phone devices available to the application.

### `lpdwAPIVersion`

Pointer to a **DWORD**. The application must initialize this **DWORD**, before calling this function, to the highest API version it is designed to support (for example, the same value it would pass into *dwAPIHighVersion* parameter of
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)). Artificially high values must not be used; the value must be accurately set. TAPI translates any newer messages or structures into values or formats supported by the application's version. Upon successful completion of this request, this location is filled with the highest API version supported by TAPI, thereby allowing the application to detect and adapt to having been installed on a system with an older version of TAPI.

### `lpPhoneInitializeExParams`

Pointer to a structure of type
[PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams) containing additional parameters used to establish the association between the application and TAPI (specifically, the application's selected event notification mechanism and associated parameters).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPNAME, PHONEERR_OPERATIONFAILED, PHONEERR_INIFILECORRUPT, PHONEERR_INVALPOINTER, PHONEERR_REINIT, PHONEERR_NOMEM, PHONEERR_INVALPARAM.

## Remarks

Applications must select one of three mechanisms by which TAPI notifies the application of telephony events: Hidden Window, Event Handle, or Completion Port.

* The **Hidden Window** mechanism is selected by specifying PHONEINITIALIZEEXOPTION_USEHIDDENWINDOW in the **dwOptions** member in the
  [PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams) structure. In this mechanism (which is the only mechanism available to TAPI version 1.*x* applications), TAPI creates a window in the context of the application during the
  **phoneInitializeEx** function, and subclasses the window so that all messages posted to it are handled by a WNDPROC in TAPI itself. When TAPI has a message to deliver to the application, TAPI posts a message to the hidden window. When the message is received (which can happen only when the application calls the Windows
  [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) function), Windows switches the process context to that of the application and invokes the WNDPROC in TAPI. TAPI then delivers the message to the application by calling the
  [phoneCallbackFunc](https://learn.microsoft.com/windows/desktop/api/tapi/nc-tapi-phonecallback), a pointer to which the application provided as a parameter in its call to
  **phoneInitializeEx** (or
  [phoneInitialize](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitialize), for TAPI version 1.3 and 1.4 applications). This mechanism requires the application to have a message queue (which is not desirable for service processes) and to service that queue regularly to avoid delaying processing of telephony events. The hidden window is destroyed by TAPI during the
  [phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown) function.
* The **Event Handle** mechanism is selected by specifying PHONEINITIALIZEEXOPTION_USEEVENT in the **dwOptions** member in the
  [PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams) structure. In this mechanism, TAPI creates an event object on behalf of the application, and returns a handle to the object in the **hEvent** member in
  [PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams). The application must not manipulate this event in any manner (for example, must not call
  [SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent),
  [ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent),
  [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle), and so on) or undefined behavior results; the application can only wait on this event using functions such as
  [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) or
  [MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects). TAPI signals this event whenever a telephony event notification is pending for the application; the application must call
  [phoneGetMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetmessage) to fetch the contents of the message. The event is reset by TAPI when no events are pending. The event handle is closed and the event object destroyed by TAPI during the
  [phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown) function. The application is not required to wait on the event handle that is created; the application could choose instead to call
  **phoneGetMessage** and have it block waiting for a message to be queued.
* The **Completion Port** mechanism is selected by specifying PHONEINITIALIZEEXOPTION_USECOMPLETION PORT in the **dwOptions** member in the
  [PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams) structure. In this mechanism, whenever a telephony event needs to be sent to the application, TAPI sends it to the application using
  [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) to the completion port that the application specified in the **hCompletionPort** member in
  [PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams), tagged with the completion key that the application specified in the **dwCompletionKey** member in
  [PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams). The application must have previously created the completion port using
  [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport). The applications retrieves events using
  [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus). Upon return from **GetQueuedCompletionStatus**, the application has the specified **dwCompletionKey** written to the **DWORD** pointed to by the *lpCompletionKey* parameter, and a pointer to a
  [PHONEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonemessage) structure returned to the location pointed to by *lpOverlapped*. After the application has processed the event, the application must call
  [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) to release the memory used to contain the
  **PHONEMESSAGE** structure. Because the application created the completion port (thereby allowing it to be shared for other purposes), the application must close it; the application must not close the completion port until after calling
  [phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown).

When a multithreaded application is using the Event Handle mechanism and more than one thread is waiting on the handle, or the Completion Port notification mechanism and more than one thread is waiting on the port, it is possible for telephony events to be processed out of sequence. This is not due to the sequence of delivery of events from TAPI, but would be caused by the time slicing of threads or the execution of threads on separate processors.

If PHONEERR_REINIT is returned and TAPI reinitialization has been requested (for example, as a result of adding or removing a telephony service provider), then
**phoneInitializeEx** requests are rejected with this error until the last application shuts down its usage of the API (using
[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown)). At that time, the new configuration becomes effective and applications are once again permitted to call
**phoneInitializeEx**.

If the PHONEERR_INVALPARAM error value is returned, the specified *hInstance* parameter is invalid.

The application can refer to individual phone devices by using phone device identifiers that range from zero to *dwNumDevs* minus one. An application should not assume that these phone devices are capable of any particular TAPI function without first querying their device capabilities by
[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps).

> [!NOTE]
> The tapi.h header defines phoneInitializeEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PHONEINITIALIZEEXPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneinitializeexparams)

[PHONEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonemessage)

[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneCallbackFunc](https://learn.microsoft.com/windows/desktop/api/tapi/nc-tapi-phonecallback)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)

[phoneGetMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetmessage)

[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)

[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown)