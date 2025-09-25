# GESTURECONFIG structure

## Description

Gets and sets the configuration for
enabling gesture messages and the type of this configuration.

## Members

### `dwID`

The identifier for the type of configuration that will have messages enabled or disabled. For more information, see Remarks.

### `dwWant`

The messages to enable.

### `dwBlock`

The messages to disable.

## Remarks

It is impossible to disable two-finger panning and keep single finger panning.
You must set the want bits for GC_PAN before you can set them for GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY
or GC_PAN_WITH_SINGLE_FINGER_VERTICALLY.

An inertia vector is included in the GID_PAN message with the GF_END flag if inertia was disabled by a call to
[SetGestureConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setgestureconfig).

When you pass this structure, the *dwID* member contains information
for a set of gestures. This determines what the other flags will mean.
If you set flags for pan messages, they will be different from those
flags that are set for rotation messages.

The following table indicates the various identifiers for gestures that are
supported by the *dwID* member of the **GESTURECONFIG** structure. Note that setting
*dwID* to 0 indicates that global gesture configuration flags are set.

| Name | Value | Description |
| --- | --- | --- |
| GID_ZOOM | 3 | Indicates configuration settings for the zoom gesture. |
| GID_PAN | 4 | Indicates the pan gesture. |
| GID_ROTATE | 5 | Indicates the rotation gesture. |
| GID_TWOFINGERTAP | 6 | Indicates the two-finger tap gesture. |
| GID_PRESSANDTAP | 7 | Indicates the press and tap gesture. |

The following flags are used when *dwID* is set to 0.

| Name | Value | Description |
| --- | --- | --- |
| GC_ALLGESTURES | 0x00000001 | Indicates all of the gestures. |

The following flags are used when *dwID* is set to GID_ZOOM.

| Name | Value | Description |
| --- | --- | --- |
| GC_ZOOM | 0x00000001 | Indicates the zoom gesture. |

The following flags are used when *dwID* is set to GID_PAN.

| Name | Value | Description |
| --- | --- | --- |
| GC_PAN | 0x00000001 | Indicates all pan gestures. |
| GC_PAN_WITH_SINGLE_FINGER_VERTICALLY | 0x00000002 | Indicates vertical pans with one finger. |
| GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY | 0x00000004 | Indicates horizontal pans with one finger. |
| GC_PAN_WITH_GUTTER | 0x00000008 | Limits perpendicular movement to primary direction until a threshold is reached to break out of the gutter. |
| GC_PAN_WITH_INERTIA | 0x00000010 | Indicates panning with inertia to smoothly slow when pan gestures stop. |

**Note** Setting the **GID_PAN** flags in [SetGestureConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setgestureconfig) will affect the default gesture handler for panning.
You should not have both **dwWant** and **dwBlock** set for the same flags; this will result in unexpected behavior.
See [Windows Touch Gestures](https://learn.microsoft.com/windows/desktop/wintouch/guide-multi-touch-gestures) for more information on panning
and legacy panning support; see **SetGestureConfig** for examples of enabling and blocking gestures.

The following flags are used when *dwID* is set to GID_ROTATE.

| Name | Value | Description |
| --- | --- | --- |
| GC_ROTATE | 0x00000001 | Indicates the rotation gesture. |

The following flags are used when *dwID* is set to GID_TWOFINGERTAP.

| Name | Value | Description |
| --- | --- | --- |
| GC_TWOFINGERTAP | 0x00000001 | Indicates the two-finger tap gesture. |

The following flags are used when *dwID* is set to GID_PRESSANDTAP.

| Name | Value | Description |
| --- | --- | --- |
| GC_PRESSANDTAP | 0x00000001 | Indicates the press and tap gesture. |

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

[GetGestureConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getgestureconfig)

[SetGestureConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setgestureconfig)

[Structures](https://learn.microsoft.com/windows/desktop/wintouch/mtstructures)