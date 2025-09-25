# SHStripMneumonicW function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Removes the mnemonic marker from a string.

## Parameters

### `pszMenu` [in, out]

Type: **LPTSTR***

A pointer to the null-terminated string that contains the mnemonic marker.

## Return value

Type: **TCHAR**

Returns the mnemonic character, if one was found. Otherwise, returns 0.

## Remarks

The term "mnemonic" is misspelled in the function name.

The function supports the following mnemonic formats.

| Input String | Output String | Mnemonic Character | Remarks |
| --- | --- | --- | --- |
| "Str&ing" | "String" | 'i' | None. |
| "String (&S)" | "String" | 'S' | Supported only by the Unicode version of this function. Requires Windows XP or later. |

> [!NOTE]
> The shlwapi.h header defines SHStripMneumonic as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext)