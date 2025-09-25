# GetGestureConfig function

## Description

Retrieves the configuration for which Windows Touch gesture messages are sent from a window.

## Parameters

### `hwnd` [in]

A handle to the window to get the gesture configuration from.

### `dwReserved` [in]

This value is reserved and must be set to 0.

### `dwFlags` [in]

A gesture command flag value indicating options for retrieving the gesture configuration. See Remarks for additional information and supported values.

### `pcIDs` [in]

The size, in number of gesture configuration structures, that is in the *pGestureConfig* buffer.

### `pGestureConfig` [in, out]

An array of gesture configuration structures that specify the gesture configuration.

### `cbSize` [in]

The size of the gesture configuration ([GESTURECONFIG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureconfig)) structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Passing a value other than `sizeof(GESTURECONFIG)` for the
*cbSize* parameter will cause calls to this function to fail and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will
return **ERROR_INVALID_PARAMETER** (87 in decimal).

The following table lists the gesture configuration values:

| Name | Value | Description |
| --- | --- | --- |
| **GCF_INCLUDE_ANCESTORS** | 0x00000001 | If specified, **GetGestureConfig** returns consolidated configuration for the specified window and its parent window chain. |

#### Examples

```cpp
    GESTURECONFIG gc[3];
    UINT uiGcs = 3;

    ZeroMemory(&gc, sizeof(gc));
    gc[0].dwID  = GID_ZOOM;
    gc[1].dwID  = GID_ROTATE;
    gc[2].dwID  = GID_PAN;
    BOOL bResult = GetGestureConfig(hWnd, 0, 0, &uiGcs, gc, sizeof(GESTURECONFIG));
    if (!bResult){
        DWORD err = GetLastError();
    }

```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtgfunctions)

[GESTURECONFIG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureconfig)

[Programming Guide for Gestures](https://learn.microsoft.com/windows/desktop/wintouch/guide-multi-touch-gestures)