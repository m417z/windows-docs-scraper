# FILTERKEYS structure

## Description

Contains information about the FilterKeys accessibility feature, which enables a user with disabilities to set the keyboard repeat rate (RepeatKeys), acceptance delay (SlowKeys), and bounce rate (BounceKeys).

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the structure size, in bytes.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags that specify properties of the FilterKeys feature. The following bit-flag values are defined:

| Value | Meaning |
| --- | --- |
| **FKF_AVAILABLE**<br><br>0x00000002 | The FilterKeys features are available. |
| **FKF_CLICKON**<br><br>0x00000040 | The computer makes a click sound when a key is pressed or accepted. If SlowKeys is on, a click is generated when the key is pressed and again when the keystroke is accepted. |
| **FKF_CONFIRMHOTKEY**<br><br>0x00000008 | **Windows 95/98, Windows 2000:** A confirmation dialog box appears when the FilterKeys features are activated by using the hot key. |
| **FKF_FILTERKEYSON**<br><br>0x00000001 | The FilterKeys features are on. |
| **FKF_HOTKEYACTIVE**<br><br>0x00000004 | The user can turn the FilterKeys feature on and off by holding down the RIGHT SHIFT key for eight seconds. |
| **FKF_HOTKEYSOUND**<br><br>0x00000010 | If this flag is set, the computer plays a siren sound when the user turns the FilterKeys feature on or off by using the hot key. |
| **FKF_INDICATOR**<br><br>0x00000020 | **Windows 95, Windows 2000:** A visual indicator is displayed when the FilterKeys features are on. |

### `iWaitMSec`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of time, in milliseconds, that the user must hold down a key before it is accepted by the computer.

### `iDelayMSec`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of time, in milliseconds, that the user must hold down a key before it begins to repeat.

### `iRepeatMSec`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of time, in milliseconds, between each repetition of the keystroke.

### `iBounceMSec`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of time, in milliseconds, that must elapse after releasing a key before the computer will accept a subsequent press of the same key.

## Remarks

Use a **FILTERKEYS** structure when calling the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the *uiAction* parameter set to the **SPI_GETFILTERKEYS** or **SPI_SETFILTERKEYS** value. When using **SPI_GETFILTERKEYS**, you must specify the **cbSize** member of the **FILTERKEYS** structure; the **SystemParametersInfo** function fills the remaining members. Specify all structure members when using the **SPI_SETFILTERKEYS** value.

The **iBounceMSec** member controls the BounceKeys feature, and the **iWaitMSec**, **iDelayMSec**, and **iRepeatMSec** members work together to control the RepeatKeys and SlowKeys features. If BounceKeys is on (that is, **iBounceMSec** is nonzero), the RepeatKeys and SlowKeys features are off (that is, the **iWaitMSec**, **iDelayMSec**, and **iRepeatMSec** members must all be zero). Similarly, if BounceKeys is off (**iBounceMSec** is zero), the **iWaitMSec**, **iDelayMSec**, and **iRepeatMSec** must all be nonzero.

The maximum value of the **iBounceMSec**, **iWaitMSec**, **iDelayMSec**, and **iRepeatMSec** members is 20,000 milliseconds.

## See also

[Accessibility Structures](https://learn.microsoft.com/windows/desktop/WinAuto/accessibility-structures)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)