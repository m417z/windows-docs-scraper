# OPEN_PRINTER_PROPS_INFOA structure

## Description

Identifies a particular property sheet in a printer's property pages and whether that property sheet should be modal. Optionally used with the [SHInvokePrinterCommand](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shinvokeprintercommanda) function.

## Members

### `dwSize`

Type: **DWORD**

The size of the structure.

### `pszSheetName`

Type: **LPSTR**

The name of the property sheet. If the specified sheet is not found, the property sheet still appears with the default first page.

### `uSheetIndex`

Type: **UINT**

The index of the property sheet in the array of property sheets that makes up the window. If empty or invalid, the default first page is displayed.

### `dwFlags`

Type: **DWORD**

Not used.

### `bModal`

Type: **BOOL**

**TRUE** if the property sheet should be modal; otherwise, **FALSE**.

## Remarks

This structure can be passed in the *lpBuf2* parameter of the [SHInvokePrinterCommand](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shinvokeprintercommanda) function when that function's *uAction* parameter is set to PRINTACTION_PROPERTIES.

> [!NOTE]
> The shellapi.h header defines OPEN_PRINTER_PROPS_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).