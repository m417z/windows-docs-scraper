# FCICreate function

## Description

The **FCICreate** function creates an FCI context.

## Parameters

### `perf` [in, out]

Pointer to an [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure that receives the error information.

### `pfnfcifp` [in]

Pointer to an application-defined callback function to notify when a file is placed in the cabinet. The function should be declared using the [FNFCIFILEPLACED](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcifileplaced) macro.

### `pfna` [in]

Pointer to an application-defined callback function to allocate memory. The function should be declared using the [FNFCIALLOC](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcialloc) macro.

### `pfnf` [in]

Pointer to an application-defined callback function to free previously allocated memory. The function should be declared using the [FNFCIFREE](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcifree) macro.

### `pfnopen` [in]

Pointer to an application-defined callback function to open a file. The function should be declared using the [FNFCIOPEN](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfciopen) macro.

### `pfnread` [in]

Pointer to an application-defined callback function to read data from a file. The function should be declared using the [FNFCIREAD](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfciread) macro.

### `pfnwrite` [in]

Pointer to an application-defined callback function to write data to a file. The function should be declared using the [FNFCIWRITE](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfciwrite) macro.

### `pfnclose` [in]

Pointer to an application-defined callback function to close a file. The function should be declared using the [FNFCICLOSE](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfciclose) macro.

### `pfnseek` [in]

Pointer to an application-defined callback function to move a file pointer to the specific location. The function should be declared using the [FNFCISEEK](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfciseek) macro.

### `pfndelete` [in]

Pointer to an application-defined callback function to delete a file. The function should be declared using the [FNFCIDELETE](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcidelete) macro.

### `pfnfcigtf` [in]

Pointer to an application-defined callback function to retrieve a temporary file name. The function should be declared using the [FNFCIGETTEMPFILE](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcigettempfile) macro.

### `pccab` [in]

Pointer to a [CCAB](https://learn.microsoft.com/windows/desktop/api/fci/ns-fci-ccab) structure that contains the parameters for creating a cabinet.

### `pv` [in, optional]

Pointer to an application-defined value that is passed to callback functions.

## Return value

If the function succeeds, it returns a non-**NULL** HFCI context pointer; otherwise, **NULL**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure.

## Remarks

FCI supports multiple simultaneous contexts. As a result it is possible to create or extract multiple cabinets at the same time within the same application. If the application is multithreaded, it is also possible to run a different context in each thread; however, an application cannot use the same context simultaneously in multiple threads. For example, [FCIAddFile](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fciaddfile) cannot be called from two different threads, using the same FCI context.

## See also

[FCIAddFile](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fciaddfile)

[FCIDestroy](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcidestroy)

[FCIFlushFolder](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fciflushfolder)