# _PRINTER_EVENT_ATTRIBUTES_INFO structure

## Description

The PRINTER_EVENT_ATTRIBUTES_INFO structure contains the former attributes and the new attributes for a printer.

## Members

### `cbSize`

Specifies the size of this structure.

### `dwOldAttributes`

A set of bits describing the current printer attributes.

### `dwNewAttributes`

A set of bits describing the new printer attributes to be applied to the printer.

## Remarks

The bits in the **dwOldAttributes** and **dwNewAttributes** members of this structure are set in accordance with the **Attributes** member of the PRINTER_INFO_2 structure (defined in the Microsoft Windows SDK documentation).

Because this structure might become larger in future operating system versions, anyone using this structure is advised to check that the value in the **cbSize** member of this structure is at least as large as the offset of the member to be accessed.

## See also

[DrvPrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvprinterevent)

[IPrintOemUI::PrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-printerevent)