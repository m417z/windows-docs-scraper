# FDIIsCabinet function

## Description

The **FDIIsCabinet** function determines whether a file is a cabinet and, if it is, returns information about it.

## Parameters

### `hfdi` [in]

A valid FDI context handle returned by [FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate).

### `hf` [in]

An application-defined value to keep track of the opened file. This value must be of the same type as values used by the File I/O functions passed to [FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate).

### `pfdici` [in, out]

Pointer to an [FDICABINETINFO](https://learn.microsoft.com/windows/desktop/api/fdi/ns-fdi-fdicabinetinfo) structure that receives the cabinet details, in the event the file is actually a cabinet.

## Return value

If the file is a cabinet, the function returns **TRUE** ; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FDI context.

## See also

[FDICABINETINFO](https://learn.microsoft.com/windows/desktop/api/fdi/ns-fdi-fdicabinetinfo)

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)

[FDITruncateCabinet](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fditruncatecabinet)