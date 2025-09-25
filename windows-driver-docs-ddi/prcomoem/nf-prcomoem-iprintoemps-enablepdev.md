# IPrintOemPS::EnablePDEV

## Description

The `IPrintOemPS::EnablePDEV` method allows a rendering plug-in for Pscript5 to create its own PDEV structure.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pPrinterName`

Caller-supplied pointer to a text string representing the logical address of the printer.

### `cPatterns`

Caller-supplied value representing the number of HSURF-typed surface handles contained in the buffer pointed to by *phsurfPatterns*.

### `phsurfPatterns`

Caller-supplied pointer to a buffer that is large enough to contain *cPatterns* number of HSURF-typed surface handles. The handles represent surface fill patterns.

### `cjGdiInfo`

Caller-supplied value representing the size of the structure pointed to by *pGdiInfo*.

### `pGdiInfo`

Caller-supplied pointer to a [GDIINFO](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-gdiinfo) structure.

### `cjDevInfo`

Caller-supplied value representing the size of the structure pointed to by *pDevInfo*.

### `pDevInfo`

Caller-supplied pointer to a [DEVINFO](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-devinfo) structure.

### `pded`

Caller-supplied pointer to a [DRVENABLEDATA](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-drvenabledata) structure containing the addresses of the printer driver's graphics DDI hooking functions. For more information, see the following Remarks section.

### `pDevOem` [out]

Receives a method-supplied pointer to a private PDEV structure. (For more information, see the following Remarks section.)

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

If the operation fails, the method should call **SetLastError** to set an error code.

## Remarks

The `IPrintOemPS::EnablePDEV` method performs the same types of operations as the [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev) function that is exported by a printer graphics DLL. Its purpose is to allow a rendering plug-in to create its own PDEV structure. (For more information about PDEV structures, see [Customized PDEV Structures](https://learn.microsoft.com/windows-hardware/drivers/print/customized-pdev-structures).)

If you provide a rendering plug-in that exports the `IPrintOemPS::EnablePDEV` method, Pscript5's printer graphics DLL calls the method from within its [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev) function.

The `IPrintOemPS::EnablePDEV` method should allocate an instance of its private PDEV structure, initialize it, and return its address as the method's *pDevOem* parameter. Other plug-in methods receive the address as the **pdevOEM** member of the [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

The **pdevOEM** member of the DEVOBJ structure is not used with the `IPrintOemPS::EnablePDEV` method.

The structures pointed to by the *phsurfPatterns*, *pGdiInfo*, and *pDevInfo* parameter values are the same ones that Pscript5's **DrvEnablePDEV** function receives. The rendering plug-in can modify the structure contents as necessary. It can supply surface fill patterns by obtaining HSURF-typed surface handles and placing them in the buffer pointed to by *phsurfPatterns*. Fill pattern types and handle order are listed in the description of [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev).

The [DRVENABLEDATA](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-drvenabledata) structure pointed to by *pded* contains the addresses of graphics DDI functions provided by Pscript5's printer graphics DLL. You are allowed to provide customized hooking functions in your plug-in for these graphics DDI functions. The DRVENABLEDATA structure's contents enable your customized hooking functions to call back to the driver's graphics DDI functions. For more information, see [Customized Graphics DDI Functions](https://learn.microsoft.com/windows-hardware/drivers/print/customized-graphics-ddi-functions).