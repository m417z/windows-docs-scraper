# UnhookWinEvent function

## Description

Removes an event hook function created by a previous call to [SetWinEventHook](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwineventhook).

## Parameters

### `hWinEventHook` [in]

Type: **HWINEVENTHOOK**

Handle to the event hook returned in the previous call to [SetWinEventHook](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwineventhook).

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns **TRUE**; otherwise, returns **FALSE**.

Three common errors cause this function to fail:

* The *hWinEventHook* parameter is **NULL** or not valid.
* The event hook specified by *hWinEventHook* was already removed.
* **UnhookWinEvent** is called from a thread that is different from the original call to [SetWinEventHook](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwineventhook).

## Remarks

This function removes the event hook specified by *hWinEventHook* that prevents the corresponding callback function from receiving further event notifications. If the client's thread ends, the system automatically calls this function.

Call this function from the same thread that installed the event hook. **UnhookWinEvent** fails if called from a thread different from the call that corresponds to [SetWinEventHook](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwineventhook).

If WINEVENT_INCONTEXT was specified when this event hook was installed, the system attempts to unload the corresponding DLL from all processes that loaded it. Although unloading does not occur immediately, the hook function is not called after **UnhookWinEvent** returns. For more information on WINEVENT_INCONTEXT, see [In-Context Hook Functions](https://learn.microsoft.com/windows/desktop/WinAuto/in-context-hook-functions).