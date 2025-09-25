# FCIAddFile function

## Description

The **FCIAddFile** adds a file to the cabinet under construction.

## Parameters

### `hfci` [in]

A valid FCI context handle returned by the [FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate) function.

### `pszSourceFile` [in]

The name of the file to add; this value should include path information.

### `pszFileName` [in]

The name under which to store the file in the cabinet.

### `fExecute` [in]

If set **TRUE**, the file will be executed when extracted.

### `pfnfcignc` [in]

Pointer to an application-defined callback function to obtain specifications on the next cabinet to create. The function should be declared using the [FNFCIGETNEXTCABINET](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcigetnextcabinet) macro.

### `pfnfcis` [in]

Pointer to an application-defined callback function to update the progress information available to the user. The function should be declared using the [FNFCISTATUS](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcistatus) macro.

### `pfnfcigoi` [in]

Pointer to an application-defined callback function to open a file and retrieve the file date, time, and attributes. The function should be declared using the [FNFCIGETOPENINFO](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fnfcigetopeninfo) macro.

### `typeCompress` [in]

The compression type to use.

**Note** To indicate LZX compression, use the [TCOMPfromLZXWindow](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/nf-fdi_fci_types-tcompfromlzxwindow) macro.

| Value | Meaning |
| --- | --- |
| **tcompTYPE_NONE**<br><br>0x0000 | No compression. |
| **tcompTYPE_MSZIP**<br><br>0x0001 | Microsoft ZIP compression. |

## Return value

If the function succeeds, it returns **TRUE**; otherwise, **FALSE**.

Extended error information is provided in the [ERF](https://learn.microsoft.com/windows/desktop/api/fdi_fci_types/ns-fdi_fci_types-erf) structure used to create the FCI context.

## Remarks

When set, the _A_EXEC attribute is added to the file entry in the CAB. This mechanism is used in some Microsoft self-extracting executables, and could be used for this purpose in any custom extraction application.

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)