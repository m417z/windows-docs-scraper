## Description

The **DEVOBJ** structure is used as an input argument to several of a rendering plug-in's COM interface methods.

## Members

### `dwSize`

Specifies the size, in bytes, of the **DEVOBJ** structure. Supplied by the Unidrv or Pscript5 driver.

### `pdevOEM`

Pointer to the rendering plug-in's private PDEV structure, as returned by [IPrintOemUni::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-enablepdev) or [IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev). Supplied by the Unidrv or Pscript5 driver.

### `hEngine`

GDI handle to the physical device. This handle is received by the printer driver's [DrvCompletePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvcompletepdev) function, as the function's *hdev* argument.

### `hPrinter`

Spooler's handle to the printer. This handle is received by the printer driver's [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev) function, as the function's *hDriver* argument.

### `hOEM`

Plug-in instance handle. Supplied by the Unidrv or Pscript5 driver.

### `pPublicDM`

Pointer to the printer's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. Supplied by the Unidrv or Pscript5 driver.

### `pOEMDM`

Pointer to the rendering plug-in's private DEVMODEW structure members. Supplied by the Unidrv or Pscript5 driver.

### `pDrvProcs`

 Not used. In a previous version of the interface, this was a pointer to a [DRVPROCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_drvprocs) structure.

## Remarks

The **DEVOBJ** structure is accessible to graphics DDI hooking functions through the [SURFOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-surfobj) structure's **dhpdev** member. For more information, see [IPrintOemUni::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-enablepdev) or [IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev).

## See also

[DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[DrvCompletePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvcompletepdev)

[DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev)

[IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev)

[IPrintOemUni::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-enablepdev)

[SURFOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-surfobj)