# PFAXINITIALIZEEVENTQUEUE callback function

## Description

The **FaxInitializeEventQueue** function creates a fax event queue for the calling fax client application. The queue enables the application to receive notifications of asynchronous events from the fax server.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `CompletionPort` [in]

Type: **HANDLE**

Specifies a valid handle to an I/O completion port returned by a call to the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. This parameter is required for notification using I/O completion packets. This parameter must be **NULL** if you specify notification messages.

For information about I/O completion ports, see [I/O Completion Ports](https://learn.microsoft.com/windows/desktop/FileIO/i-o-completion-ports).

### `CompletionKey` [in]

Type: **ULONG_PTR**

Specifies a variable that contains a completion key value the fax server includes in each I/O completion packet. This parameter is required for notification using I/O completion packets. This parameter must be **NULL** if you specify notification messages. For more information, see the following Remarks section.

### `hWnd` [in]

Type: **HWND**

Handle to a window of the fax client application to notify when an asynchronous event occurs. This parameter is required for notification messages. This parameter must be **NULL** if you specify notification using I/O completion packets.

### `MessageStart` [in]

Type: **UINT**

Specifies an unsigned integer that identifies the application's base window message. The application can use this number to determine whether to process the message as a fax server event. For more information, see the [FAX_EVENT](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_eventa) topic.

This parameter is required for notification messages. This parameter must be equal to zero if you specify notification using I/O completion packets.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Both the *hWnd* and *CompletionPort* parameters are **NULL**, or both parameters are specified. |
| **ERROR_INVALID_PARAMETER** | The *FaxHandle* parameter is **NULL**; or the *hWnd* parameter is specified but the *FaxHandle* parameter does not specify a connection with a local fax server; or the *MessageStart* parameter specifies a message in the range below [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user). |
| **ERROR_INVALID_DATA** | The application called the [FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue) function more than once during a fax service session in Windows 2000. More than one call is supported in Windows XP and Windows Server 2003. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

An application can specify how the fax server should inform the client application of events. The application can request that the fax server queue I/O completion packets to an I/O completion port, or it can specify notification messages.

A fax client application must call the **FaxInitializeEventQueue** function before calling [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) to retrieve the value to specify in the *CompletionKey* parameter. This value is useful to a message loop that retrieves I/O completion packets from multiple I/O completion ports, using calls to the [WaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects) function. If you specify a different completion key for each I/O completion port, you can identify the completion port associated with the completion packet.

An application can call the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function to retrieve the queued I/O completion packet for a completed I/O operation. A call to GetQueuedCompletionStatus also returns a pointer to a variable that the function sets to the address of a [FAX_EVENT](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_eventa) structure. The structure is associated with the I/O completion packet of interest. Call the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the memory allocated for the **FAX_EVENT** structure.

After a fax client application receives the **FEI_FAXSVC_ENDED** message, it will no longer receive fax events from the fax service. To resume receiving fax events, the application must call the **FaxInitializeEventQueue** function again when the fax service restarts. The application can determine if the fax service is running by using the service control manager. For more information, see [FaxClose](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxclose) and [Enabling an Application to Receive Notifications of Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-enabling-an-application-to-receive-notifications-of-fax-events).

For a list of the asynchronous events that can occur within the fax server, see the [FAX_EVENT](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_eventa) topic.

## See also

[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport)

[FAX_EVENT](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_eventa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxClose](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxclose)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[WaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects)