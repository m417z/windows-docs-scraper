# EnumResourceLanguagesExA function

## Description

Enumerates language-specific resources, of the specified type and name, associated with a specified binary module. Extends [EnumResourceLanguages](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcelanguagesa) by allowing more control over the enumeration.

## Parameters

### `hModule` [in]

Type: **HMODULE**

The handle to a module to search. Typically this is a [language-neutral Portable Executable](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) (LN file), and if flag **RESOURCE_ENUM_MUI** is set, then appropriate .mui files are included in the search. Alternately, this can be a handle to an .mui file or other LN file. If this is a specific .mui file, only that file is searched for resources.

If this parameter is **NULL**, it is equivalent to passing in a handle to the module used to create the current process.

### `lpType` [in]

Type: **LPCTSTR**

The type of the resource for which the language is being enumerated. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is an integer value representing a predefined resource type. For a list of predefined resource types, see [Resource Types](https://learn.microsoft.com/windows/desktop/menurc/resource-types). For more

information, see the Remarks section below.

### `lpName` [in]

Type: **LPCTSTR**

The name of the resource for which the language is being enumerated. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is the integer identifier of the resource. For more information, see the Remarks section below.

### `lpEnumFunc` [in]

Type: **ENUMRESLANGPROC**

A pointer to the callback function to be called for each enumerated resource language. For more information, see [EnumResLangProcA](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumreslangproca).

### `lParam` [in]

Type: **LONG_PTR**

An application-defined value passed to the callback function. This parameter can be used in error checking.

### `dwFlags` [in]

Type: **DWORD**

The type of file to be searched. The following values are supported. Note that if *dwFlags* is zero, then the **RESOURCE_ENUM_LN** and **RESOURCE_ENUM_MUI** flags are assumed to be specified.

| Value | Meaning |
| --- | --- |
| **RESOURCE_ENUM_MUI**<br><br>0x0002 | Search for language-specific resources in .mui files associated with the LN file specified by *hModule*. Alternately, if *LangId* is nonzero, the only .mui file searched will be the one matching the specified *LangId*. Typically this flag should be used only if *hModule* references an LN file. If *hModule* references an .mui file, then that file is actually covered by the **RESOURCE_LN** flag, despite the name of the flag. See the Remarks section below for sequence of search. |
| **RESOURCE_ENUM_LN**<br><br>0x0001 | Searches the file specified by *hModule*, regardless of whether the file is an LN file, another type of LN file, or an .mui file. |
| **RESOURCE_ENUM_MUI_SYSTEM**<br><br>0x0004 | Restricts the .mui files search to system-installed MUI languages. |
| **RESOURCE_ENUM_VALIDATE**<br><br>0x0008 | Performs extra validation on the resource section and its reference in the PE header while doing the enumeration to ensure that resources are properly formatted. |

### `LangId` [in]

Type: **LANGID**

The localization language used to filter the search in the .mui file. This parameter is used only when the **RESOURCE_ENUM_MUI** flag is set in *dwFlags*. If zero is specified, then all .mui files are included in the search. If a nonzero *LangId* is specified, then the only .mui file searched will be the one matching the specified *LangId*.

## Return value

Type: **BOOL**

Returns **TRUE** if the function succeeds or **FALSE** if the function does not find a resource of the type specified, or if the function fails for another reason. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpType*) is **TRUE**, then *lpType* specifies the integer identifier of the given resource type. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the

integer identifier of the resource type. For example, the string "#258" represents the identifier 258.

Similarly, if [IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpName*) is **TRUE**, then *lpName* specifies the integer identifier of the given resource. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the

integer identifier of the resource.

Starting with Windows Vista, the binary module is typically an LN file, and the enumeration will also include resources from the corresponding language-specific resource files (.mui files) that contain localizable language resources.

For each such resource found, **EnumResourceLanguagesEx** calls an application-defined callback function *lpEnumFunc*, passing to the callback function the language identifier (see [Language Identifiers](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers)) of the language for which a resource was found (as well as the various other parameters that were passed to **EnumResourceLanguagesEx**).

The search can include both an LN file and its associated .mui files, or it can be limited either to a single binary module of any type, or to the .mui files associated with a single LN file. Also, by specifying an LN file for the *hModule* parameter and a nonzero *LangId* parameter, the search can be limited to the unique .mui file associated with that LN file and language.

The **EnumResourceLanguagesEx** function continues to enumerate resource languages until the callback function returns **FALSE** or all resource languages have been enumerated.

If *hModule* specifies an LN file, and both flags are selected, the languages enumerated include all languages whose resources reside either in the LN file or in any .mui files associated with it. If no .mui files are found, only languages from the LN file are returned.

If *dwFlags* contains **RESOURCE_ENUM_MUI** or **NULL** and *LangId* is 0, then the enumeration first includes the languages associated with all system-installed .mui files, using languages retrieved from [EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa).. Finally, if the **RESOURCE_ENUM_LN** flag is also set, the file designated by *hModule* is also searched.

If the *LangId* is nonzero, then only the .mui file corresponding to that language identifier will be searched. Language fallbacks will not be used. If an .mui file for that language does not exist, the enumeration will be empty (unless resources for that language exist in the LN file, and the flag is set to search the LN file as well).

The enumeration never includes duplicates: if resources for a particular language are contained in both the LN file and in an .mui file, the type will only be enumerated once.

#### Examples

For an example, see [Creating a Resource List](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-resource-requirements-list).

> [!NOTE]
> The libloaderapi.h header defines EnumResourceLanguagesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResLangProcA](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumreslangproca)

[EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa)

[EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)

**Reference**

[Resources](https://msdn.microsoft.com/ff321356-c999-4021-a537-fbe863996e24)