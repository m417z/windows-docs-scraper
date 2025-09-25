# PathCommonPrefixW function

## Description

Compares two paths to determine if they share a common prefix. A prefix is one of these types: "C:\\", ".", "..", "..\\".

## Parameters

### `pszFile1` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the first path name.

### `pszFile2` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the second path name.

### `achPath` [out, optional]

Type: **LPTSTR**

A pointer to a buffer that receives the common prefix. This buffer must be at least MAX_PATH characters in size. If there is no common prefix, it is set to **NULL**.

## Return value

Type: **int**

Returns the count of common prefix characters in the path. If the output buffer pointer is not **NULL**, then these characters are copied to the output buffer.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathCommonPrefix as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).