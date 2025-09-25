# DrvResetPDEV function

## Description

The **DrvResetPDEV** function allows a graphics driver to transfer the state of the driver from an old [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) structure to a new PDEV structure when a Win32 application calls [ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca).

## Parameters

### `dhpdevOld`

Caller-supplied handle to the original device PDEV structure. This handle was previously provided by the driver as a return value for [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `dhpdevNew`

Caller-supplied handle to the new PDEV structure.

## Return value

This return value is **TRUE** if the function is successful. Otherwise it is **FALSE**, and an error code is logged.

## Remarks

A graphics driver's **DrvResetPDEV** function should be used for modifying the contents of a new PDEV structure, based on the contents of the old (currently in use) PDEV structure.

OpenGL display drivers that need to know about mode changes should implement **DrvResetPDEV**. Otherwise, all other display drivers typically do not need to implement this function.

### Note The following information pertains to printer graphics DLLs.

The function is called as a result of an application's call to the Win32 [ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca) function, which in turn causes GDI to call the driver's [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) to obtain a new PDEV structure. Because the driver can modify a PDEV structure's contents during the rendering of a print job, the **DrvResetPDEV** function allows the driver to transfer these modifications from the old PDEV structure to the new one.

Examples of the types of information that a printer graphics DLL might want to add to the new PDEV structure are pointers to cached font files, or flags indicating whether page initialization should (or should not) take place the next time [DrvStartDoc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartdoc) or [DrvStartPage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartpage) is called.

If [ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca) is called during the rendering of a print document, the printer graphics DLL receives the following sequence of calls:

```
    dhpdevNew = DrvEnablePDEV();
    DrvResetPDEV(dhpdevOld, dhpdevNew);
    DrvDisableSurface(dhpdevOld);
    DrvDisablePDEV(dhpdevOld);
    DrvEnableSurface(dhpdevNew);
    DrvStartDoc(dhpdevNew);
```

If [ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca) is called between documents there is no surface associated with the PDEV, so only the following sequence of calls is made:

```
    dhpdevNew = DrvEnablePDEV();
    DrvResetPDEV(dhpdevOld,dhpdevNew);
    DrvDisablePDEV(dhpdevOld);
```

## See also

[DrvDisablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablepdev)

[DrvDisableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablesurface)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)

[DrvStartDoc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartdoc)

[DrvStartPage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstartpage)