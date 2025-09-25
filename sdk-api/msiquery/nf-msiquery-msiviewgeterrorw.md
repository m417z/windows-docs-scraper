# MsiViewGetErrorW function

## Description

The
**MsiViewGetError** function returns the error that occurred in the
[MsiViewModify](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewmodify) function.

## Parameters

### `hView` [in]

Handle to the view.

### `szColumnNameBuffer` [out]

Pointer to the buffer that receives the null-terminated column name. Do not attempt to determine the size of the buffer by passing in a null (value=0) for *szColumnName*. You can get the size of the buffer by passing in an empty string (for example ""). The function then returns MSIDBERROR_MOREDATA and *pcchBuf* contains the required buffer size in TCHARs, not including the terminating null character. On return of MSIDBERROR_NOERROR, *pcchBuf* contains the number of TCHARs written to the buffer, not including the terminating null character. This parameter is an empty string if there are no errors.

### `pcchBuf` [in, out]

Pointer to the variable that specifies the size, in TCHARs, of the buffer pointed to by the variable *szColumnNameBuffer*. When the function returns MSIDBERROR_NOERROR, this variable contains the size of the data copied to *szColumnNameBuffer*, not including the terminating null character. If *szColumnNameBuffer* is not large enough, the function returns MSIDBERROR_MOREDATA and stores the required size, not including the terminating null character, in the variable pointed to by *pcchBuf*.

## Return value

This function returns one of the following values.

| Error code | Meaning |
| --- | --- |
| **MSIDBERROR_INVALIDARG** | An argument was invalid. |
| **MSIDBERROR_MOREDATA** | The buffer was too small to receive data. |
| **MSIDBERROR_FUNCTIONERROR** | The function failed. |
| **MSIDBERROR_NOERROR** | The function completed successfully with no errors. |
| **MSIDBERROR_DUPLICATEKEY** | The new record duplicates primary keys of the existing record in a table. |
| **MSIDBERROR_REQUIRED** | There are no null values allowed; or the column is about to be deleted, but is referenced by another row. |
| **MSIDBERROR_BADLINK** | The corresponding record in a foreign table was not found. |
| **MSIDBERROR_OVERFLOW** | The data is greater than the maximum value allowed. |
| **MSIDBERROR_UNDERFLOW** | The data is less than the minimum value allowed. |
| **MSIDBERROR_NOTINSET** | The data is not a member of the values permitted in the set. |
| **MSIDBERROR_BADVERSION** | An invalid version string was supplied. |
| **MSIDBERROR_BADCASE** | The case was invalid. The case must be all uppercase or all lowercase. |
| **MSIDBERROR_BADGUID** | An invalid GUID was supplied. |
| **MSIDBERROR_BADWILDCARD** | An invalid wildcard file name was supplied, or the use of wildcards was invalid. |
| **MSIDBERROR_BADIDENTIFIER** | An invalid identifier was supplied. |
| **MSIDBERROR_BADLANGUAGE** | Invalid language IDs were supplied. |
| **MSIDBERROR_BADFILENAME** | An invalid file name was supplied. |
| **MSIDBERROR_BADPATH** | An invalid path was supplied. |
| **MSIDBERROR_BADCONDITION** | An invalid conditional statement was supplied. |
| **MSIDBERROR_BADFORMATTED** | An invalid format string was supplied. |
| **MSIDBERROR_BADTEMPLATE** | An invalid template string was supplied. |
| **MSIDBERROR_BADDEFAULTDIR** | An invalid string was supplied in the DefaultDir column of the [Directory](https://learn.microsoft.com/windows/desktop/Msi/directory-table) table. |
| **MSIDBERROR_BADREGPATH** | An invalid registry path string was supplied. |
| **MSIDBERROR_BADCUSTOMSOURCE** | An invalid string was supplied in the CustomSource column of the [CustomAction](https://learn.microsoft.com/windows/desktop/Msi/customaction-table) table. |
| **MSIDBERROR_BADPROPERTY** | An invalid property string was supplied. |
| **MSIDBERROR_MISSINGDATA** | The [_Validation](https://learn.microsoft.com/windows/desktop/Msi/-validation-table) table is missing a reference to a column. |
| **MSIDBERROR_BADCATEGORY** | The category column of the [_Validation](https://learn.microsoft.com/windows/desktop/Msi/-validation-table) table for the column is invalid. |
| **MSIDBERROR_BADCABINET** | An invalid cabinet name was supplied. |
| **MSIDBERROR_BADKEYTABLE** | The table in the Keytable column of the [_Validation](https://learn.microsoft.com/windows/desktop/Msi/-validation-table) table was not found or loaded. |
| **MSIDBERROR_BADMAXMINVALUES** | The value in the MaxValue column of the [_Validation](https://learn.microsoft.com/windows/desktop/Msi/-validation-table) table is less than the value in the MinValue column. |
| **MSIDBERROR_BADSHORTCUT** | An invalid shortcut target name was supplied. |
| **MSIDBERROR_STRINGOVERFLOW** | The string is too long for the length specified by the column definition. |
| **MSIDBERROR_BADLOCALIZEATTRIB** | An invalid localization attribute was supplied. (Primary keys cannot be localized.) |

Note that in low memory situations, this function can raise a STATUS_NO_MEMORY exception.

## Remarks

You should only call the
**MsiViewGetError** function when
[MsiViewModify](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewmodify) returns ERROR_INVALID_DATA, indicating that the data is invalid. Errors are only recorded for MSIMODIFY_VALIDATE, MSIMODIFY_VALIDATE_NEW, and MSIMODIFY_VALIDATEFIELD.

If ERROR_MORE_DATA is returned, the parameter that is a pointer gives the size of the buffer required to hold the string. Upon success, it gives the number of characters written to the string buffer. Therefore you can get the required size of the buffer by passing a small buffer (one character minimum) and examining the value at *pcchPathBuf* when the function returns MSIDBERROR_MOREDATA. Do not attempt to determine the size of the buffer by passing in null as *szColumnNameBuffer* or a buffer size of 0 in the **DWORD** referenced by *pcchBuf*.

Once MSIDBERROR_NOERROR is returned, no more validation errors remain. The MSIDBERROR return value indicates the type of validation error that occurred for the value located in the column identified by the *szColumnNameBuffer*.

> [!NOTE]
> The msiquery.h header defines MsiViewGetError as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)