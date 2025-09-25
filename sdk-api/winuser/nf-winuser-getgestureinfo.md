# GetGestureInfo function

## Description

Retrieves a [GESTUREINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureinfo) structure given a handle to
the gesture information.

## Parameters

### `hGestureInfo` [in]

The gesture information handle.

### `pGestureInfo` [out]

A pointer to the gesture information structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **cbSize** member of the [GESTUREINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureinfo) structure passed in to the function must be set
before the function is called. Otherwise, calls to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **ERROR_INVALID_PARAMETER** (87 in decimal).
If an application processes a [WM_GESTURE](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesture) message, it is responsible for
closing the handle using [CloseGestureInfoHandle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closegestureinfohandle). Failure to do so may result in
process memory leaks.

If the message is passed to [DefWindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-defwindowproca), or is forwarded using
one of the PostMessage or SendMessage classes of API functions, the handle
is transferred with the message and need not be closed by the application.

#### Examples

```cpp

    GESTUREINFO gestureInfo = {0};
    gestureInfo.cbSize = sizeof(gestureInfo);
    BOOL bResult = GetGestureInfo((HGESTUREINFO)lParam, &gestureInfo);

    if (!bResult){
        DWORD err = GetLastError();
    }

```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtgfunctions)

[Programming Guide for Gestures](https://learn.microsoft.com/windows/desktop/wintouch/guide-multi-touch-gestures)