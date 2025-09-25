# LoadMUILibraryW function

## Description

Returns a handle to the language-specific resources associated with a particular language-neutral (LN) file.

**Note** To ensure that the DLL is unloaded correctly, your applications should match each call to **LoadMUILibrary** with a corresponding call to [FreeMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-freemuilibrary).

## Parameters

### `pszFullModuleName` [in]

Pointer to a null-terminated string specifying the name of an LN file.

### `dwLangConvention` [in]

Flags specifying the naming convention on pre-Windows Vista operating systems to name the directories containing the language-specific resource files. The flags are mutually exclusive, and the default is MUI_LANGUAGE_NAME.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_ID** | Interpret the name of the folder containing the language-specific resource files using [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) format. |
| **MUI_LANGUAGE_NAME** | Interpret the name of the folder containing the language-specific resource files using [language name](https://learn.microsoft.com/windows/desktop/Intl/language-names) format. |

The following flag is available as an option and can be used in combination with either of the other flags.

| Value | Meaning |
| --- | --- |
| **MUI_LANGUAGE_EXACT** | If resources for the identified language are not found in the resource files, check the main module specified by *pwszModuleName* and return a handle to that module if successful. |

### `LangID` [in]

Language identifier for the user interface resources on a pre-Windows Vista operating system. The language identifier cannot correspond to the language associated with any of these locale information constants:

* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)
* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

## Return value

Returns a handle to the appropriate language-specific resource file if successful.

This function returns **NULL** if it fails. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function allows applications developed using the Win32 MUI resource technology to determine correctly the language-specific resource file to load on pre-Windows Vista operating systems. Applications using this function do not specifically have to be built on Windows Vista, but they do have to link statically with the MUILoad library provided in the Microsoft Windows SDK for Windows Vista. This function requires the executable and language-specific resource files to be stored using standard conventions. See [Application Deployment](https://learn.microsoft.com/windows/desktop/Intl/application-deployment) for further information about file placement.

The following items influence the loading of satellite binaries by this function.

* Operating system version running the application that calls the function
* Flag passed in the *dwLangConvention* parameter
* State of the language identifier passed in the *LangID* parameter

When running on Windows Vista, this function loads the main module without redirection. Only the *pszFullModuleName* parameter is used, as the resource loader functions perform redirection appropriately when they are called. When running on pre-Windows Vista operating systems, this function takes into account all parameters that the application supplies. It redirects binary loading to the proper satellite binary pair associated with the file represented by *pszFullModuleName*. This process reconstitutes the path associated with the file to mimic the behavior of Windows Vista that underlies the resource loader functions.

The application uses the *dwLangConvention* parameter to specify the way the satellite binaries should be probed. If the application sets this parameter to MUI_LANGUAGE_ID, the binaries are probed in folders with hexadecimal string values. (These values do not include the leading 0x, and are 4 characters in length. For example, en-US is represented

as "0409" and en as "0009".) If the application sets the parameter to MUI_LANGUAGE_NAME, the function uses Windows Vista resource loading, which uses language name-based folder probes to find a satellite file.

The state of the language identifier in the *LangID* parameter affects resource probing. If the application sets this parameter to 0, the function uses the predefined fallback logic, dependent on the operating system, to locate the appropriate language-specific resource file. When the application sets *LangID* to a nonzero value, the probing mechanism only searches the appropriately named folder and its associated neutral equivalent. For more information, see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management).

**LoadMUILibrary** is built on the function [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa), and similar considerations need to be applied to its usage. In particular, [FreeMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-freemuilibrary) should be called for any handle returned by **LoadMUILibrary**. Also, **LoadMUILibrary** should not be called from [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain). For more information see the Remarks sections of [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) and [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary).

> [!NOTE]
> The muiload.h header defines LoadMUILibrary as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FreeMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-freemuilibrary)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)