# PostMessageW function

## Description

Places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message.

To post a message in the message queue associated with a thread, use the [PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea) function.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window whose window procedure is to receive the message. The following values have special meanings.

| Value | Meaning |
| --- | --- |
| **HWND_BROADCAST**<br><br>((HWND)0xffff) | The message is posted to all top-level windows in the system, including disabled or invisible unowned windows, overlapped windows, and pop-up windows. The message is not posted to child windows. |
| NULL | The function behaves like a call to [PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea) with the *dwThreadId* parameter set to the identifier of the current thread. |

Starting with Windows Vista, message posting is subject to UIPI. The thread of a process can post messages only to message queues of threads in processes of lesser or equal integrity level.

### `Msg` [in]

Type: **UINT**

The message to be posted.

For lists of the system-provided messages, see [System-Defined Messages](https://learn.microsoft.com/windows/desktop/winmsg/about-messages-and-message-queues).

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

 When a message is blocked by UIPI the last error, retrieved with [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), is set to 5 (access denied).

Messages in a message queue are retrieved by calls to the [GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) function.

Applications that need to communicate using **HWND_BROADCAST** should use the [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) function to obtain a unique message for inter-application communication.

The system only does marshalling for system messages (those in the range 0 to ([WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user)-1)). To send other messages (those >= **WM_USER**) to another process, you must do custom marshalling.

If you send a message in the range below [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user) to the asynchronous message functions (**PostMessage**, [SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea), and [SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)), its message parameters cannot include pointers. Otherwise, the operation will fail. The functions will return before the receiving thread has had a chance to process the message and the sender will free the memory before it is used.

Do not post the [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message using **PostMessage**; use the [PostQuitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postquitmessage) function.

 An accessibility application can use **PostMessage** to post [WM_APPCOMMAND](https://learn.microsoft.com/windows/desktop/inputdev/wm-appcommand) messages to the shell to launch applications. This functionality is not guaranteed to work for other types of applications.

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

If the function fails, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information. **GetLastError** returns **ERROR_NOT_ENOUGH_QUOTA** when the limit is hit.

The minimum acceptable value is 4000.

#### Examples

The following example shows how to post a private window message using the **PostMessage** function. Assume you defined a private window message called **WM_COMPLETE**:

```cpp
#define        WM_COMPLETE     (WM_USER + 0)

```

You can post a message to the message queue associated with the thread that created the specified window as shown below:

```cpp
 WaitForSingleObject (pparams->hEvent, INFINITE) ;
 lTime = GetCurrentTime () ;
 PostMessage (pparams->hwnd, WM_COMPLETE, 0, lTime);

```

For more examples, see [Initiating a Data Link](https://learn.microsoft.com/windows/desktop/dataxchg/using-dynamic-data-exchange).

> [!NOTE]
> The winuser.h header defines PostMessage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

[Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/messages-and-message-queues)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[PostQuitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postquitmessage)

[PostThreadMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postthreadmessagea)

**Reference**

[RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)

[SendMessageCallback](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessagecallbacka)

[SendNotifyMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendnotifymessagea)