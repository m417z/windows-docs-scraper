# EnumResourceTypesExA function

## Description

Enumerates resource types associated with a specified binary module. The search can include both a [language-neutral Portable Executable](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) file (LN file) and its associated .mui files. Alternately, it can be limited to a single binary module of any type, or to the .mui files associated with a single LN file. The search can also be limited to a single associated .mui file that contains resources for a specific language.

For each resource type found, **EnumResourceTypesEx** calls an application-defined callback function *lpEnumFunc*, passing the resource type it finds, as well as the various other parameters that were passed to **EnumResourceTypesEx**.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

The handle to a module to be searched. Typically this is an LN file, and if flag **RESOURCE_ENUM_MUI** is set, then appropriate .mui files can be included in the search. Alternately, this can be a handle to an .mui file or other LN file.

If this parameter is **NULL**, it is equivalent to passing in a handle to the module used to create the current process.

### `lpEnumFunc` [in]

Type: **ENUMRESTYPEPROC**

A pointer to the callback function to be called for each enumerated resource type. For more information, see [EnumResTypeProc](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumrestypeproca).

### `lParam` [in]

Type: **LONG_PTR**

An application-defined value passed to the callback function.

### `dwFlags` [in]

Type: **DWORD**

The type of file to be searched. The following values are supported. Note that if *dwFlags* is zero, then the **RESOURCE_ENUM_LN** and **RESOURCE_ENUM_MUI** flags are assumed to be specified.

| Value | Meaning |
| --- | --- |
| **RESOURCE_ENUM_MUI**<br><br>0x0002 | Search for resource types in one of the .mui files associated with the file specified by *hModule* and with the current language preferences, following the usual Resource Loader strategy (see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management)). Alternately, if *LangId* is nonzero, then only the .mui file of the language as specified by *LangId* will be searched. Typically this flag should be used only if *hModule* references an LN file. If *hModule* references an .mui file, then that file is actually covered by the **RESOURCE_ENUM_LN** flag, despite the name of the flag. |
| **RESOURCE_ENUM_LN**<br><br>0x0001 | Searches only the file specified by *hModule*, regardless of whether the file is an LN file or an .mui file. |
| **RESOURCE_ENUM_VALIDATE**<br><br>0x0008 | Performs extra validation on the resource section and its reference in the PE header while doing the enumeration to ensure that resources are properly formatted. The validation sets a maximum limit of 260 characters for each type that is enumerated. |

### `LangId` [in]

Type: **LANGID**

The language used to filter the search in the MUI module. This parameter is used only when the **RESOURCE_ENUM_MUI** flag is set in *dwFlags*. If zero is specified, then all .mui files that match current language preferences are included in the search, following the usual Resource Loader strategy (see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management)). If a nonzero *LangId* is specified, then the only .mui file searched will be the one matching the specified *LangId*.

## Return value

Type: **BOOL**

Returns **TRUE** if successful or **FALSE** if the function does not find a resource of the type specified, or if the function fails for another reason. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **EnumResourceTypesEx** function continues to enumerate resource types until the callback function returns **FALSE** or all resource types have been enumerated.

If *hModule* specifies an LN file, and both flags are selected, the types enumerated correspond to resources residing either in the LN file or in the .mui files associated with it. If no .mui files are found, only types from the LN file are returned. Once one appropriate .mui file is found the search will not continue further, because all .mui files corresponding to a single LN file have the same resource types.

If *dwFlags* and *LangId* are both zero, then the function behaves like [EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa).

If *LangId* is nonzero, then only the .mui file corresponding to that language identifier will be searched. Language fallbacks will not be used. If an .mui file for that language does not exist, the enumeration will be empty (unless resources for that language exist in the LN file, and the flag is set to search the LN file as well).

The enumeration never includes duplicates: if resources for a particular language are contained in both the LN file and in an .mui file, the type will only be enumerated once.

#### Examples

For an example, see [Creating a Resource List](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-resource-requirements-list).

> [!NOTE]
> The libloaderapi.h header defines EnumResourceTypesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResTypeProc](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumrestypeproca)

[EnumResourceLanguagesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa)

[EnumResourceNamesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesexa)

[EnumResourceTypes](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-enumresourcetypesa)

**Reference**

[Resources](https://msdn.microsoft.com/ff321356-c999-4021-a537-fbe863996e24)