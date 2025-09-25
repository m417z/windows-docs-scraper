## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

A print provider's **InitializePrintProvidor** function initializes the provider and supplies the print spooler with the provider's entry points.

## Parameters

### `pPrintProvidor` [out]

Caller-supplied address of a [**PRINTPROVIDOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprovidor) structure, to be filled in by the print provider.

### `cbPrintProvidor` [in]

Caller-supplied size, in bytes, of the PRINTPROVIDOR structure pointed to by *pPrintProvidor*.

### `pFullRegistryPath` [in, optional]

Caller-supplied pointer to a string representing the full registry path to the provider's registry entry.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise the function should return **FALSE**.

## Remarks

Print providers are required to define an **InitializePrintProvidor** function, which is the first function called by the spooler after the provider has been loaded. The function must fill the supplied [**PRINTPROVIDOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprovidor) structure with pointers to the provider's defined functions (see [Functions defined by print providers](https://learn.microsoft.com/windows-hardware/drivers/print/functions-defined-by-print-providers)). The function can also perform other provider-specific initialization operations.

## See also

[**PRINTPROVIDOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_printprovidor)