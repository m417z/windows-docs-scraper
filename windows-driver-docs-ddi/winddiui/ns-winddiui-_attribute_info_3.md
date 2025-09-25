## Description

The ATTRIBUTE_INFO_3 structure is used as a parameter for a printer interface DLL's [DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes) function. All member values are function-supplied.

## Members

### `dwJobNumberOfPagesPerSide`

Number of document pages to be placed on one side of a physical page, as requested by the user. Allowable values are 1, 2, 4, 6, 9, or 16.

### `dwDrvNumberOfPagesPerSide`

Number of document pages that the printer and driver can place on one side of a physical page. This value must be 1 or the value specified for **dwJobNumberOfPagesPerSide**.

### `dwNupBorderFlags`

One of the following bit flag values:

| Flag | Definition |
|---|---|
| BORDER_PRINT | The print processor should draw a border around the page. |
| NO_BORDER_PRINT | The print processor should not draw a border around the page. |

### `dwJobPageOrderFlags`

One of the following bit flag values:

| Flag | Definition |
|---|---|
| BOOKLET_PRINT | Pages should be printed in booklet form, with two document pages printed on one side of a physical page. In landscape mode, the two document pages are printed side-by-side on the paper. In portrait mode, the two document pages are printed top-and-bottom. |
| NORMAL_PRINT | Pages should be printed in normal order: page 1, page 2, and so on. |
| REVERSE_PRINT | Pages should be printed in reverse order: last page, next-to-last page, and so on. |

### `dwDrvPageOrderFlags`

Bit flags indicating which page ordering options are supported by the printer and driver. Uses the same flags as **dwJobPageOrderFlags**.

### `dwJobNumberOfCopies`

Number of copies of the print job, as requested by the user.

### `dwDrvNumberOfCopies`

Maximum number of copies the printer and driver can handle at once, taking into account such job attributes as collating and stapling.

### `dwColorOptimization`

One of the following bit flag values:

| Flag | Definition |
|---|---|
| COLOR_OPTIMIZATION | The print processor should use monochrome color optimization. |
| NO_COLOR_OPTIMIZATION | The print processor should not use monochrome color optimization. |

### `dmPrintQuality`

Value to be used instead of the **dmPrintQuality** member of the print job's [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure, if the COLOR_OPTIMIZATION flag is set in **dwColorOptimization**.

### `dmYResolution`

Value to be used instead of the **dmYResolution** member of the print job's DEVMODEW structure, if the COLOR_OPTIMIZATION flag is set in **dwColorOptimization**.

## Remarks

If the **dmPrintQuality** member of a print job's DEVMODEW structure is a negative value, such as DMRES_HIGH, and if monochrome color optimization is enabled, then switching between color and monochrome could result in different resolutions being used. This is because DMRES_HIGH might be assigned to different DPI values for color and monochrome rendering. (For Unidrv-supported devices, this assignment occurs in the printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file.) To ensure a consistent resolution throughout the print job, the driver can specify positive **dmPrintQuality** and **dmYResolution** values (representing a specific DPI resolution) to override the equivalent [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) values.

The EMF print processor uses the flag specified for **dwColorOptimization** to determine whether to request GDI to perform monochrome color optimization. If monochrome color optimization is enabled, the print job can be switched between monochrome and color rendering as appropriate.

If you are creating a Unidrv rendering plug-in to generate color watermarks, note that when the **dwColorOptimization** member is set to COLOR_OPTIMIZATION, color watermarks are printed in black and white when they are printed on black-and-white documents. To ensure that color watermarks print correctly with color and black-and-white documents, disable color optimization. Color optimization also can be controlled by the Unidrv ***ChangeColorModeOnDoc?** color attribute (see [Color Attributes](https://learn.microsoft.com/windows-hardware/drivers/print/color-attributes)), and by the [GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf) function.

For information about other ATTRIBUTE_INFO_3 structure members, see [**ATTRIBUTE_INFO_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1) and [**ATTRIBUTE_INFO_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2).

## See also

[**ATTRIBUTE_INFO_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2)

[**ATTRIBUTE_INFO_4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4)

[DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes)

[GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf)

[GetJobAttributesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-getjobattributesex)