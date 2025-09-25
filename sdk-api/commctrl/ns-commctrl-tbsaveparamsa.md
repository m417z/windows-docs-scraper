# TBSAVEPARAMSA structure

## Description

Specifies the location in the registry where the [TB_SAVERESTORE](https://learn.microsoft.com/windows/desktop/Controls/tb-saverestore) message stores and retrieves information about the state of a toolbar.

## Members

### `hkr`

Type: **[HKEY](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the registry key.

### `pszSubKey`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Subkey name.

### `pszValueName`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value name.

## Remarks

> [!NOTE]
> The commctrl.h header defines TBSAVEPARAMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).