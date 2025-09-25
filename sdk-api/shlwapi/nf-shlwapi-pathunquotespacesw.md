# PathUnquoteSpacesW function

## Description

Removes quotes from the beginning and end of a path.

## Parameters

### `lpsz` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path. When the function returns successfully, points to the string with beginning and ending quotation marks removed.

## Return value

**TRUE** if the string gets unquoted; otherwise, **FALSE**.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathUnquoteSpaces as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).