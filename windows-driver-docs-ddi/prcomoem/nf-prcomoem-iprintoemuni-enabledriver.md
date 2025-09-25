## Description

The **IPrintOemUni::EnableDriver** method allows a rendering plug-in for [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/print/microsoft-universal-printer-driver) to hook out some graphics DDI functions.

## Parameters

### `DriverVersion`

Caller-supplied interface version number. This value is defined by PRINTER_OEMINTF_VERSION, in printoem.h.

### `cbSize`

Caller-supplied size, in bytes, of the structure pointed to by *pded*.

### `pded`

Caller-supplied pointer to a [DRVENABLEDATA](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-drvenabledata) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
|---|---|
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |

## Remarks

A rendering plug-in for Unidrv must implement the **IPrintOemUni::EnableDriver** method.

The **IPrintOemUni::EnableDriver** method allows a rendering plug-in to perform the same types of operations as the [DrvEnableDriver](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenabledriver) function that is exported by printer graphics DLLs.

Like the **DrvEnableDriver** function, the **IPrintOemUni::EnableDriver** method is responsible for providing addresses of internally supported graphics DDI functions, known as hooking functions. It can also perform other one-time initialization operations. Unlike the **DrvEnableDriver** function, implementation of **IPrintOemUni::EnableDriver** is optional.

If you implement **IPrintOemUni::EnableDriver**, you must also implement [IPrintOemUni::DisableDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-disabledriver). Actions begun in the former method might need to be completed in the latter method. For example, if a large buffer is allocated in **IPrintOemUni::EnableDriver**, but not deallocated in **IPrintOemUni::DisableDriver**, a memory leak can occur.

The method should fill the supplied [DRVENABLEDATA](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-drvenabledata) structure and allocate an array of [DRVFN](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-drvfn) structures. It should fill the array with pointers to hooking functions, along with winddi.h-defined index values that identify the hooked out graphics DDI functions.

A rendering plug-in for Unidrv can hook out a graphics DDI function only if the Unidrv driver defines the function. The following graphics DDI functions are defined in Unidrv and/or Pscript5 and can therefore be hooked out:

- [DrvAlphaBlend](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvalphablend)

- [DrvBitBlt](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvbitblt)

- [DrvCopyBits](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvcopybits)

- [DrvDitherColor](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvdithercolor)

- [DrvEndDoc](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenddoc)

- [DrvEscape](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvescape)

- [DrvFillPath](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvfillpath)

- [DrvFontManagement](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvfontmanagement)

- [DrvGetGlyphMode](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetglyphmode)

- [DrvGradientFill](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgradientfill)

- [DrvIcmCreateColorTransform](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvicmcreatecolortransform)

- [DrvIcmDeleteColorTransform](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvicmdeletecolortransform)

- [DrvLineTo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvlineto)

- [DrvNextBand](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvnextband)

- [DrvPlgBlt](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvplgblt)

- [DrvQueryAdvanceWidths](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvqueryadvancewidths)

- [DrvQueryDeviceSupport](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvquerydevicesupport)

- [DrvQueryFont](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvqueryfont)

- [DrvQueryFontData](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvqueryfontdata)

- [DrvQueryFontTree](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvqueryfonttree)

- [DrvRealizeBrush](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvrealizebrush)

- [DrvSendPage](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvsendpage)

- [DrvStartBanding](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstartbanding)

- [DrvStartDoc](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstartdoc)

- [DrvStartPage](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstartpage)

- [DrvStretchBlt](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstretchblt)

- [DrvStretchBltROP](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstretchbltrop)

- [DrvStrokeAndFillPath](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstrokeandfillpath)

- [DrvStrokePath](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvstrokepath)

- [DrvTextOut](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvtextout)

- [DrvTransparentBlt](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvtransparentblt)

If you provide a customized hooking function, it preempts the driver's equivalent graphics DDI function. Hooking functions can also call back into the driver's graphics DDI functions. For more information see [Customized Graphics DDI Functions](https://learn.microsoft.com/windows-hardware/drivers/print/customized-graphics-ddi-functions).

Customized hooking functions have the same input and output parameters as the equivalent graphics DDI function, with one exception - where graphics DDI functions receive PDEV pointers, customized hooking functions receive [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) pointers. There are two ways for graphics DDI functions to receive PDEV pointers:

- As the contents of the **dhpdev** member of a [SURFOBJ](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-surfobj) structure for the destination surface. For the equivalent customized hooking function, the destination SURFOBJ structure's **dhpdev** member points to a DEVOBJ structure, and must be cast to type PDEVOBJ when referenced. An example graphics DDI function is **DrvBitBlt**.

- As an input argument for a *dhpdev* parameter. The equivalent customized hooking function must cast this input parameter to type PDEVOBJ when referencing it. An example graphics DDI function is **DrvDitherColor**.

Note that while a [printer graphics DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) includes the addresses of its [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev), [DrvDisablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvdisablepdev), and [DrvResetPDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvresetpdev) functions in the DRVENABLEDATA structure, a rendering plug-in explicitly exports **EnablePDEV**, **DisablePDEV**, and **ResetPDEV** as methods of the **IPrintOemUni** interface and does not place their addresses in the DRVENABLEDATA structure.

If **IPrintOemUni::EnableDriver** methods are exported by multiple rendering plug-ins, the methods are called in the order that the plug-ins are specified for installation.

Each graphics DDI function can be hooked out by only one rendering plug-in. If multiple plug-ins attempt to hook out the same graphics DDI function, all hook-outs after the first one are ignored.

For more information about creating and installing rendering plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).