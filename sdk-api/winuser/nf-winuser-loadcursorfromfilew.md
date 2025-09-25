# LoadCursorFromFileW function

## Description

Creates a cursor based on data contained in a file.

> [!NOTE]
> This function has been superseded by the [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagew) function (with **LR_DEFAULTSIZE** and **LR_LOADFROMFILE** flags set).

## Parameters

### `lpFileName` [in]

Type: **LPCTSTR**

The source of the file data to be used to create the cursor. The data in the file must be in either .CUR or .ANI format.

If the high-order word of *lpFileName* is nonzero, it is a pointer to a string that is a fully qualified name of a file containing cursor data.

## Return value

Type: **HCURSOR**

If the function is successful, the return value is a handle to the new cursor.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return the following value.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The specified file cannot be found. |

## Remarks

### DPI Virtualization

This API does not participate in DPI virtualization. The output returned is not affected by the DPI of the calling thread.

> [!NOTE]
> The winuser.h header defines LoadCursorFromFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[SetSystemCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsystemcursor)