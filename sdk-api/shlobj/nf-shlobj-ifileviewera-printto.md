## Description

Prints a file. The Shell specifies the name of the file to print by calling the file viewer's [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load) method.

## Parameters

### `pszDriver`

A pointer to a buffer that contains the name of the printer device driver that should print the file. If this parameter is **NULL**, the file viewer determines which device driver to use.

### `fSuppressUI`

A user interface suppression flag. If this parameter is **TRUE**, the file viewer should not display any user interface, including error messages, during the print operation. If this parameter is **FALSE**, the file viewer can show dialog boxes, as needed.

## Return value

## Remarks

## See also