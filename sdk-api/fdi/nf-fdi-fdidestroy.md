# FDIDestroy function

## Description

The **FDIDestroy** function deletes an open FDI context.

## Parameters

### `hfdi` [in]

 A valid FDI context handle returned by the [FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate) function.

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FDI context.

## See also

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)