# DrvConvertDevMode function

## Description

A printer interface DLL's **DrvConvertDevMode** function converts a printer's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure from one version to another.

## Parameters

### `pPrinterName` [in]

Caller-supplied pointer to a printer name string. For more information about this parameter, see the following Remarks section.

### `pdmIn` [in]

Caller-supplied pointer to an input DEVMODEW structure. If *fMode* is CDM_DRIVER_DEFAULT, this pointer is **NULL**.

### `pdmOut` [out]

Caller-supplied pointer to a buffer to receive an output DEVMODEW structure. If *fMode* is CDM_CONVERT the buffer contains, on input, a valid DEVMODEW structure indicating the target driver version.

### `pcbNeeded` [in, out]

Caller-supplied pointer to the size, in bytes, of the buffer pointed to by *pdmOut*. On output, the printer interface DLL should overwrite the received size value with the actual size of the converted DEVMODEW structure. If the received buffer is too small, the printer interface DLL should overwrite the received size value with the required buffer size.

### `fMode` [in]

Caller-supplied bit flag indicating the type of operation to be performed. This can be one of the following flags:

#### CDM_CONVERT

The function should convert the contents of the input DEVMODEW structure (pointed to by *pdmIn*) into a new DEVMODEW structure, and place the result in the DEVMODEW structure pointed to by *pdmOut*. The initial contents of the received output DEVMODEW structure (pointed to by *pdmOut*) should be used to determine the output version.

#### CDM_CONVERT351

The function should convert the contents of the input DEVMODEW structure (pointed to by *pdmIn*), creating an output DEVMODEW structure that is compatible with Windows NT 3.51, and place the result in the DEVMODEW structure pointed to by *pdmOut*.

If the driver does not support a DEVMODEW structure for Windows NT 3.51, the function should convert the input DEVMODEW to the current version.

#### CDM_DRIVER_DEFAULT

The function should copy the current version of its default DEVMODEW structure to the buffer pointed to by *pdmOut*.

## Return value

If the operation succeeds, the function should return **TRUE**; otherwise, it should call SetLastError to set an error code, and return **FALSE**.

## Remarks

In a client/server environment, a client might be running one version of the operating system or printer driver while the server (spooler) is running another, which means a printer's DEVMODEW structure definition might be inconsistent between the client and server. The **DrvConvertDevMode** function must be capable of performing conversions from one version of the printer's DEVMODEW structure to another.

When converting from one DEVMODEW version to another, both public and private DEVMODEW members must be included.

The printer name pointed to by *pPrinterName* can be used as an input argument to the **OpenPrinter** function (described in the Microsoft Windows SDK documentation), which can be called to obtain stored default values when the CDM_DRIVER_DEFAULT flag is received. Note that the printer name string must be not be modified in any way prior to a call to **OpenPrinter**. In addition, a call to **OpenPrinter** must be in the same thread as was used to call **DrvConvertDevMode**.

The function should verify that both *pdmIn* and *pdmOut* (if applicable) point to valid DEVMODEW structures. If they do not, the function should call SetLastError(ERROR_INVALID_PARAMETER) and return **FALSE**. If the output DEVMODEW size specified by *pcbNeeded* is too small, the driver should overwrite the size value supplied by *pcbNeeded* with the required buffer size, call SetLastError(ERROR_INSUFFICIENT_BUFFER), and return **FALSE**.

The **DrvConvertDevMode** function runs in the spooler's context and must therefore not display a user interface.

When **DrvConvertDevMode** is called with a **NULL** DEVMODEW structure pointer in the *pdmOut* parameter to get the buffer size, the driver is expected to set the last error to ERROR_INSUFFICIENT_BUFFER. If the last error is not set to this value, the spooler assumes a general error.