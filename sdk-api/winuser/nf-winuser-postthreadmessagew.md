# PostThreadMessageW function

## Description

Posts a message to the message queue of the specified thread. It returns without waiting for the thread to process the message.

## Parameters

### `idThread` [in]

Type: **DWORD**

The identifier of the thread to which the message is to be posted.

The function fails if the specified thread does not have a message queue. The system creates a thread's message queue when the thread makes its first call to one of the User or GDI functions. For more information, see the Remarks section.

Message posting is subject to UIPI. The thread of a process can post messages only to posted-message queues of threads in processes of lesser or equal integrity level.

 This thread must have the **SE_TCB_NAME** privilege to post a message to a thread that belongs to a process with the same locally unique identifier (LUID) but is in a different desktop. Otherwise, the function fails and returns **ERROR_INVALID_THREAD_ID**.

 This thread must either belong to the same desktop as the calling thread or to a process with the same LUID. Otherwise, the function fails and returns **ERROR_INVALID_THREAD_ID**.

### `Msg` [in]

Type: **UINT**

The type of message to be posted.

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** returns **ERROR_INVALID_THREAD_ID** if *idThread* is not a valid thread identifier, or if the thread specified by *idThread* does not have a message queue. **GetLastError** returns **ERROR_NOT_ENOUGH_QUOTA** when the message limit is hit.

## Remarks

 When a message is blocked by UIPI the last error, retrieved with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), is set to 5 (access denied).

The thread to which the message is posted must have created a message queue, or else the call to **PostThreadMessage** fails. Use the following method to handle this situation.

* Create an event object, then create the thread.
* Use the [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject) function to wait for the event to be set to the signaled state before calling **PostThreadMessage**.
* In the thread to which the message will be posted, call [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) as shown here to force the system to create the message queue.

  `PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE)`
* Set the event, to indicate that the thread is ready to receive posted messages.

The thread to which the message is posted retrieves the message by calling the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function. The **hwnd** member of the returned [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure is **NULL**.

Messages posted by **PostThreadMessage** are not associated with a window. As a general rule, messages that are not associated with a window cannot be dispatched by the [DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage) function. Therefore, if the recipient thread is in a modal loop (as used by [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) or [DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa)), the messages will be lost. To intercept thread messages while in a modal loop, use a thread-specific hook.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

 There is a limit of 10,000 posted messages per message queue. This limit should be sufficiently large. If your application exceeds the limit, it should be redesigned to avoid consuming so many system resources. To adjust this limit, modify the following registry key.

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows NT
            CurrentVersion
               Windows
                  USERPostMessageLimit
```

The minimum acceptable value is 4000.

> [!NOTE]
> The winuser.h header defines PostThreadMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[GetWindowThreadProcessId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowthreadprocessid)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

**Other Resources**

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**

[Sleep](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-sleep)

[WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject)