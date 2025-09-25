## Description

The **FINVOCATION** structure is used as input to the [IPrintOemUni::SendFontCmd](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-sendfontcmd) method. The structure is defined in printoem.h.

## Members

### `dwCount`

Specifies the Unidrv-supplied length, in bytes, of the command pointed to by **pubCommand**.

### `pubCommand`

Unidrv-supplied pointer to a string containing the printer's font selection command. The command is obtained from the font's .ufm (Unidrv Font Metrics) file.

## See also

[IPrintOemUni::SendFontCmd](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-sendfontcmd)