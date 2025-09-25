# EngGetPrinter function

## Description

The **EngGetPrinter** function retrieves information about the specified printer.

## Parameters

### `hPrinter` [in]

Handle to the printer for which data should be retrieved. This is the handle that is passed as the *hDriver* parameter of [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `dwLevel` [in]

Specifies the version of the structure to which *pPrinter* points. This parameter can have any of the following values:

| Value | Structure Returned via *pPrinter* |
| --- | --- |
| 1 | PRINTER_INFO_1 |
| 2 | PRINTER_INFO_2 |
| 3 | PRINTER_INFO_3 |
| 4 | PRINTER_INFO_4 |
| 5 | PRINTER_INFO_5 |

### `pPrinter` [out, optional]

Pointer to the memory buffer in which the printer information structure, identified by *dwLevel*, is loaded.

### `cbBuf` [in]

Specifies the size, in bytes, of the memory buffer pointed to by *pPrinter*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the number of bytes copied if the function succeeds, or the number of required bytes if *cbBuf* is too small.

## Return value

**EngGetPrinter** returns **TRUE** upon success; otherwise, it logs an error and returns **FALSE**. To get error information, call [EngGetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetlasterror).

## Remarks

The PRINTER_INFO_*X* structures are defined in the Microsoft Windows SDK documentation.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)