# HIGHCONTRASTW structure

## Description

Contains information about the high contrast accessibility feature.This feature sets the appearance scheme of the user interface for maximum visibility for a visually-impaired user, and advises applications to comply with this appearance scheme.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of this structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a combination of the following values:

| Value | Meaning |
| --- | --- |
| **HCF_HIGHCONTRASTON**<br><br>0x00000001 | The high contrast feature is on. |
| **HCF_AVAILABLE**<br><br>0x00000002 | The high contrast feature is available. |
| **HCF_HOTKEYACTIVE**<br><br>0x00000004 | The user can turn the high contrast feature on and off by simultaneously pressing the left ALT, left SHIFT, and PRINT SCREEN keys. |
| **HCF_CONFIRMHOTKEY**<br><br>0x00000008 | A confirmation dialog appears when the high contrast feature is activated by using the hot key. |
| **HCF_HOTKEYSOUND**<br><br>0x00000010 | A siren is played when the user turns the high contrast feature on or off by using the hot key. |
| **HCF_INDICATOR**<br><br>0x00000020 | A visual indicator is displayed when the high contrast feature is on. This value is not currently used and is ignored. |
| **HCF_HOTKEYAVAILABLE**<br><br>0x00000040 | The hot key associated with the high contrast feature can be enabled. An application can retrieve this value, but cannot set it. |
| **HCF_OPTION_NOTHEMECHANGE**<br><br>0x00001000 | Passing HIGHCONTRASTSTRUCTURE in calls to SystemParametersInfoW can cause theme change effects even if the theme isn't being changed. For example, the WM_THEMECHANGED message is sent to Windows even if the only change is to HCF_HOTKEYSOUND.<br><br>To prevent this, include the HCF_OPTION_NOTHEMECHANGE flag in the call to SystemParametersInfo.<br><br>> [!NOTE] > The HCF_OPTION_NOTHEMECHANGE flag should not be used when toggling the high contrast mode (HCF_HIGHCONTRASTON). |
| **HCF_OPTION_NOTHEMECHANGE**<br><br>0x00001000 | Passing HIGHCONTRASTSTRUCTURE in calls to SystemParametersInfoW can cause theme change effects even if the theme isn't being changed. For example, the WM_THEMECHANGED message is sent to Windows even if the only change is to HCF_HOTKEYSOUND.<br><br>To prevent this, include the HCF_OPTION_NOTHEMECHANGE flag in the call to SystemParametersInfo.<br><br>> [!NOTE] > The HCF_OPTION_NOTHEMECHANGE flag should not be used when toggling the high contrast mode (HCF_HIGHCONTRASTON). |

### `lpszDefaultScheme`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Points to a string that contains the name of the color scheme that will be set to the default scheme. The system allocates this buffer, free it with LocalFree.

## Remarks

An application uses this structure when calling the [SystemParametersInfoW function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfow) with the **SPI_GETHIGHCONTRAST** or **SPI_SETHIGHCONTRAST** value. When using **SPI_GETHIGHCONTRAST**, an application must specify the **cbSize** member of the **HIGHCONTRAST** structure; the **SystemParametersInfo** function fills the remaining members. An application must specify all structure members when using the **SPI_SETHIGHCONTRAST** value.

> [!NOTE]
> The winuser.h header defines HIGHCONTRAST as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SystemParametersInfoW function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfow), [HIGHCONTRASTA structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-highcontrasta), [Accessibility Structures](https://learn.microsoft.com/windows/desktop/WinAuto/accessibility-structures),
[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)