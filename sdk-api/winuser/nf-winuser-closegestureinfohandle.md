# CloseGestureInfoHandle function

## Description

Closes resources associated with a gesture information handle.

## Parameters

### `hGestureInfo`

The gesture information handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If an application processes a [WM_GESTURE](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesture) message, it is responsible for
closing the handle using this function. Failure to do so may result in
process memory leaks.

If the message is passed to [DefWindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-defwindowproca), or is forwarded using
one of the PostMessage or SendMessage classes of API functions, the handle
is transferred with the message and need not be closed by the application.

#### Examples

The following code shows a handler that closes the [GESTUREINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureinfo) handle if the gesture has been handled.

```cpp
  LRESULT DecodeGesture(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    // Create a structure to populate and retrieve the extra message info.
    GESTUREINFO gi;

    ZeroMemory(&gi, sizeof(GESTUREINFO));

    gi.cbSize = sizeof(GESTUREINFO);

    BOOL bResult  = GetGestureInfo((HGESTUREINFO)lParam, &gi);
    BOOL bHandled = FALSE;

    if (bResult){
        // now interpret the gesture
        switch (gi.dwID){
           case GID_ZOOM:
               // Code for zooming goes here
               bHandled = TRUE;
               break;
           case GID_PAN:
               // Code for panning goes here
               bHandled = TRUE;
               break;
           case GID_ROTATE:
               // Code for rotation goes here
               bHandled = TRUE;
               break;
           case GID_TWOFINGERTAP:
               // Code for two-finger tap goes here
               bHandled = TRUE;
               break;
           case GID_PRESSANDTAP:
               // Code for roll over goes here
               bHandled = TRUE;
               break;
           default:
               // A gesture was not recognized
               break;
        }
    }else{
        DWORD dwErr = GetLastError();
        if (dwErr > 0){
            //MessageBoxW(hWnd, L"Error!", L"Could not retrieve a GESTUREINFO structure.", MB_OK);
        }
    }
    if (bHandled){
        return 0;
    }else{
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
  }

```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtgfunctions)

[Programming Guide for Gestures](https://learn.microsoft.com/windows/desktop/wintouch/guide-multi-touch-gestures)