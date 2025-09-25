# EngGetPrinterDriver function

## Description

The **EngGetPrinterDriver** function retrieves driver data for the specified printer.

## Parameters

### `hPrinter` [in]

Handle to the printer for which the driver data should be retrieved.

### `pEnvironment` [in, optional]

Pointer to a null-terminated string that specifies the environment. For example, "Windows NT x86" specifies an NT-based operating system running on an Intel processor. If *pEnvironment* is **NULL**, the current environment of the calling driver and client machine is used.

### `dwLevel` [in]

Specifies the version of the structure to which *lpbDrvInfo* points. This parameter must be one of the following values:

| Value | Meaning |
| --- | --- |
| 1 | GDI writes a DRIVER_INFO_1 structure in the buffer to which *lpbDrvInfo* points. |
| 2 | GDI writes a DRIVER_INFO_2 structure in the buffer to which *lpbDrvInfo* points. |
| 3 | GDI writes a DRIVER_INFO_3 structure in the buffer to which *lpbDrvInfo* points. |

### `lpbDrvInfo` [out, optional]

Pointer to a buffer in which GDI places the requested DRIVER_INFO_*X* structure.

### `cbBuf` [in]

Specifies the size, in bytes, of the buffer to which *lpbDrvInfo* points.

### `pcbNeeded` [out]

Pointer to a memory location in which GDI places the number of bytes copied into the buffer to which *lpbDrvInfo* points upon success, or the number of bytes required if *cbBuf* is too small.

## Return value

**EngGetPrinterDriver** returns **TRUE** upon success; otherwise it reports an error and returns **FALSE**.

## Remarks

A printer driver DLL can work with multiple data files to support different printer models. The printer driver calls **EngGetPrinterDriver** to determine which data file to use. For example, the Unidrv renderer calls this function to determine the name of a [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file, and the postscript driver calls this function to determine the name of a [PPD](https://learn.microsoft.com/windows-hardware/drivers/) file. The DRIVER_INFO_2 and DRIVER_INFO_3 structures contain a full path and file name specifying the location of the data file. The printer driver can then use the returned path and file name to load the data file by calling [EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule) with the path and file name as a single argument.

The DRIVER_INFO_*X* structures are described in the Microsoft Windows SDK documentation.

## See also

[EngLoadModule](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadmodule)