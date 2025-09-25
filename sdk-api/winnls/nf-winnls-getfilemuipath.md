# GetFileMUIPath function

## Description

Retrieves the path to all language-specific resource files associated with the supplied LN file. The application must call this function repeatedly to get the path for each resource file.

## Parameters

### `dwFlags` [in]

Flags identifying language format and filtering. The following flags specify the format of the language indicated by *pwszLanguage*. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Retrieve the language string in [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | Retrieve the language string in [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

The following flags specify the filtering for the function to use in locating language-specific resource files if *pwszLanguage* is set to **NULL**. The filtering flags are mutually exclusive, and the default is MUI_USER_PREFERRED_UI_LANGUAGES.

| Value | Meaning |
| --- | --- |
| **MUI_USE_SEARCH_ALL_LANGUAGES** | Retrieve all language-specific resource files for the path indicated by *pcwszFilePath*, without considering file licensing. This flag is relevant only if the application supplies a null string for *pwszLanguage*. |
| **MUI_USER_PREFERRED_UI_LANGUAGES** | Retrieve only the files that implement languages in the fallback list. Successive calls enumerate the successive fallbacks, in the appropriate order. The first file indicated by the output value of *pcchFileMUIPath* should be the best fit. This flag is relevant only if the application supplies a null string for *pwszLanguage*. |
| **MUI_USE_INSTALLED_LANGUAGES** | Retrieve only the files for the languages installed on the computer. This flag is relevant only if the application supplies a null string for *pwszLanguage*. |

The following flags allow the user to indicate the type of file that is specified by *pcwszFilePath* so that the function can determine if it must add ".mui" to the file name. The flags are mutually exclusive. If the application passes both flags, the function fails. If the application passes neither flag, the function checks the file in the root folder to verify the file type and decide on file naming.

| Value | Meaning |
| --- | --- |
| **MUI_LANG_NEUTRAL_PE_FILE** | Do not verify the file passed in *pcwszFilePath* and append ".mui" to the file name before processing. For example, change Abc.exe to Abc.exe.mui. |
| **MUI_NON_LANG_NEUTRAL_FILE** | Do not verify the file passed in *pcwszFilePath* and do not append ".mui" to the file name before processing. For example, use Abc.txt or Abc.chm. |

### `pcwszFilePath` [in]

Pointer to a null-terminated string specifying a file path. The path is either for an existing LN file or for a file such as a .txt, .inf, or .msc file. If the file is an LN file, the function looks for files containing the associated language-specific resources. For all other types of files, the function seeks files that correspond exactly to the file name and path indicated. Your application can overwrite the behavior of the file type check by using the MUI_LANG_NEUTRAL_PE_FILE or MUI_NON_LANG_NEUTRAL_FILE flag. For more information, see the Remarks section.

**Note** The supplied file path can be a network path: for example, "\\machinename\c$\windows\system32\notepad.exe".

### `pwszLanguage` [in, out, optional]

Pointer to a buffer containing a language string. On input, this buffer contains the language identifier or language name for which the application should find language-specific resource files, depending on the settings of *dwFlags*. On successful return from the function, this parameter contains the language of the language-specific resource file that the function has found.

Alternatively, the application can set this parameter to **NULL**, with the value referenced by *pcchLanguage* set to 0. In this case, the function retrieves the required buffer size in *pcchLanguage*.

### `pcchLanguage` [in, out]

Pointer to the buffer size, in characters, for the language string indicated by *pwszLanguage*. If the application sets the value referenced by this parameter to 0 and passes **NULL** for *pwszLanguage*, then the required buffer size will be returned in *pcchLanguage* and the returned buffer size is always [LOCALE_NAME_MAX_LENGTH](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants), because the function is typically called multiple times in succession. The function cannot determine the exact size of the language name for all successive calls, and cannot extend the buffer on subsequent calls. Thus LOCALE_NAME_MAX_LENGTH is the only safe maximum.

### `pwszFileMUIPath` [out, optional]

Pointer to a buffer containing the path to the language-specific resource file. It is strongly recommended to allocate this buffer to be of size MAX_PATH.

Alternatively, this parameter can retrieve **NULL** if the value referenced by *pcchFileMUIPath* is set to 0. In this case, the function retrieves the required size for the file path buffer in *pcchFileMUIPath*.

### `pcchFileMUIPath` [in, out]

Pointer to the buffer size, in characters, for the file path indicated by *pwszFileMUIPath*. On successful return from the function, this parameter indicates the size of the retrieved file path. If the application sets the value referenced by this parameter to 0, the function retrieves **NULL** for *pwszFileMUIPath*, the required buffer size will be returned in *pcchFileMUIPath* and the returned buffer size is always MAX_PATH, because the function is typically called multiple times in succession. The function cannot determine the exact size of the path for all successive calls, and cannot extend the buffer on subsequent calls. Thus MAX_PATH is the only safe maximum.

### `pululEnumerator` [in, out]

Pointer to an enumeration variable. The first time this function is called, the value of the variable should be 0. Between subsequent calls, the application should not change the value of this parameter. After the function retrieves all possible language-specific resource file paths, it returns **FALSE**.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. If the function fails, the output parameters do not change.

To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_NO_MORE_FILES. There were no more files to process.

## Remarks

This function verifies that language-specific resource files exist, but it does not verify that they are correct. It requires the resource files to be stored according to the storage convention explained in [Application Deployment](https://learn.microsoft.com/windows/desktop/Intl/application-deployment).

If the call to this function specifies the MUI_LANGUAGE_ID flag, the supplied language string must

use a hexadecimal language identifier that does not include the leading 0x, and is 4 characters in length.

For example, en-US should be passed as "0409" and en as "0009". The returned language string will be in the

same format.

When MUI_LANGUAGE_ID is specified, each hexadecimal value in the supplied language string must represent an actual language identifier. In particular, the values corresponding to the following locales cannot be specified:

* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

To receive enumerated information, the application should call this function repeatedly until it returns **FALSE**, leaving the contents of *pululEnumerator* unchanged between calls. Since each call retrieves the path to a different language-specific resource file, the application must clear the language buffer to an empty string between calls. If the application does not do this, the input value of *pwszLanguage* takes precedence over the setting of *dwFlags*.

Typically the resource loader is used to find resource files. However, your application can also use this function to find the files. If the input file path is for an LN file, the function attaches a suffix of ".mui" when looking for the corresponding language-specific resource files.

For example, the function retrieves the following files when the application passes the string "C:\mydir\Example1.dll" in *pcwszFilePath* as the root file path, with *dwFlags* set to MUI_LANGUAGE_NAME | MUI_USE_SEARCH_ALL_LANGUAGES:

* C:\mydir\Example1.dll
  + C:\mydir\en-US\Example1.dll.mui
  + C:\mydir\ja-JP\Example1.dll.mui

The first call to the function sets *pwszFileMUIPath* to "C:\mydir\en-US\Example1.dll.mui". The second call sets the file path to "C:\mydir\ja-JP\Example1.dll.mui". The function returns **FALSE** when called a third time and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_NO_MORE_FILES.

If the file indicated by *pcwszFilePath* does not have resource configuration data, or if the file does not exist, the function leaves the file name as it is when looking for the corresponding language-specific resource files.

For example, the application passes the string "C:\mydir\Example2.txt" in *pcwszFilePath* as the root file path, with *dwFlags* set to MUI_LANGUAGE_NAME | MUI_USER_PREFERRED_UI_LANGUAGES. Let's consider the case in which the user preferred UI languages (in order) are Catalan, "ca-ES", and Spanish (Spain), "es-ES", and where the following files exist:

* (no corresponding file in C:\mydir)
  + C:\mydir\en-US\Example2.txt
  + C:\mydir\en\Example2.txt
  + C:\mydir\es-ES\Example2.txt
  + C:\mydir\es\Example2.txt
  + C:\mydir\ja-JP\Example2.txt

The first call to the function determines that there are no resources for "ca-ES" or for the neutral language "ca". The function then tries the next option, "es-ES", for which it succeeds in finding a match. Before returning, the function sets *pwszFileMUIPath* to "C:\mydir\es-ES\Example2.txt". A second application call to the function continues the enumeration by setting *pwszFileMUIPath* to "C:\mydir\es\Example2.txt".

If the target file and its associated resource files are actually [Side-by-side enabled assemblies](https://learn.microsoft.com/windows/desktop/SbsCs/isolated-applications-and-side-by-side-assemblies-portal), GetFileMUIPath cannot be used to retrieve the path to the resource file. Please refer to [Using Assemblies with a Multilanguage User Interface](https://learn.microsoft.com/windows/desktop/SbsCs/using-assemblies-with-a-multilanguage-user-interface) for details on how to use Side-by-side assemblies with MUI support.

### C# Signature

```cpp
[DllImport("Kernel32.dll", CharSet = CharSet.Auto)]
        static extern System.Boolean GetFileMUIPath(
            System.UInt32 dwFlags,
            System.String pcwszFilePath,
            System.Text.StringBuilder pwszLanguage,
            ref System.UInt32 pcchLanguage,
            System.Text.StringBuilder pwszFileMUIPath,
            ref System.UInt32 pcchFileMUIPath,
            ref System.UInt64 pululEnumerator
            );

```

## See also

[GetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getthreaduilanguage)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)

[SetThreadPreferredUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreadpreferreduilanguages)

[SetThreadUILanguage](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-setthreaduilanguage)