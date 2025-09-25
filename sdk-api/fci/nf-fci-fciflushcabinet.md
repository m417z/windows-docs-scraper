# FCIFlushCabinet function

## Description

The **FCIFlushCabinet** function completes the current cabinet.

## Parameters

### `hfci` [in]

A valid FCI context handle returned by the[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate) function.

### `fGetNextCab` [in]

Specifies whether the function pointed to by the supplied *GetNextCab* parameter will be called.

### `pfnfcignc` [in]

Pointer to an application-defined callback function to obtain specifications on the next cabinet to create. The function should be declared using the [FNFCIGETNEXTCABINET](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcigetnextcabinet) macro.

### `pfnfcis` [in]

Pointer to an application-defined callback function to update the user. The function should be declared using the [FNFCISTATUS](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcistatus) macro.

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FCI context.

## Remarks

The **FCIFlushCabinet** API forces the current cabinet under construction to be completed immediately and then written to disk. Further calls to [FCIAddFile](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fciaddfile) will result in files being added to another cabinet.

 In the event the current cabinet has reached the application-specified media size limit, the pending data within an FCI's internal buffers will be placed into another cabinet.

The *fGetNextCab* flag determines whether the function pointed to by the *GetNextCab* parameter will be called. If *fGetNextCab* is set **TRUE**, *GetNextCab* is called to obtain continuation information. If **FALSE**, then *GetNextCab* is called only in the event the cabinet overflows.

## See also

[FCIFlushFolder](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fciflushfolder)