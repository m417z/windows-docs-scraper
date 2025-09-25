# FCIFlushFolder function

## Description

The **FCIFlushFolder** function forces the current folder under construction to be completed immediately.

## Parameters

### `hfci` [in]

A valid FCI context handle returned by the [FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate) function.

### `pfnfcignc` [in]

Pointer to an application-defined callback function to obtain specifications on the next cabinet to create. The function should be declared using the [FNFCIGETNEXTCABINET](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcigetnextcabinet) macro.

### `pfnfcis` [in]

Pointer to an application-defined callback function to update the user. The function should be declared using the [FNFCISTATUS](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcistatus) macro.

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FCI context.

## Remarks

The **FCIFlushFolder** API forces the folder currently under construction to be completed immediately; effectively resetting the compression history if a compression method is in use.

The callback function indicated by *GetNextCab* will be called if the cabinet overflows, which occurs if the pending data buffered inside an FCI causes the application-specified cabinet media size to be exceeded.

## See also

[FCIFlushCabinet](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fciflushcabinet)