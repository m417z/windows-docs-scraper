# PathQuoteSpacesW function

## Description

Searches a path for spaces. If spaces are found, the entire path is enclosed in quotation marks.

## Parameters

### `lpsz` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string that contains the path to search. The size of this buffer must be set to MAX_PATH to ensure that it is large enough to hold the returned string.

## Return value

Type: **BOOL**

**TRUE** if spaces were found; otherwise, **FALSE**.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathQuoteSpaces as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).