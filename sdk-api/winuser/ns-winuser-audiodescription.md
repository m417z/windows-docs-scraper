# AUDIODESCRIPTION structure

## Description

Contains information associated with audio descriptions. This structure is used with the
[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function when the SPI_GETAUDIODESCRIPTION or SPI_SETAUDIODESCRIPTION action value is specified.

## Members

### `cbSize`

The size of the structure, in bytes. The caller must set this member to `sizeof(AUDIODESCRIPTION)`.

### `Enabled`

If this member is **TRUE**, audio descriptions are enabled; Otherwise, this member is **FALSE**.

### `Locale`

The locale identifier (LCID) of the language for the audio description. For more information, see
[Locales and Languages](https://learn.microsoft.com/windows/desktop/Intl/locales-and-languages).

## Remarks

To compile an application that uses this structure, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)