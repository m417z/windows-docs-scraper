# FCIDestroy function

## Description

The **FCIDestroy** function deletes an open FCI context, freeing any memory and temporary files associated with the context.

## Parameters

### `hfci` [in]

A valid FCI context handle returned by the [FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate) function.

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FCI context.

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)