# AttachThreadInput function

## Description

Attaches or detaches the input processing mechanism of one thread to that of another thread.

## Parameters

### `idAttach` [in]

The identifier of the thread to be attached to another thread. The thread to be attached cannot be a system thread.

### `idAttachTo` [in]

The identifier of the thread to which *idAttach* will be attached. This thread cannot be a system thread.

A thread cannot attach to itself. Therefore, *idAttachTo* cannot equal *idAttach*.

### `fAttach` [in]

If this parameter is **TRUE**, the two threads are attached. If the parameter is **FALSE**, the threads are detached.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Windows Server 2003 and Windows XP:** There is no extended error information; do not call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). This behavior changed as of Windows Vista.

## Remarks

By using the **AttachThreadInput** function, a thread can share its input states (such as keyboard states and the current focus window) with another thread. Keyboard and mouse events received by both threads are processed in the order they were received until the threads are detached by calling **AttachThreadInput** a second time and specifying **FALSE** for the *fAttach* parameter.

The
**AttachThreadInput** function fails if either of the specified threads does not have a message queue. The system creates a thread's message queue when the thread makes its first call to one of the USER or GDI functions. The
**AttachThreadInput** function also fails if a journal record hook is installed. Journal record hooks attach all input queues together.

Note that key state, which can be ascertained by calls to the
[GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate) or
[GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate) function, is reset after a call to
**AttachThreadInput**. You cannot attach a thread to a thread in another [desktop](https://learn.microsoft.com/windows/desktop/winstation/desktops).

## See also

[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)

[GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)

[GetWindowThreadProcessId](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowthreadprocessid)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SetFocus](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iresourcemanager-setfocus)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)