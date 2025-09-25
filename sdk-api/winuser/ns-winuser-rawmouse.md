# RAWMOUSE structure

## Description

Contains information about the state of the mouse.

## Members

### `usFlags`

Type: **USHORT**

The mouse state. This member can be any reasonable combination of the following.

| Value | Meaning |
|-------|---------|
| **MOUSE_MOVE_RELATIVE**0x00 | Mouse movement data is relative to the last mouse position. For further information about mouse motion, see the following Remarks section. |
| **MOUSE_MOVE_ABSOLUTE**0x01 | Mouse movement data is based on absolute position. For further information about mouse motion, see the following Remarks section. |
| **MOUSE_VIRTUAL_DESKTOP**0x02 | Mouse coordinates are mapped to the virtual desktop (for a multiple monitor system). For further information about mouse motion, see the following Remarks section. |
| **MOUSE_ATTRIBUTES_CHANGED**0x04 | Mouse attributes changed; application needs to query the mouse attributes. |
| **MOUSE_MOVE_NOCOALESCE**0x08 | This mouse movement event was not coalesced. Mouse movement events can be coalesced by default.<br>Windows XP/2000: This value is not supported. |

### `DUMMYUNIONNAME.ulButtons`

Type: **ULONG**

Reserved.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.usButtonFlags`

Type: **USHORT**

The transition state of the mouse buttons. This member can be one or more of the following values.

| Value | Meaning |
|-------|---------|
| **RI_MOUSE_BUTTON_1_DOWN****RI_MOUSE_LEFT_BUTTON_DOWN**0x0001 | Left button changed to down. |
| **RI_MOUSE_BUTTON_1_UP****RI_MOUSE_LEFT_BUTTON_UP**0x0002 | Left button changed to up. |
| **RI_MOUSE_BUTTON_2_DOWN****RI_MOUSE_RIGHT_BUTTON_DOWN**0x0004 | Right button changed to down. |
| **RI_MOUSE_BUTTON_2_UP****RI_MOUSE_RIGHT_BUTTON_UP**0x0008 | Right button changed to up. |
| **RI_MOUSE_BUTTON_3_DOWN****RI_MOUSE_MIDDLE_BUTTON_DOWN**0x0010 | Middle button changed to down. |
| **RI_MOUSE_BUTTON_3_UP****RI_MOUSE_MIDDLE_BUTTON_UP**0x0020 | Middle button changed to up. |
| **RI_MOUSE_BUTTON_4_DOWN**0x0040 | XBUTTON1 changed to down. |
| **RI_MOUSE_BUTTON_4_UP**0x0080 | XBUTTON1 changed to up. |
| **RI_MOUSE_BUTTON_5_DOWN**0x0100 | XBUTTON2 changed to down. |
| **RI_MOUSE_BUTTON_5_UP**0x0200 | XBUTTON2 changed to up. |
| **RI_MOUSE_WHEEL**0x0400 | Raw input comes from a mouse wheel. The wheel delta is stored in **usButtonData**.<br>A positive value indicates that the wheel was rotated forward, away from the user; a negative value indicates that the wheel was rotated backward, toward the user. For further information see the following Remarks section. |
| **RI_MOUSE_HWHEEL**0x0800 | Raw input comes from a horizontal mouse wheel. The wheel delta is stored in **usButtonData**.<br>A positive value indicates that the wheel was rotated to the right; a negative value indicates that the wheel was rotated to the left. For further information see the following Remarks section.<br>Windows XP/2000: This value is not supported. |

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.usButtonData`

Type: **USHORT**

If **usButtonFlags** has **RI_MOUSE_WHEEL** or **RI_MOUSE_HWHEEL**, this member specifies the distance the wheel is rotated. For further information see the following Remarks section.

### `ulRawButtons`

Type: **ULONG**

The raw state of the mouse buttons. The Win32 subsystem does not use this member.

### `lLastX`

Type: **LONG**

The motion in the X direction. This is signed relative motion or absolute motion, depending on the value of **usFlags**.

### `lLastY`

Type: **LONG**

The motion in the Y direction. This is signed relative motion or absolute motion, depending on the value of **usFlags**.

### `ulExtraInformation`

Type: **ULONG**

