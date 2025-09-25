# keybd_event function

## Description

Synthesizes a keystroke. The system can use such a synthesized keystroke to generate a [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup) or [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) message. The keyboard driver's interrupt handler calls the **keybd_event** function.

**Note** This function has been superseded. Use [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) instead.

## Parameters

### `bVk` [in]

Type: **BYTE**

A virtual-key code. The code must be a value in the range 1 to 254. For a complete list, see [Virtual Key Codes](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes).

### `bScan` [in]

Type: **BYTE**

A hardware scan code for the key.

### `dwFlags` [in]

Type: **DWORD**

Controls various aspects of function operation. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **KEYEVENTF_EXTENDEDKEY**<br><br>0x0001 | If specified, the scan code was preceded by a prefix byte having the value 0xE0 (224). |
| **KEYEVENTF_KEYUP**<br><br>0x0002 | If specified, the key is being released. If not specified, the key is being depressed. |

### `dwExtraInfo` [in]

Type: **ULONG_PTR**

An additional value associated with the key stroke.

## Remarks

An application can simulate a press of the PRINTSCRN key in order to obtain a screen snapshot and save it to the clipboard. To do this, call **keybd_event** with the
*bVk* parameter set to **VK_SNAPSHOT**.

#### Examples

The following sample program toggles the NUM LOCK light by using **keybd_event** with a virtual key of **VK_NUMLOCK**. It takes a Boolean value that indicates whether the light should be turned off (**FALSE**) or on (**TRUE**). The same technique can be used for the CAPS LOCK key (**VK_CAPITAL**) and the SCROLL LOCK key (**VK_SCROLL**).

```

   #include <windows.h>

   void SetNumLock( BOOL bState )
   {
      BYTE keyState[256];

      GetKeyboardState((LPBYTE)&keyState);
      if( (bState && !(keyState[VK_NUMLOCK] & 1)) ||
          (!bState && (keyState[VK_NUMLOCK] & 1)) )
      {
      // Simulate a key press
         keybd_event( VK_NUMLOCK,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( VK_NUMLOCK,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
      }
   }

   void main()
   {
      SetNumLock( TRUE );
   }

```

## See also

- [GetAsyncKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getasynckeystate)
- [GetKeyState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeystate)
- [GetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getkeyboardstate)
- [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)
- [MapVirtualKey](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapvirtualkeya)
- [SetKeyboardState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setkeyboardstate)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)