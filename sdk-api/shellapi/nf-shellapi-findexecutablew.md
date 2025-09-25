# FindExecutableW function

## Description

Retrieves the name of and handle to the executable (.exe) file associated with a specific document file.

## Parameters

### `lpFile` [in]

Type: **LPCTSTR**

The address of a **null**-terminated string that specifies a file name. This file should be a document.

### `lpDirectory` [in, optional]

Type: **LPCTSTR**

The address of a **null**-terminated string that specifies the default directory. This value can be **NULL**.

### `lpResult` [out]

Type: **LPTSTR**

The address of a buffer that receives the file name of the associated executable file. This file name is a **null**-terminated string that specifies the executable file started when an ":::no-loc text="open":::" by association is run on the file specified in the *lpFile* parameter. Put simply, this is the application that is launched when the document file is directly double-clicked or when **Open** is chosen from the file's shortcut menu. This parameter must contain a valid non-**null** value and is assumed to be of length MAX_PATH. Responsibility for validating the value is left to the programmer.

## Return value

Type: **HINSTANCE**

Returns a value greater than 32 if successful, or a value less than or equal to 32 representing an error.

The following table lists possible error values.

| Return code/value | Description |
| --- | --- |
| **SE_ERR_FNF**<br><br>2 | The specified file was not found. |
| **SE_ERR_PNF**<br><br>3 | The specified path is invalid. |
| **SE_ERR_ACCESSDENIED**<br><br>5 | The specified file cannot be accessed. |
| **SE_ERR_OOM**<br><br>8 | The system is out of memory or resources. |
| **SE_ERR_NOASSOC**<br><br>31 | There is no association for the specified file type with an executable file. |

## Remarks

Use **FindExecutable** for documents. If you want to retrieve the path of an executable file, use the following:

```
AssocQueryString(ASSOCF_OPEN_BYEXENAME,
                 ASSOCSTR_EXECUTABLE,
                 pszExecutableName,
                 NULL,
                 pszPath,
                 pcchOut);
```

Here, *pszExecutableName* is a pointer to a **null**-terminated string that specifies the name of the executable file, *pszPath* is a pointer to the **null**-terminated string buffer that receives the path to the executable file, and *pcchOut* is a pointer to a **DWORD** that specifies the number of characters in the *pszPath* buffer. When the function returns, *pcchOut* is set to the number of characters actually placed in the buffer. See [AssocQueryString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-assocquerystringa) for more information.

When **FindExecutable** returns, the *lpResult* parameter may contain the path to the Dynamic Data Exchange (DDE) server started if a server does not respond to a request to initiate a DDE conversation with the DDE client application.

> [!NOTE]
> The shellapi.h header defines FindExecutable as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea)