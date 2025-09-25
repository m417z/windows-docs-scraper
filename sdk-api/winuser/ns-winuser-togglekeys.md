# TOGGLEKEYS structure

## Description

Contains information about the ToggleKeys accessibility feature. When the ToggleKeys feature is on, the computer emits a high-pitched tone whenever the user turns on the CAPS LOCK, NUM LOCK, or SCROLL LOCK key, and a low-pitched tone whenever the user turns off one of those keys.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of this structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags that specify properties of the ToggleKeys feature. The following bit flag values are defined:

| Value | Meaning |
| --- | --- |
| **TKF_AVAILABLE**<br><br>0x00000002 | If this flag is set, the ToggleKeys feature is available. |
| **TKF_CONFIRMHOTKEY**<br><br>0x00000008 | **Windows 95/98, Windows 2000:** A confirmation dialog box appears when the ToggleKeys feature is activated by using the hot key. |
| **TKF_HOTKEYACTIVE**<br><br>0x00000004 | If this flag is set, the user can turn the ToggleKeys feature on and off by holding down the NUM LOCK key for eight seconds. |
| **TKF_HOTKEYSOUND**<br><br>0x00000010 | If this flag is set, the system plays a siren sound when the user turns the ToggleKeys feature on or off by using the hot key. |
| **TKF_INDICATOR**<br><br>0x00000020 | This flag is not implemented. |
| **TKF_TOGGLEKEYSON**<br><br>0x00000001 | If this flag is set, the ToggleKeys feature is on. |

## Remarks

An application uses a **TOGGLEKEYS** structure when calling the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the *uiAction* parameter set to **SPI_GETTOGGLEKEYS** or **SPI_SETTOGGLEKEYS**. When using SPI_GETTOGGLEKEYS, an application must specify the **cbSize** member of the **TOGGLEKEYS** structure; the **SystemParametersInfo** function fills the remaining members. An application must specify all structure members when using the **SPI_SETTOGGLEKEYS** value.

## See also

[Accessibility Structures](https://learn.microsoft.com/windows/desktop/WinAuto/accessibility-structures)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)