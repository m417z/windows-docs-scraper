# STICKYKEYS structure

## Description

Contains information about the StickyKeys accessibility feature. When the StickyKeys feature is on, the user can press a modifier key (SHIFT, CTRL, or ALT) and then another key in sequence rather than at the same time, to enter shifted (modified) characters and other key combinations. Pressing a modifier key once *latches* the key down until the user presses a non-modifier key or clicks a mouse button. Pressing a modifier key twice *locks* the key until the user presses the key a third time.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of this structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit-flags that specify properties of the StickyKeys feature. The following bit-flag values are defined:

| Value | Meaning |
| --- | --- |
| **SKF_AUDIBLEFEEDBACK**<br><br>0x00000040 | If this flag is set, the system plays a sound when the user latches, locks, or releases modifier keys using the StickyKeys feature. |
| **SKF_AVAILABLE**<br><br>0x00000002 | If this flag is set, the StickyKeys feature is available. |
| **SKF_CONFIRMHOTKEY**<br><br>0x00000008 | **Windows 95/98, Windows 2000:** A confirmation dialog appears when the StickyKeys feature is activated by using the hot key. |
| **SKF_HOTKEYACTIVE**<br><br>0x00000004 | If this flag is set, the user can turn the StickyKeys feature on and off by pressing the SHIFT key five times. |
| **SKF_HOTKEYSOUND**<br><br>0x00000010 | If this flag is set, the system plays a siren sound when the user turns the StickyKeys feature on or off by using the hot key. |
| **SKF_INDICATOR**<br><br>0x00000020 | **Windows 95/98, Windows 2000:** A visual indicator should be displayed when the StickyKeys feature is on. |
| **SKF_STICKYKEYSON**<br><br>0x00000001 | If this flag is set, the StickyKeys feature is on. |
| **SKF_TRISTATE**<br><br>0x00000080 | If this flag is set, pressing a modifier key twice in a row locks down the key until the user presses it a third time. |
| **SKF_TWOKEYSOFF**<br><br>0x00000100 | If this flag is set, releasing a modifier key that has been pressed in combination with any other key turns off the StickyKeys feature. |
| **SKF_LALTLATCHED**<br><br>0x10000000 | **Windows 98, Windows 2000:** The left ALT key is latched. |
| **SKF_LCTLLATCHED**<br><br>0x04000000 | **Windows 98, Windows 2000:**  The left CTRL key is latched. |
| **SKF_LSHIFTLATCHED**<br><br>0x01000000 | **Windows 98, Windows 2000:**  The left SHIFT key is latched. |
| **SKF_RALTLATCHED**<br><br>0x20000000 | **Windows 98, Windows 2000:**  The right ALT key is latched. |
| **SKF_RCTLLATCHED**<br><br>0x08000000 | **Windows 98, Windows 2000:**  The right CTRL key is latched. |
| **SKF_RSHIFTLATCHED**<br><br>0x02000000 | **Windows 98, Windows 2000:**  The right SHIFT key is latched. |
| **SKF_LALTLOCKED**<br><br>0x00100000 | **Windows 98, Windows 2000:**  The left ALT key is locked. |
| **SKF_LCTLLOCKED**<br><br>0x00040000 | **Windows 98, Windows 2000:**  The left CTRL key is locked. |
| **SKF_LSHIFTLOCKED**<br><br>0x00010000 | **Windows 98, Windows 2000:**  The left SHIFT key is locked. |
| **SKF_RALTLOCKED**<br><br>0x00200000 | **Windows 98, Windows 2000:**  The right ALT key is locked. |
| **SKF_RCTLLOCKED**<br><br>0x00080000 | **Windows 98, Windows 2000:**  The right CTRL key is locked. |
| **SKF_RSHIFTLOCKED**<br><br>0x00020000 | **Windows 98, Windows 2000:**  The right SHIFT key is locked. |
| **SKF_LWINLATCHED**<br><br>0x40000000 | **Windows 98, Windows 2000:**  The left Windows key is latched. |
| **SKF_RWINLATCHED**<br><br>0x80000000 | **Windows 98, Windows 2000:**  The right Windows key is latched. |
| **SKF_LWINLOCKED**<br><br>0x00400000 | **Windows 98, Windows 2000:**  The left Windows key is locked. |
| **SKF_RWINLOCKED**<br><br>0x00800000 | **Windows 98, Windows 2000:**  The right Windows key is locked. |

## Remarks

An application uses a **STICKYKEYS** structure when calling the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the *uiAction* parameter set to **SPI_GETSTICKYKEYS** or **SPI_SETSTICKYKEYS**. When using **SPI_GETSTICKYKEYS**, you must specify the **cbSize** member of the **STICKYKEYS** structure; the **SystemParametersInfo** function fills the remaining members. You must specify all structure members when using the **SPI_SETSTICKYKEYS** value.

If you call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) with the **SPI_SETSTICKYKEYS** value, the following flags are ignored:

* SKF_LALTLATCHED
* SKF_LCTLLATCHED
* SKF_LSHIFTLATCHED
* SKF_RALTLATCHED
* SKF_RCTLLATCHED
* SKF_RSHIFTLATCHED
* SKF_LALTLOCKED
* SKF_LCTLLOCKED
* SKF_LSHIFTLOCKED
* SKF_RALTLOCKED
* SKF_RCTLLOCKED
* SKF_RSHIFTLOCKED

## See also

[Accessibility Structures](https://learn.microsoft.com/windows/desktop/WinAuto/accessibility-structures)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)