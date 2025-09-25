# IPrintOemPS::ResetPDEV

## Description

The `IPrintOemPS::ResetPDEV` method allows a rendering plug-in for Pscript5 to reset its PDEV structure.

## Parameters

### `pdevobjOld`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure containing current PDEV information.

### `pdevobjNew`

Caller-supplied pointer to a DEVOBJ structure into which the method should place new PDEV information.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

If the operation fails it should call **SetLastError**.

## Remarks

A rendering plug-in's `IPrintOemPS::ResetPDEV` method performs the same types of operations as the [DrvResetPDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvresetpdev) function that is exported by a printer graphics DLL. During the processing of an application's call to the Microsoft Windows SDK **ResetDC** function, the `IPrintOemPS::ResetPDEV` method is called by the **DrvResetPDEV** function in Pscript5's printer graphics DLL. For more information about when **DrvResetPDEV** is called, see its description.

The rendering plug-in's private PDEV structure's address is contained in the **pdevOEM** member of the DEVOBJ structure pointed to by *pdevobjOld*. The `IPrintOemPS::ResetPDEV` method should use relevant members of this old structure to fill in the new structure, which is referenced through *pdevobjNew*.