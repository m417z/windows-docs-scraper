# IPrintOemPS::DisablePDEV

## Description

The `IPrintOemPS::DisablePDEV` method allows a rendering plug-in for Pscript5 to delete the private PDEV structure that was allocated by its [IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev) method.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemPS::DisablePDEV` method performs the same types of operations as the [DrvDisablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvdisablepdev) function that is exported by a printer graphics DLL. Its purpose is to allow a rendering plug-in to delete the private PDEV structure that is pointed to by the DEVOBJ structure's **pdevOEM** member. This PDEV structure is one that was allocated by the plug-in's [IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev) method.