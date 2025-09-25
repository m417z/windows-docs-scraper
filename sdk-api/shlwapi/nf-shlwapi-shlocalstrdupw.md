# SHLocalStrDupW function

## Description

Makes a copy of a string in newly allocated memory.

## Parameters

### `psz`

Type: **PCTSTR**

A pointer to a null-terminated, Unicode string to be copied.

### `ppsz` [out, optional]

Type: **PTSTR***

The address of a pointer to an allocated string that, when this function returns successfully, receives the result. **SHLocalStrDup** allocates memory for this string with [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc). You should free the string with [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) when it is no longer needed.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

> [!NOTE]
> The shlwapi.h header defines SHLocalStrDup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).