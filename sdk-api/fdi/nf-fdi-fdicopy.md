# FDICopy function

## Description

The **FDICopy** function extracts files from cabinets.

## Parameters

### `hfdi` [in]

A valid FDI context handle returned by the [FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate) function.

### `pszCabinet` [in]

The name of the cabinet file, excluding any path information, from which to extract files. If a file is split over multiple cabinets, **FDICopy** allows for subsequent cabinets to be opened.

### `pszCabPath` [in]

The pathname of the cabinet file, but not including the name of the file itself. For example, "C:\MyCabs\".

The contents of *pszCabinet* are appended to *pszCabPath* to create the full pathname of the cabinet.

### `flags` [in]

No flags are currently defined and this parameter should be set to zero.

### `pfnfdin` [in]

Pointer to an application-defined callback notification function to update the application on the status of the decoder. The function should be declared using the [FNFDINOTIFY](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnfdinotify) macro.

### `pfnfdid` [in]

Not currently used by FDI. This parameter should be set to **NULL**.

### `pvUser` [in, optional]

Pointer to an application-specified value to pass to the notification function.

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FDI context.

## See also

[FDICreate](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdicreate)