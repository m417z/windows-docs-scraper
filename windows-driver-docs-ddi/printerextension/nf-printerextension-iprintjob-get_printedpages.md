## Description

Gets the number of pages that have been printed.

This property is read-only.

## Parameters

### `pulPages`

Defines the **ULONG** parameter *pulPages*.

## Return value

Returns an **HRESULT** value.

## Remarks

If the **PrintedPages** and [IPrintJob::TotalPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintjob-get_totalpages) properties are both zero, then page delimiting is not supported for the print job.

## See also

[IPrintJob::IPrintJob](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjob)

[TotalPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintjob-get_totalpages)