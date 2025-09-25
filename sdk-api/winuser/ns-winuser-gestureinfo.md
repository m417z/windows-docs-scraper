# GESTUREINFO structure

## Description

 Stores information about a gesture.

## Members

### `cbSize`

The size of the structure, in bytes. The caller must set this to `sizeof(GESTUREINFO)`.

### `dwFlags`

The state of the gesture. For additional information, see Remarks.

### `dwID`

The identifier of the gesture command.

### `hwndTarget`

A handle to the window that is targeted by this gesture.

### `ptsLocation`

A **POINTS** structure containing the coordinates associated with the gesture. These coordinates are always relative to the origin of the screen.

### `dwInstanceID`

An internally used identifier for the structure.

### `dwSequenceID`

An internally used identifier for the sequence.

### `ullArguments`

A 64-bit unsigned integer that contains the arguments for gestures that fit into 8 bytes.

### `cbExtraArgs`

The size, in bytes, of extra arguments that accompany this gesture.

## Remarks

The **HIDWORD** of the **ullArguments** member is always 0, with the following exceptions:

* For **GID_PAN**, it is 0 except when there is inertia. When **GF_INERTIA** is set, the **HIDWORD** is an inertia vector (two 16-bit values).
* For **GID_PRESSANDTAP**, it is the distance between the two points.

The **GESTUREINFO** structure is retrieved by passing the handle to the gesture information structure
to the [GetGestureInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getgestureinfo) function.

The following flags indicate the various states of the gestures and are stored in **dwFlags**.

| Name | Value | Description |
| --- | --- | --- |
| GF_BEGIN | 0x00000001 | A gesture is starting. |
| GF_INERTIA | 0x00000002 | A gesture has triggered inertia. |
| GF_END | 0x00000004 | A gesture has finished. |

**Note** Most applications should ignore the **GID_BEGIN** and **GID_END** messages and pass them to **DefWindowProc**.
These messages are used by the default gesture handler. Application behavior is undefined when
the **GID_BEGIN** and **GID_END** messages are consumed by a third-party application.

The following table indicates the various identifiers for gestures.

| Name | Value | Description |
| --- | --- | --- |
| **GID_BEGIN** | 1 | A gesture is starting. |
| **GID_END** | 2 | A gesture is ending. |
| **GID_ZOOM** | 3 | The zoom gesture. |
| **GID_PAN** | 4 | The pan gesture. |
| **GID_ROTATE** | 5 | The rotation gesture. |
| **GID_TWOFINGERTAP** | 6 | The two-finger tap gesture. |
| **GID_PRESSANDTAP** | 7 | The press and tap gesture. |

**Note** The **GID_PAN** gesture has built-in inertia. At the end of a pan gesture, additional pan
gesture messages are created by the operating system.

The following type is defined to represent a constant pointer to a **GESTUREINFO** structure.

```cpp

    typedef GESTUREINFO const * PCGESTUREINFO;	

```

#### Examples

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

[GetGestureInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getgestureinfo)

[Structures](https://learn.microsoft.com/windows/desktop/wintouch/mtstructures)

[WM_GESTURE](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesture)