## Description

The ATTRIBUTE_INFO_1 structure is used as a parameter for a printer interface DLL's [DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes) function. All member values are function-supplied.

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

## Remarks

The caller (the EMF print processor) uses the **dwJobNumberOfPagesPerSide** and **dwDrvNumberOfPagesPerSide** members to determine whether the driver or the print processor handles "N-up" printing.

If the print processor handles "N-up" printing, it checks **dwNupBorderFlags** to determine if it should draw a page border.

The print processor checks **dwJobPageOrderFlags** and **dwDrvPageOrderFlags** to determine the order in which pages should be sent to the printer.

The print processor uses **dwJobNumberOfCopies** and **dwDrvNumberOfCopies** to determine the number of times the print job must be sent to the printer.

## See also

[DrvQueryJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvqueryjobattributes)