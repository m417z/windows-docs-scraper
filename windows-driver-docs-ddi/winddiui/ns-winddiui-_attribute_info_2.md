## Description

The **ATTRIBUTE_INFO_2** structure is used as a parameter for a printer interface DLL's [DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes) function. All member values are function-supplied.

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

## Remarks

The EMF print processor uses the flag specified for **dwColorOptimization** to determine whether to request GDI to perform monochrome color optimization. If monochrome color optimization is enabled, the print job can be switched between monochrome and color rendering as appropriate.

If you are creating a Unidrv rendering plug-in to generate color watermarks, note that when the **dwColorOptimization** member is set to COLOR_OPTIMIZATION, color watermarks are printed in black and white when they are printed on black-and-white documents. To ensure that color watermarks print correctly with color and black-and-white documents, disable color optimization. Color optimization also can be controlled by the Unidrv ***ChangeColorModeOnDoc?** color attribute (see [Color Attributes](https://learn.microsoft.com/windows-hardware/drivers/print/color-attributes)), and by the [GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf) function.

For more information about other structure members, see [**ATTRIBUTE_INFO_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1).

## See also

[**ATTRIBUTE_INFO_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1)

[DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes)

[GdiEndPageEMF](https://learn.microsoft.com/windows-hardware/drivers/ddi/winppi/nf-winppi-gdiendpageemf)