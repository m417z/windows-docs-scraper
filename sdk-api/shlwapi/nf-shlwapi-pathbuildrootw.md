# PathBuildRootW function

## Description

Creates a root path from a given drive number.

## Parameters

### `pszRoot` [out]

Type: **LPTSTR**

A pointer to the string that receives the constructed root path. This buffer must be at least four characters in size.

### `iDrive` [in]

Type: **int**

A variable of type **int** that indicates the desired drive number. It should be between 0 and 25.

## Return value

Type: **LPTSTR**

Returns the address of the constructed root path. If the call fails for any reason (for example, an invalid drive number), *szRoot* is returned unchanged.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathBuildRoot as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).