# EngEnumForms function

## Description

The **EngEnumForms** function enumerates the forms supported by the specified printer.

## Parameters

### `hPrinter` [in]

Handle to the printer for which the forms should be enumerated. This is the PDEV handle that is passed as the *hDriver* parameter of [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

### `Level` [in]

Specifies the version of the structure pointed to by *pForm*. This value must be 1, which indicates that the enumerated forms are to be returned in FORM_1_INFO structures.

### `pForm` [out, optional]

Pointer to an array of bytes in which the enumerated FORM_INFO_1 structures are written.

### `cbBuf` [in]

Specifies the size, in bytes, of *lpbForms*.

### `pcbNeeded` [out]

Pointer to a DWORD that receives the number of bytes copied into *pForm*  if the copy is completed successfully. If *pForm* is too small to contain all the enumerated forms' data, this DWORD specifies the number of bytes required.

### `pcReturned` [out]

Pointer to a DWORD that receives the number of FORM_INFO_1 structures copied into *pForm*.

## Return value

**EngEnumForms** returns **TRUE** if all parameters are valid and the enumerated form data is successfully copied into *pForm*. Otherwise, it returns **FALSE** and an error message is logged. To get error information, call [EngGetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetlasterror).

## Remarks

A printer driver can call **EngEnumForms** to have GDI obtain the list of forms supported by a particular printer. The enumerated information is returned as an array of FORM_INFO_1 structures (declared in the Microsoft Windows SDK documentation) pointed to by *pForm*. If the array pointed to by *pForm* is not large enough to hold the enumerated data, the requisite array size is instead returned in *pcbNeeded*.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngGetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetlasterror)