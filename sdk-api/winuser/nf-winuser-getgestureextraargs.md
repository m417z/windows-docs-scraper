# GetGestureExtraArgs function

## Description

Retrieves additional information about a gesture from its [GESTUREINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureinfo) handle.

## Parameters

### `hGestureInfo` [in]

The handle to the gesture information that is passed in the *lParam* of a [WM_GESTURE](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesture) message.

### `cbExtraArgs` [in]

A count of the bytes of data stored in the extra arguments.

### `pExtraArgs` [out]

A pointer to the extra argument information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

This function is reserved for future use and should only be used for testing. Windows 7 gestures do not use extra arguments.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtgfunctions)

[GetGestureInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getgestureinfo)

[Programming Guide for Gestures](https://learn.microsoft.com/windows/desktop/wintouch/guide-multi-touch-gestures)