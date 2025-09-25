# FDITruncateCabinet function

## Description

The **FDITruncateCabinet** function truncates a cabinet file starting at the specified folder number.

## Parameters

### `hfdi` [in]

A valid FDI context handle returned by the [FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate) function.

### `pszCabinetName` [in]

The full cabinet filename.

### `iFolderToDelete` [in]

The index of the first folder to delete.

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FDI context.

## See also

[FDIIsCabinet](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdiiscabinet)