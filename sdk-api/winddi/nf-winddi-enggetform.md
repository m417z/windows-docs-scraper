# EngGetForm function

## Description

The **EngGetForm** function gets the FORM_INFO_1 details for the specified form.

## Parameters

### `hPrinter` [in]

Handle to the printer for which the form is being specified.

### `pFormName` [in]

Pointer to a string that specifies the name of the form.

### `Level` [in]

Specifies the version of the form structure to which *pForm* points. This value must be 1, which indicates that the form information will be returned in a FORM_INFO_1 structure.

### `pForm` [in, optional]

Pointer to an array of bytes that receives the initialized FORM_INFO_1 structure.

### `cbBuf` [in]

Specifies the size, in bytes, of *pForm*.

### `pcbNeeded` [out]

Pointer to a value that specifies the number of bytes copied into the buffer pointed to by *pForm* if the function succeeds. The value is the number of bytes required to perform the copy if *cbBuf* is too small.

## Return value

**EngGetForm** returns **TRUE** if the form structure is successfully copied into *pForm*. Otherwise, it logs an error message and returns **FALSE**. To get the error information, call [EngGetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetlasterror).

## Remarks

**EngGetForm** returns a FORM_INFO_1 structure (described in the Microsoft Windows SDK documentation) containing the form data associated with *pFormName*. The written data and its size are returned to the caller via *pForm* and *pcbNeeded*, respectively. If the array pointed to by *pForm* is not large enough to hold the form data, the requisite array size is instead returned in *pcbNeeded*.

To get a list of all supported forms, the printer driver should call [EngEnumForms](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engenumforms).

## See also

[EngEnumForms](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engenumforms)

[EngGetLastError](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggetlasterror)