# DrvQueryFont function

## Description

The **DrvQueryFont** function is used by GDI to get the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure for a given font.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) that identifies a physical device. The PDEV was returned from a previous call to [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `iFile`

Pointer to a driver-defined value that identifies a driver font file. This pointer is returned by [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile). This parameter is zero for device-resident fonts.

### `iFace`

Specifies the one-based index of the driver font. GDI can query the number of fonts from the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure.

### `pid`

Pointer to a memory location holding the address of a driver-defined value that GDI passes to [DrvFree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfree) when the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure is no longer needed. Depending on how the driver manages memory, this value can identify the structure, identify the way it was allocated, or do nothing at all.

## Return value

The return value is a pointer to the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure that describes the given font if the function is successful. Otherwise, it is **NULL**, and an error code is logged.

## Remarks

The driver fills the IFIMETRICS structure.

The IFIMETRICS structure must remain unchanged during the scope of the associated PDEV.

If the number of fonts in DEVINFO is -1 and *iFace* is zero, the driver should return the number of fonts it supports.

**DrvQueryFont** is required for font drivers and drivers that use driver-specific or device-specific fonts.

## See also

[DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvFree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfree)

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)