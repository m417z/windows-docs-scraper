# EngGetPrinterData function

## Description

The **EngGetPrinterData**  function retrieves configuration data for the specified printer.

## Parameters

### `hPrinter` [in]

Handle to the printer for which configuration data should be retrieved. This is the handle that is passed as the *hDriver* parameter of [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `pValueName` [in]

Pointer to a null-terminated string that identifies the data to be retrieved.

### `pType` [out, optional]

Pointer to a variable that receives the data type stored by [EngSetPrinterData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetprinterdata). This parameter can be **NULL**.

### `pData` [out, optional]

Pointer to an array of bytes in which the configuration data is written.

### `nSize` [in]

Specifies the size, in bytes, of *pData*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the number of bytes copied into *lpbData* if the function succeeds. This parameter receives the number of bytes required if *nSizef* is too small.

## Return value

**EngGetPrinterData** returns the last logged error message.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngSetPrinterData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetprinterdata)