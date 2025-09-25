# IsCharSpaceA function

## Description

Determines whether a character represents a space.

## Parameters

### `wch` [in]

Type: **TCHAR**

A single character.

## Return value

Type: **BOOL**

Returns **TRUE** if the character is a space; otherwise, **FALSE**.

## Remarks

For those versions of Windows that do not include **IsCharSpace** in Shlwapi.h, **IsCharSpaceW** must be called directly from Shlwapi.dll (ordinal 29), using a WCHAR in the *wch* parameter. **IsCharSpaceA** is not available in versions of Windows that do not include **IsCharSpace** in Shlwapi.h.

> [!NOTE]
> The shlwapi.h header defines IsCharSpace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).