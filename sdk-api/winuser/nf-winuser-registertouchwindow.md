# RegisterTouchWindow function

## Description

Registers a window as being touch-capable.

## Parameters

### `hwnd` [in]

The handle of the window being registered. The function fails with **ERROR_ACCESS_DENIED** if the calling thread does not own the specified window.

### `ulFlags` [in]

A set of bit flags that specify optional modifications. This field may contain 0 or one of the following values.

| Value | Meaning |
| --- | --- |
| **TWF_FINETOUCH** | Specifies that *hWnd* prefers noncoalesced touch input. |
| **TWF_WANTPALM** | Setting this flag disables palm rejection which reduces delays for getting [WM_TOUCH](https://learn.microsoft.com/windows/desktop/wintouch/wm-touchdown) messages. This is useful if you want as quick of a response as possible when a user touches your application.<br><br>By default, palm detection is enabled and some [WM_TOUCH](https://learn.microsoft.com/windows/desktop/wintouch/wm-touchdown) messages are prevented from being sent to your application. This is useful if you do not want to receive **WM_TOUCH** messages that are from palm contact. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

**Note** **RegisterTouchWindow** must be called on every window that will be used for touch input. This means that if you have an application that has multiple windows within it, **RegisterTouchWindow** must be called on every window in that application that uses touch features. Also, an application can call **RegisterTouchWindow** any number of times for the same window if it desires to change the modifier flags. A window can be marked as no longer requiring touch input using the [UnregisterTouchWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregistertouchwindow) function.

If **TWF_WANTPALM** is enabled, packets from touch input are not buffered and palm detection is not performed before the packets are sent to your application. Enabling **TWF_WANTPALM** is most useful if you want minimal latencies when processing [WM_TOUCH](https://learn.microsoft.com/windows/desktop/wintouch/wm-touchdown) messages.

#### Examples

```cpp

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in the global variable.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   RegisterTouchWindow(hWnd, 0);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}	
	
```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtfunctions)

[UnregisterTouchWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregistertouchwindow)