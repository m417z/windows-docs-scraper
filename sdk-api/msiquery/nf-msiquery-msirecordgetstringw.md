# MsiRecordGetStringW function

## Description

The
**MsiRecordGetString** function returns the string value of a record field.

## Parameters

### `hRecord` [in]

Handle to the record.

### `iField` [in]

Specifies the field requested.

### `szValueBuf` [out]

Pointer to the buffer that receives the null terminated string containing the value of the record field. Do not attempt to determine the size of the buffer by passing in a null (value=0) for *szValueBuf*. You can get the size of the buffer by passing in an empty string (for example ""). The function then returns **ERROR_MORE_DATA** and *pcchValueBuf* contains the required buffer size in TCHARs, not including the terminating null character. On return of **ERROR_SUCCESS**, *pcchValueBuf* contains the number of **TCHARs** written to the buffer, not including the terminating null character.

### `pcchValueBuf` [in, out]

Pointer to the variable that specifies the size, in **TCHAR**s, of the buffer pointed to by the variable *szValueBuf*. When the function returns **ERROR_SUCCESS**, this variable contains the size of the data copied to *szValueBuf*, not including the terminating null character. If *szValueBuf* is not large enough, the function returns **ERROR_MORE_DATA** and stores the required size, not including the terminating null character, in the variable pointed to by *pcchValueBuf*.

## Return value

The
**MsiRecordGetString** function returns one of the following values:

## Remarks

If **ERROR_MORE_DATA** is returned, the parameter which is a pointer gives the size of the buffer required to hold the string. If **ERROR_SUCCESS** is returned, it gives the number of characters written to the string buffer. To get the size of the buffer, pass in the address of a 1 character buffer as *szValueBuf* and specify the size of the buffer with *pcchValueBuf* as 0. This ensures that no string value returned by the function fits into the buffer. Do not attempt to determine the size of the buffer by passing in a Null (value=0).

> [!NOTE]
> The msiquery.h header defines MsiRecordGetString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)