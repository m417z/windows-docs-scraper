# PathFindOnPathW function

## Description

Searches for a file.

## Parameters

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the file name for which to search. If the search is successful, this parameter is used to return the fully qualified path name.

### `ppszOtherDirs` [in, optional]

Type: **LPCTSTR***

An optional, null-terminated array of directories to be searched first. This value can be **NULL**.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

**PathFindOnPath** searches for the file specified by *pszFile*. If no directories are specified in *ppszOtherDirs*, it attempts to find the file by searching standard directories such as System32 and the directories specified in the PATH environment variable. To expedite the process or enable **PathFindOnPath** to search a wider range of directories, use the *ppszOtherDirs* parameter to specify one or more directories to be searched first. If more than one file has the name specified by *pszFile*, **PathFindOnPath** returns the first instance it finds.

> [!NOTE]
> The shlwapi.h header defines PathFindOnPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).