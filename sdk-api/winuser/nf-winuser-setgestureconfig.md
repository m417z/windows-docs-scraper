# SetGestureConfig function

## Description

Configures the messages that are sent from a window for Windows Touch gestures.

## Parameters

### `hwnd` [in]

A handle to the window to set the gesture configuration on.

### `dwReserved` [in]

This value is reserved and must be set to 0.

### `cIDs` [in]

A count of the gesture configuration structures that are being passed.

### `pGestureConfig` [in]

An array of gesture configuration structures that specify the gesture configuration.

### `cbSize` [in]

The size of the gesture configuration ([GESTURECONFIG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureconfig)) structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If you don't expect to change the gesture configuration, call **SetGestureConfig** at window creation time.
If you want to dynamically change the gesture configuration, call **SetGestureConfig** in response to [WM_GESTURENOTIFY](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesturenotify) messages.

The following table shows the identifiers for gestures that are
supported by the *dwID* member of the [GESTURECONFIG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureconfig) structure. Note that setting
*dwID* to 0 indicates that global gesture configuration flags are set.

| Name | Value | Description |
| --- | --- | --- |
| **GID_ZOOM** | 3 | Configuration settings for the zoom gesture. |
| **GID_PAN** | 4 | The pan gesture. |
| **GID_ROTATE** | 5 | The rotation gesture. |
| **GID_TWOFINGERTAP** | 6 | The two-finger tap gesture. |
| **GID_PRESSANDTAP** | 7 | The press and tap gesture. |

The following flags are used when *dwID* is set to zero.

| Name | Value | Description |
| --- | --- | --- |
| **GC_ALLGESTURES** | 0x00000001 | All of the gestures. |

The following flags are used when *dwID* is set to GID_ZOOM.

| Name | Value | Description |
| --- | --- | --- |
| **GC_ZOOM** | 0x00000001 | The zoom gesture. |

The following flags are used when *dwID* is set to GID_PAN.

| Name | Value | Description |
| --- | --- | --- |
| **GC_PAN** | 0x00000001 | All pan gestures. |
| **GC_PAN_WITH_SINGLE_FINGER_VERTICALLY** | 0x00000002 | Vertical pans with one finger. |
| **GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY** | 0x00000004 | Horizontal pans with one finger. |
| **GC_PAN_WITH_GUTTER** | 0x00000008 | Panning with a gutter boundary around the edges of pannable region. The gutter boundary limits perpendicular movement to a primary direction until a threshold is reached to break out of the gutter. |
| **GC_PAN_WITH_INTERTIA** | 0x00000010 | Panning with inertia to smoothly slow when pan gestures stop. |

**Note** Pan gestures can be used in conjunction with each other to control behavior.
For example, setting the **dwWant** bits to panning with single-finger horizontal
and setting the **dwBlock** bits to single-finger vertical will restrict panning to horizontal pans. Changing the
**dwWant** bit to have `GC_PAN_WITH_SINGLE_FINGER_VERTICALLY | GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY` and removing single-finger vertical pan from the **dwBlock** bit will enable both vertical and horizontal panning.

**Note** By default, panning has inertia enabled.

**Note** A single call to **SetGestureConfig** cannot include other GIDs along with 0.

The following flags are used when *dwID* is set to GID_ROTATE.

| Name | Value | Description |
| --- | --- | --- |
| **GC_ROTATE** | 0x00000001 | The rotation gesture. |

The following flags are used when *dwID* is set to **GID_TWOFINGERTAP**.

| Name | Value | Description |
| --- | --- | --- |
| **GC_TWOFINGERTAP** | 0x00000001 | The two-finger tap gesture. |

The following flags are used when *dwID* is set to **GID_PRESSANDTAP**.

| Name | Value | Description |
| --- | --- | --- |
| **GC_PRESSANDTAP** | 0x00000001 | The press and tap gesture. |

**Note** Calling **SetGestureConfig** will change the gesture configuration for the lifetime of the Window, not just for the next gesture.

#### Examples

The following example shows how you could receive horizontal and vertical single-finger panning with no gutter and no
inertia. This is a typical configuration for a 2-D navigation application such as the Microsoft PixelSense Globe application.

```cpp
// set up our want / block settings
DWORD dwPanWant  = GC_PAN_WITH_SINGLE_FINGER_VERTICALLY | GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY;
DWORD dwPanBlock = GC_PAN_WITH_GUTTER | GC_PAN_WITH_INERTIA;

// set the settings in the gesture configuration
GESTURECONFIG gc[] = {{ GID_ZOOM, GC_ZOOM, 0 },
                      { GID_ROTATE, GC_ROTATE, 0},
                      { GID_PAN, dwPanWant , dwPanBlock}
                     };

UINT uiGcs = 3;
BOOL bResult = SetGestureConfig(hWnd, 0, uiGcs, gc, sizeof(GESTURECONFIG));

if (!bResult){
    DWORD err = GetLastError();
}

```

The following example shows how to receive single-finger pan gestures and disable gutter panning. This is a typical
configuration for applications that scroll text such as Notepad.

**Note** You should explicitly set all the flags that you want enabled or disabled when controlling single-finger panning.

```cpp
// set up our want / block settings
DWORD dwPanWant  = GC_PAN | GC_PAN_WITH_SINGLE_FINGER_VERTICALLY;
DWORD dwPanBlock = GC_PAN_WITH_GUTTER;

// set the settings in the gesture configuration
GESTURECONFIG gc[] = {{ GID_ZOOM, GC_ZOOM, 0 },
                      { GID_ROTATE, GC_ROTATE, 0},
                      { GID_PAN, dwPanWant , dwPanBlock}
                     };

UINT uiGcs = 3;
BOOL bResult = SetGestureConfig(hWnd, 0, uiGcs, gc, sizeof(GESTURECONFIG));

if (!bResult){
    DWORD err = GetLastError();
}

```

The following example shows how you can disable all gestures.

```cpp
// set the settings in the gesture configuration
GESTURECONFIG gc[] = {0,0,GC_ALLGESTURES};

UINT uiGcs = 1;
BOOL bResult = SetGestureConfig(hWnd, 0, uiGcs, gc, sizeof(GESTURECONFIG));

if (!bResult){
    DWORD err = GetLastError();
}

```

The following example shows how you could enable all gestures.

```cpp
GESTURECONFIG gc = {0,GC_ALLGESTURES,0};

UINT uiGcs = 1;

BOOL bResult = SetGestureConfig(hWnd, 0, uiGcs, &gc, sizeof(GESTURECONFIG));

if (!bResult){
    DWORD err = GetLastError();
}

```

The following example shows how you could enable all Windows 7 gestures.

```cpp
// set the settings in the gesture configuration
GESTURECONFIG gc[] = {{ GID_ZOOM, GC_ZOOM, 0 },
                      { GID_ROTATE, GC_ROTATE, 0},
                      { GID_PAN, GC_PAN , 0},
                      { GID_TWOFINGERTAP, GC_TWOFINGERTAP , 0},
                      { GID_PRESSANDTAP, GC_PRESSANDTAP , 0}
                     };

UINT uiGcs = 5;
BOOL bResult = SetGestureConfig(hWnd, 0, uiGcs, gc, sizeof(GESTURECONFIG));

if (!bResult){
    DWORD err = GetLastError();
}

```

The following example configuration would set the parent window to
enable support for zoom, horizontal pan, and vertical pan while the child window would just support horizontal pan.

```cpp
// set up our want / block settings for a parent window
DWORD dwPanWant  = GC_PAN_WITH_SINGLE_FINGER_VERTICALLY | GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY;
DWORD dwPanBlock = GC_PAN_WITH_GUTTER | GC_PAN_WITH_INERTIA;

// set the settings in the gesture configuration
GESTURECONFIG gcParent[] = {{ GID_ZOOM, GC_ZOOM, 0 },
                            { GID_PAN, dwPanWant , dwPanBlock}
                           };

// Set the pan settings for a child window
dwPanWant  = GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY;
dwPanBlock = GC_PAN_WITH_SINGLE_FINGER_VERTICALLY | GC_PAN_WITH_GUTTER | GC_PAN_WITH_INERTIA;

GESTURECONFIG gcChild[]  = {{ GID_ZOOM, 0, GC_ZOOM },
                            { GID_PAN, dwPanWant , dwPanBlock}
                           };

UINT uiGcs   = 2;
BOOL bResult = FALSE;

if (isParent){
  bResult = SetGestureConfig(hWnd, 0, uiGcs, gcParent, sizeof(GESTURECONFIG));
}else{
  bResult = SetGestureConfig(hWnd, 0, uiGcs, gcChild, sizeof(GESTURECONFIG));
}

if (!bResult){
    DWORD err = GetLastError();
}

```

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtgfunctions)

[GESTURECONFIG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-gestureconfig)

[GetGestureConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getgestureconfig)

[Programming Guide for Gestures](https://learn.microsoft.com/windows/desktop/wintouch/guide-multi-touch-gestures)

[WM_GESTURENOTIFY](https://learn.microsoft.com/windows/desktop/wintouch/wm-gesturenotify)