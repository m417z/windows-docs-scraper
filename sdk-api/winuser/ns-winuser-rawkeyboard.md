# RAWKEYBOARD structure

## Description

Contains information about the state of the keyboard.

## Members

### `MakeCode`

Type: **USHORT**

Specifies the [scan code](https://learn.microsoft.com/windows/win32/inputdev/about-keyboard-input#scan-codes) associated with a key press. See Remarks.

### `Flags`

Type: **USHORT**

Flags for scan code information. It can be one or more of the following:

| Value | Meaning |
|----------------------|----------------------------------|
| **RI\_KEY\_MAKE** 0 | The key is down. |
| **RI\_KEY\_BREAK** 1 | The key is up. |
| **RI\_KEY\_E0** 2 | The scan code has the E0 prefix. |
| **RI\_KEY\_E1** 4 | The scan code has the E1 prefix. |

### `Reserved`

Type: **USHORT**

Reserved; must be zero.

### `VKey`

Type: **USHORT**

The corresponding [legacy virtual-key code](https://learn.microsoft.com/windows/win32/inputdev/virtual-key-codes).

### `Message`

Type: **UINT**

The corresponding [legacy keyboard window message](https://learn.microsoft.com/windows/win32/inputdev/keyboard-input-notifications), for example [WM_KEYDOWN](https://learn.microsoft.com/windows/win32/inputdev/wm-keydown), [WM_SYSKEYDOWN](https://learn.microsoft.com/windows/win32/inputdev/wm-syskeydown), and so forth.

### `ExtraInformation`

Type: **ULONG**

The device-specific additional information for the event.

## Remarks

**KEYBOARD_OVERRUN_MAKE_CODE** is a special **MakeCode** value sent when an invalid or unrecognizable combination of keys is pressed or the number of keys pressed exceeds the limit for this keyboard.

```cpp
case WM_INPUT:
{
    UINT dwSize = sizeof(RAWINPUT);
    static BYTE lpb[sizeof(RAWINPUT)];

    GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

    RAWINPUT* raw = (RAWINPUT*)lpb;

    if (raw->header.dwType == RIM_TYPEKEYBOARD)
    {
        RAWKEYBOARD& keyboard = raw->data.keyboard;
        WORD scanCode = 0;
        BOOL keyUp = keyboard.Flags & RI_KEY_BREAK;

        // Ignore key overrun state and keys not mapped to any virtual key code
        if (keyboard.MakeCode == KEYBOARD_OVERRUN_MAKE_CODE || keyboard.VKey >= UCHAR_MAX)
            return 0;

        if (keyboard.MakeCode)
        {
            // Compose the full scan code value with its extended byte
            scanCode = MAKEWORD(keyboard.MakeCode & 0x7f, ((keyboard.Flags & RI_KEY_E0) ? 0xe0 : ((keyboard.Flags & RI_KEY_E1) ? 0xe1 : 0x00)));
        }
        else
        {
            // Scan code value may be empty for some buttons (for example multimedia buttons)
            // Try to get the scan code from the virtual key code
            scanCode = LOWORD(MapVirtualKey(keyboard.VKey, MAPVK_VK_TO_VSC_EX));
        }

        // Get the key name for debug output
        TCHAR keyNameBuffer[MAX_PATH] = {};
        GetKeyNameText((LONG)MAKELPARAM(0, (HIBYTE(scanCode) ? KF_EXTENDED : 0x00) | LOBYTE(scanCode)), keyNameBuffer, MAX_PATH);

        // Debug output
        TCHAR printBuffer[MAX_PATH] = {};
        StringCchPrintf(printBuffer, MAX_PATH, TEXT("Keyboard: scanCode=%04x keyName=%s\r\n"), scanCode, keyNameBuffer);
        OutputDebugString(printBuffer);
    }
    ...

    return 0;
}
```

## See also

- [GetRawInputDeviceInfo](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getrawinputdeviceinfow)
- [RAWINPUT](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-rawinput)
- [Raw Input](https://learn.microsoft.com/windows/win32/inputdev/raw-input)
- [Keyboard and mouse HID client drivers](https://learn.microsoft.com/windows-hardware/drivers/hid/keyboard-and-mouse-hid-client-drivers)
- [KEYBOARD_INPUT_DATA structure](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_input_data)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)