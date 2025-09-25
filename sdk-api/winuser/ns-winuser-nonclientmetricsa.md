# NONCLIENTMETRICSA structure

## Description

Contains the scalable metrics associated with the nonclient area of a nonminimized window. This structure is used by the **SPI_GETNONCLIENTMETRICS** and **SPI_SETNONCLIENTMETRICS** actions of
the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function.

## Members

### `cbSize`

The size of the structure, in bytes. The caller must set this to `sizeof(NONCLIENTMETRICS)`. For information about application compatibility, see Remarks.

### `iBorderWidth`

The thickness of the sizing border, in pixels. The default is 1 pixel.

### `iScrollWidth`

The width of a standard vertical scroll bar, in pixels.

### `iScrollHeight`

The height of a standard horizontal scroll bar, in pixels.

### `iCaptionWidth`

The width of caption buttons, in pixels.

### `iCaptionHeight`

The height of caption buttons, in pixels.

### `lfCaptionFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains information about the caption font.

### `iSmCaptionWidth`

The width of small caption buttons, in pixels.

### `iSmCaptionHeight`

The height of small captions, in pixels.

### `lfSmCaptionFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains information about the small caption font.

### `iMenuWidth`

The width of menu-bar buttons, in pixels.

### `iMenuHeight`

The height of a menu bar, in pixels.

### `lfMenuFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains information about the font used in menu bars.

### `lfStatusFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains information about the font used in status bars and tooltips.

### `lfMessageFont`

A [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that contains information about the font used in message boxes.

### `iPaddedBorderWidth`

The thickness of the padded border, in pixels. The default value is 4 pixels. The **iPaddedBorderWidth** and **iBorderWidth** members are combined for both resizable and nonresizable windows in the Windows Aero desktop experience. To compile an application that uses this member, define **_WIN32_WINNT** as 0x0600 or later. For more information, see Remarks.

**Windows Server 2003 and Windows XP/2000:** This member is not supported.

## Remarks

If the **iPaddedBorderWidth** member of the [NONCLIENTMETRICS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-nonclientmetricsa) structure is present, this structure is 4 bytes larger than for an application that is compiled with **_WIN32_WINNT** less than or equal to 0x0502. For more information about conditional compilation, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

**Windows Server 2003 and Windows XP/2000:** If an application that is compiled for Windows Server 2008 or Windows Vista must also run on Windows Server 2003 or Windows XP/2000, use the [GetVersionEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getversionexa) function to check the operating system version at run time and, if the application is running on Windows Server 2003 or Windows XP/2000, subtract the size of the **iPaddedBorderWidth** member from the **cbSize** member of the [NONCLIENTMETRICS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-nonclientmetricsa) structure before calling the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function.

> [!NOTE]
> The winuser.h header defines NONCLIENTMETRICS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)