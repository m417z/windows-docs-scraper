# EngSetPrinterData function

## Description

The **EngSetPrinterData** function is obsolete in Windows 2000 and later.

In earlier versions of Windows **EngSetPrinterData**  sets the configuration data for the specified printer.

## Parameters

### `hPrinter` [in]

Handle to the printer for which configuration data should be set. This is the handle that is passed as the *hDriver* parameter of [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev). See **Remarks**.

### `pType` [in]

Pointer to a null-terminated string that identifies the data to be set.

### `dwType` [in]

Is a flag that specifies the type of information to be set. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| REG_BINARY | Binary data in any form. |
| REG_DWORD | A 32-bit number. |
| REG_DWORD_BIG_ENDIAN | A 32-bit number in big-endian format, meaning that the most significant byte of a word is the low-order byte. |
| REG_DWORD_LITTLE_ENDIAN | A 32-bit number in little-endian format (same as REG_DWORD), meaning that the most significant byte of a word is the high-order byte |
| REG_EXPAND_SZ | A null-terminated string that contains unexpanded references to environment variables (for example, "%PATH%"). It will be a Unicode or ANSI string depending on whether Unicode or ANSI functions are used. |
| REG_LINK | A Unicode symbolic link. |
| REG_MULTI_SZ | An array of null-terminated strings, terminated by two null characters. |
| REG_NONE | No defined value type. |
| REG_RESOURCE_LIST | A device-driver resource list. |
| REG_SZ | A null-terminated string. It will be a Unicode or ANSI string depending on whether you use the Unicode or ANSI functions. |

### `lpbPrinterData` [in]

Pointer to the printer configuration data that is to be set. The type of data pointed to is determined by *dwType*.

### `cjPrinterData` [in]

Specifies the size, in bytes, of *lpbPrinterData*.

## Return value

**EngSetPrinterData** returns the last logged error message.

## Remarks

Beginning with Microsoft Windows 2000, this function is obsolete. The handles used in calls to the **EngSetPrinterData** and *DrvEnablePDEV* functions have different access rights; hence these functions no longer work together. The *hDriver* parameter used in calls to the *DrvEnablePDEV* function is opened with the PRINTER_ACCESS_USE access right. In contrast, the *hPrinter* parameter used in calls to the **EngSetPrinterData** function must have been opened with the PRINTER_ALL_ACCESS access right. As a result, there is no way for a kernel-mode printer driver (the only type of printer driver that can call **EngSetPrinterData**) to use **EngSetPrinterData** to write information about a printer to the registry.

For more information about printer access rights, see the PRINTER_DEFAULTS structure (described in the Windows SDK documentation).

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngGetPrinterData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetprinterdata)