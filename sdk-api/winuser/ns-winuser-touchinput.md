# TOUCHINPUT structure

## Description

Encapsulates data for touch input.

## Members

### `x`

The x-coordinate (horizontal point) of the touch input. This member is indicated in hundredths of a pixel of physical screen coordinates.

### `y`

The y-coordinate (vertical point) of the touch input. This member is indicated in hundredths of a pixel of physical screen coordinates.

### `hSource`

A device handle for the source input device. Each device is given a unique provider at run time by the touch input provider. See **Examples** section below.

### `dwID`

A touch point identifier that distinguishes a particular touch input. This value stays consistent in a touch contact sequence from the point a contact comes down until it comes back up. An ID may be reused later for subsequent contacts.

### `dwFlags`

A set of bit flags that specify various aspects of touch point press, release, and motion. The bits in this member can be any reasonable combination of the values in the Remarks section.

### `dwMask`

A set of bit flags that specify which of the optional fields in the structure contain valid values. The availability of valid information in the optional fields is device-specific. Applications should use an optional field value only when the corresponding bit is set in *dwMask*. This field may contain a combination of the *dwMask* flags mentioned in the Remarks section.

### `dwTime`

The time stamp for the event, in milliseconds. The consuming application should note that the system performs no validation on this field; when the **TOUCHINPUTMASKF_TIMEFROMSYSTEM** flag is not set, the accuracy and sequencing of values in this field are completely dependent on the touch input provider.

### `dwExtraInfo`

An additional value associated with the touch event.

### `cxContact`

The width of the touch contact area in hundredths of a pixel in physical screen coordinates. This value is only valid if the **dwMask** member has the **TOUCHEVENTFMASK_CONTACTAREA** flag set.

### `cyContact`

The height of the touch contact area in hundredths of a pixel in physical screen coordinates. This value is only valid if the **dwMask** member has the **TOUCHEVENTFMASK_CONTACTAREA** flag set.

## Remarks

The following table lists the flags for the **dwFlags** member.

| Flag | Value | Description |
| --- | --- | --- |
| **TOUCHEVENTF_MOVE** | 0x0001 | Movement has occurred. Cannot be combined with **TOUCHEVENTF_DOWN**. |
| **TOUCHEVENTF_DOWN** | 0x0002 | The corresponding touch point was established through a new contact. Cannot be combined with **TOUCHEVENTF_MOVE** or **TOUCHEVENTF_UP**. |
| **TOUCHEVENTF_UP** | 0x0004 | A touch point was removed. |
| **TOUCHEVENTF_INRANGE** | 0x0008 | A touch point is in range. This flag is used to enable touch hover support on compatible hardware. Applications that do not want support for hover can ignore this flag. |
| **TOUCHEVENTF_PRIMARY** | 0x0010 | Indicates that this **TOUCHINPUT** structure corresponds to a primary contact point. See the following text for more information on primary touch points. |
| **TOUCHEVENTF_NOCOALESCE** | 0x0020 | When received using **GetTouchInputInfo**, this input was not coalesced. |
| **TOUCHEVENTF_PEN** | 0x0040 | The touch event was triggered by a stylus device. |
| **TOUCHEVENTF_PALM** | 0x0080 | The touch event was triggered by the user's palm. |

**Note** If the target hardware on a machine does not support hover, when the **TOUCHEVENTF_UP** flag is set, the **TOUCHEVENTF_INRANGE** flag is cleared.
If the target hardware on a machine supports hover, the **TOUCHEVENTF_UP** and **TOUCHEVENTF_INRANGE** flags will be set independently.

The following table lists the flags for the **dwMask** member.

| Flag | Value | Description |
| --- | --- | --- |
| **TOUCHINPUTMASKF_CONTACTAREA** | 0x0004 | **cxContact** and **cyContact** are valid. See the following text for more information on primary touch points. |
| **TOUCHINPUTMASKF_EXTRAINFO** | 0x0002 | **dwExtraInfo** is valid. |
| **TOUCHINPUTMASKF_TIMEFROMSYSTEM** | 0x0001 | The system time was set in the **TOUCHINPUT** structure. |

A touch point is designated as primary when it is the first touch point to be established from a previous state of no touch points.
The **TOUCHEVENTF_PRIMARY** flag continues to be set for all subsequent events for the primary touch point until
the primary touch point is released. Note that a **TOUCHEVENTF_UP** event on the primary touch point does not
necessarily designate the end of a Windows Touch operation; the current Windows Touch operation proceeds from the establishment of the primary
touch point until the last touch point is released.

Note that a solitary touch point or, in a set of simultaneous touch points, the first to be detected, is designated the primary. The system mouse position follows the primary touch point and, in addition to touch messages, also generates **WM_LBUTTONDOWN**, **WM_MOUSEMOVE**, and **WM_LBUTTONUP** messages in response to actions on a primary touch point. The primary touch point can also generate **WM_RBUTTONDOWN** and **WM_RBUTTONUP** messages using the press and hold gesture.

Note that the touch point identifier may be dynamic and is associated with a given touch point only as long as the touch point persists. If contact is broken and then resumed (for example, if a finger is removed from the surface and then pressed down again), the same touch point (the same finger, pen, or other such device) may receive a different touch point identifier.

The following type is defined to represent a constant pointer to a **TOUCHINPUT** structure.

``` syntax

   typedef TOUCHINPUT const * PCTOUCHINPUT;

```

#### Examples

**Note** In the following example, the *pInputs* array is not sorted. Use the **dwID** value to track specific touch points.

```cpp
UINT cInputs = LOWORD(wParam);
PTOUCHINPUT pInputs = new TOUCHINPUT[cInputs];
if (NULL != pInputs)
{
    if (GetTouchInputInfo((HTOUCHINPUT)lParam,
                          cInputs,
                          pInputs,
                          sizeof(TOUCHINPUT)))
    {
        // process pInputs
        if (!CloseTouchInputHandle((HTOUCHINPUT)lParam))
        {
            // error handling
        }
    }
    else
    {
        // GetLastError() and error handling
    }
    delete [] pInputs;
}
else
{
    // error handling, presumably out of memory
}
return DefWindowProc(hWnd, message, wParam, lParam);

```

The following example shows how to get the device information from the **hSource** member. This example uses [GetRawInputDevice](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getrawinputdeviceinfoa) to retrieve information about the device.

```cpp
for (UINT i = 0; i < cInputs; i++){
  TOUCHINPUT ti = pInputs[i];
  RID_DEVICE_INFO info;
  ZeroMemory(&info, sizeof(RID_DEVICE_INFO));
  info.cbSize = sizeof(RID_DEVICE_INFO);
  UINT size = 0;
  if (GetRawInputDeviceInfo(ti.hSource, RIDI_DEVICEINFO, &info, &size)){
  }else{
    DWORD err = GetLastError();
  }
}

```

## See also

[GetTouchInputInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-gettouchinputinfo)

[Structures](https://learn.microsoft.com/windows/desktop/wintouch/structures)