Additional device-specific information for the event. See [Distinguishing Pen Input from Mouse and Touch](https://learn.microsoft.com/windows/win32/tablet/system-events-and-mouse-messages#distinguishing-pen-input-from-mouse-and-touch) for more info.

## Remarks

If the mouse has moved, indicated by **MOUSE_MOVE_RELATIVE** or **MOUSE_MOVE_ABSOLUTE**, **lLastX** and **lLastY** specify information about that movement. The information is specified as relative or absolute integer values.

If **MOUSE_MOVE_RELATIVE** value is specified, **lLastX** and **lLastY** specify movement relative to the previous mouse event (the last reported position). Positive values mean the mouse moved right (or down); negative values mean the mouse moved left (or up).

If **MOUSE_MOVE_ABSOLUTE** value is specified, **lLastX** and **lLastY** contain normalized absolute coordinates between 0 and 65,535. Coordinate (0,0) maps onto the upper-left corner of the display surface; coordinate (65535,65535) maps onto the lower-right corner. In a multimonitor system, the coordinates map to the primary monitor.

If **MOUSE_VIRTUAL_DESKTOP** is specified in addition to **MOUSE_MOVE_ABSOLUTE**, the coordinates map to the entire virtual desktop.

```cpp
case WM_INPUT:
{
    UINT dwSize = sizeof(RAWINPUT);
    static BYTE lpb[sizeof(RAWINPUT)];

    GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

    RAWINPUT* raw = (RAWINPUT*)lpb;

    if (raw->header.dwType == RIM_TYPEMOUSE)
    {
        RAWMOUSE& mouse = raw->data.mouse;

        if (mouse.usFlags & MOUSE_MOVE_ABSOLUTE)
        {
            RECT rect;
            if (mouse.usFlags & MOUSE_VIRTUAL_DESKTOP)
            {
                rect.left = GetSystemMetrics(SM_XVIRTUALSCREEN);
                rect.top = GetSystemMetrics(SM_YVIRTUALSCREEN);
                rect.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
                rect.bottom = GetSystemMetrics(SM_CYVIRTUALSCREEN);
            }
            else
            {
                rect.left = 0;
                rect.top = 0;
                rect.right = GetSystemMetrics(SM_CXSCREEN);
                rect.bottom = GetSystemMetrics(SM_CYSCREEN);
            }

            int absoluteX = MulDiv(mouse.lLastX, rect.right, USHRT_MAX) + rect.left;
            int absoluteY = MulDiv(mouse.lLastY, rect.bottom, USHRT_MAX) + rect.top;
            ...
        }
        else if (mouse.lLastX != 0 || mouse.lLastY != 0)
        {
            int relativeX = mouse.lLastX;
            int relativeY = mouse.lLastY;
            ...
        }
        ...
    }

    return 0;
}
```

In contrast to legacy [WM_MOUSEMOVE](https://learn.microsoft.com/windows/win32/inputdev/wm-mousemove) window messages Raw Input mouse events is not subject to the effects of the mouse speed set in the Control Panel's **Mouse Properties** sheet. See [Mouse Input Overview](https://learn.microsoft.com/windows/win32/inputdev/about-mouse-input) for details.

If mouse wheel is moved, indicated by **RI_MOUSE_WHEEL** or **RI_MOUSE_HWHEEL** in **usButtonFlags**, then **usButtonData** contains a signed **short** value that specifies the distance the wheel is rotated.

The wheel rotation will be a multiple of **WHEEL_DELTA**, which is set at 120. This is the threshold for action to be taken, and one such action (for example, scrolling one increment) should occur for each delta.

The delta was set to 120 to allow Microsoft or other vendors to build finer-resolution wheels (a freely-rotating wheel with no notches) to send more messages per rotation, but with a smaller value in each message. To use this feature, you can either add the incoming delta values until **WHEEL_DELTA** is reached (so for a delta-rotation you get the same response), or scroll partial lines in response to the more frequent messages. You can also choose your scroll granularity and accumulate deltas until it is reached.

The application could also retrieve the current lines-to-scroll and characters-to-scroll user setting by using the [SystemParametersInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa) API with **SPI_GETWHEELSCROLLLINES** or **SPI_GETWHEELSCROLLCHARS** parameter.

Here is example of such wheel handling code:

```cpp
RAWMOUSE& mouse = raw->data.mouse;

if ((mouse.usButtonFlags & RI_MOUSE_WHEEL) || (mouse.usButtonFlags & RI_MOUSE_HWHEEL))
{
    short wheelDelta = (short)mouse.usButtonData;
    float scrollDelta = (float)wheelDelta / WHEEL_DELTA;

    if (mouse.usButtonFlags & RI_MOUSE_HWHEEL) // Horizontal
    {
        unsigned long scrollChars = 1; // 1 is the default
        SystemParametersInfo(SPI_GETWHEELSCROLLCHARS, 0, &scrollChars, 0);
        scrollDelta *= scrollChars;
        ...
    }
    else // Vertical
    {
        unsigned long scrollLines = 3; // 3 is the default
        SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &scrollLines, 0);
        if (scrollLines != WHEEL_PAGESCROLL)
            scrollDelta *= scrollLines;
        ...
    }
}
```

## See also

**Conceptual**

[GetRawInputDeviceInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getrawinputdeviceinfoa)

[RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput)

[Raw Input](https://learn.microsoft.com/windows/win32/inputdev/raw-input)

**Reference**

[MOUSEINPUT structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-mouseinput)

[SendInput function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-sendinput)

[MOUSE_INPUT_DATA structure](https://learn.microsoft.com/windows/win32/api/ntddmou/ns-ntddmou-mouse_input_data)

[Mouse Input Overview (legacy)](https://learn.microsoft.com/windows/win32/inputdev/about-mouse-input)

[Mouse Input Notifications (legacy)](https://learn.microsoft.com/windows/win32/inputdev/mouse-input-notifications)

[SystemParametersInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa)