# PathIsHTMLFileW macro

## Description

Determines if a file is an HTML file. The determination is made based on the content type that is registered for the file's extension.

## Parameters

### `pszPath` [in]

Type: **LPCTSTR**

The address of a character buffer that contains the path and name of the file.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathIsHTMLFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).