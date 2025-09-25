## Description

**SetAdditionalForegroundBoostProcesses** is a performance assist API to help applications with a multi-process application model where multiple processes contribute to a foreground experience, either as data or rendering. Examples include browsers (with the browser manager or frame, tabs, plugins, etc. hosted in different processes) and IDEs (which spawn processes for compilation and other tasks).

Applications can use this API to provide a foreground priority boost to worker processes that help support the main application. Such applications can have a uniform priority boost applied to all of their constituent processes when the application's top level window is in the foreground.

## Parameters

### `topLevelWindow`

A handle to the top level window (HWND) of the application.

### `processHandleCount`

The number of process handles in **processHandleArray**. This function can be called at a single time with a maximum of 32 handles. Set this parameter to **0** along with setting **processHandleArray** to **NULL** to clear a prior boost configuration.

### `processHandleArray`

A group of process handles to be foreground boosted or de-boosted. Set this parameter to **NULL** along with setting **processHandleCount** to **0** to clear a prior boost configuration.

## Return value

Returns **TRUE** if the call succeeds in boosting the application, **FALSE** otherwise. **SetAdditionalForegroundBoostProcesses** sets the last error code, so the application can call [GetLastError()](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain extended information if the call failed (for example, ERROR_INVALID_PARAMETER, ERROR_NOT_ENOUGH_MEMORY, or ERROR_ACCESS_DENIED).

## Remarks

This function takes a group of process handles that all get foreground boosted or de-boosted when the passed-in top level HWND moves to the foreground or background respectively. Whenever the passed-in top level HWND becomes the foreground window, a foreground boost will also be applied to the processes passed in the handle array. A similar de-boost happens when the top level HWND moves to the background.

The top level HWND passed to this function must be owned by the calling process. The calling process should have the **PROCESS_SET_INFORMATION** access right on the process handles in the **processHandleArray** - in other words, you must have full control of every window in your process. If some external component injects a window that takes foreground, or if a dialog box appears, then you lose your boost.

If you have two top level windows, you need to call this function for each one.

If the passed-in top level HWND is already in the foreground when **SetAdditionalForegroundBoostProcesses** is called, all of the processes in the **processHandleArray** are immediately boosted.

A process whose handle is in the **processHandleArray** will get a foreground boost only when the top level HWND becomes the foreground window.

Additional foreground boost is applied only when:

1. The foreground window changes, or
2. If this function is called while the window is in the foreground and the new list has the process handle, or the list does not include the process handle while it was previously included.

When the process owning the top level HWND exits or terminates, the additional boosting relationship is torn down and secondary processes do not receive any additional foreground boosting.

The primary process's top level HWND will continue to hold references to secondary processes until either the primary process's top level HWND clears its grouped boost state, or the HWND is destroyed.

## Example

In this simple scenario, the application sets up its foreground process boost configuration when the top level window is created. When WM_CREATE is handled, the function is called with handles in the *lParam* and the count of handles in the *wParam*. These processes will get foreground or background priority boosted as *m_AppWindow* moves in and out of being the foreground window. If the *m_AppWindow* is the foreground window when the function is called, the processes will also get an immediate foreground priority boost.

```C++
case WM_CREATE:

    //
    // Configure the passed in worker processes (handles) in lParam, to get foreground priority boost when m_AppWindow moves in and
    // out of the foreground.
    //

    HANDLE *pMyHandles = retinterpret_cast<HANDLE*>(lParam);
    DWORD cHandles = reinterpret_cast<DWORD>(wParam);

    If (!SetAdditionalForegroundBoostProcesses(m_AppWindow, cHandles, pMyHandles))
    {
        printf(“SetAdditionalForegroundBoostProcesses() setup failed with error code : %d\n”, GetLastError());
    }

    break;
```

## See also

[**SetForegroundWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setforegroundwindow)