# FDICreate function

## Description

The **FDICreate** function creates an FDI context.

## Parameters

### `pfnalloc` [in]

Pointer to an application-defined callback function to allocate memory. The function should be declared using the [FNALLOC](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnalloc) macro.

### `pfnfree` [in]

Pointer to an application-defined callback function to free previously allocated memory. The function should be declared using the [FNFREE](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnfree) macro.

### `pfnopen` [in]

Pointer to an application-defined callback function to open a file. The function should be declared using the [FNOPEN](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnopen) macro.

### `pfnread` [in]

Pointer to an application-defined callback function to read data from a file. The function should be declared using the [FNREAD](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnread) macro.

### `pfnwrite` [in]

Pointer to an application-defined callback function to write data to a file. The function should be declared using the [FNWRITE](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnwrite) macro.

### `pfnclose` [in]

Pointer to an application-defined callback function to close a file. The function should be declared using the [FNCLOSE](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnclose) macro.

### `pfnseek` [in]

Pointer to an application-defined callback function to move a file pointer to the specified location. The function should be declared using the [FNSEEK](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fnseek) macro.

### `cpuType` [in]

In the 16-bit version of FDI, specifies the CPU type and can be any of the following values.

**Note** Expressing the **cpuUNKNOWN** value is recommended.

| Value | Meaning |
| --- | --- |
| **cpuUNKNOWN**<br><br>-1 | FDI should determine the CPU type. |
| **cpu80286**<br><br>0 | Only 80286 instructions can be used. |
| **cpu80386**<br><br>1 | 80386 instructions can be used. |

### `perf` [in, out]

Pointer to an [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure that receives the error information.

## Return value

If the function succeeds, it returns a non-**NULL** HFDI context pointer; otherwise, it returns **NULL**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure.

## See also

[FDIDestroy](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdidestroy)