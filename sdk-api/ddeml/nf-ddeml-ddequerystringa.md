# DdeQueryStringA function

## Description

Copies text associated with a string handle into a buffer.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hsz` [in]

Type: **HSZ**

A handle to the string to copy. This handle must have been created by a previous call to the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function.

### `psz` [out, optional]

Type: **LPTSTR**

A pointer to a buffer that receives the string. To obtain the length of the string, this parameter should be set to **NULL**.

### `cchMax` [in]

Type: **DWORD**

The length, in
characters, of the buffer pointed to by the
*psz* parameter. For the ANSI version of the function, this is the number of bytes; for the Unicode version, this is the number of characters. If the string is longer than (
*cchMax*– 1), it will be truncated. If the
*psz* parameter is set to **NULL**, this parameter is ignored.

### `iCodePage` [in]

Type: **int**

The code page used to render the string. This value should be either **CP_WINANSI** or **CP_WINUNICODE**.

## Return value

Type: **DWORD**

If the
*psz* parameter specified a valid pointer, the return value is the length, in
characters, of the returned text (not including the terminating null character). If the
*psz* parameter specified a **NULL** pointer, the return value is the length of the text associated with the
*hsz* parameter (not including the terminating null character). If an error occurs, the return value is 0L.

## Remarks

The string returned in the buffer is always null-terminated. If the string is longer than (
*cchMax*– 1), only the first (
*cchMax*– 1) characters of the string are copied.

If the
*psz* parameter is **NULL**, the **DdeQueryString** function obtains the length, in bytes, of the string associated with the string handle. The length does not include the terminating null character.

> [!NOTE]
> The ddeml.h header defines DdeQueryString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[DdeCmpStringHandles](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecmpstringhandles)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeFreeStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreestringhandle)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**