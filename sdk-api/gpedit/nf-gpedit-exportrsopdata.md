# ExportRSoPData function

## Description

The
**ExportRSoPData** function exports a WMI namespace that contains RSoP information to a data file. The function writes the information to a data file that can be imported to a WMI namespace with a call to the
[ImportRSoPData](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-importrsopdata) function.

## Parameters

### `lpNameSpace` [in]

A pointer to a string that specifies the namespace which contains the RSoP data.

### `lpFileName` [in]

A pointer to a string that specifies the name of the file to receive the RSoP data.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the header file WinError.h.

## Remarks

It is recommended that you call the
**ExportRSoPData** function twice: one time to process the user data and a second time to process the computer data.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[ImportRSoPData](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-importrsopdata)