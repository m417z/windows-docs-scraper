## Description

Enumerates resources of a specified type that are associated with a specified binary module. The search can include both an LN file and its associated .mui files, or it can be limited in several ways.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

The handle to a module to search. Typically this is an LN file, and if flag **RESOURCE_ENUM_MUI** is set, then appropriate .mui files are included in the search. Alternately, this can be a handle to an .mui file or other LN file.

If this parameter is **NULL**, it is equivalent to passing in a handle to the module used to create the current process.

### `lpType`

Type: **LPCTSTR**

The type of the resource for which the name is being enumerated. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is an integer value representing a predefined resource type. For a list of predefined resource types, see [Resource Types](https://msdn.microsoft.com/8d27f79a-8165-4565-a975-f25b2344efdc). For more information, see the Remarks section below.

### `lpEnumFunc` [in]

Type: **ENUMRESNAMEPROC**

A pointer to the callback function to be called for each enumerated resource name. For more information, see [EnumResNameProc](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumresnameproca).

### `lParam` [in]

Type: **LONG_PTR**

An application-defined value passed to the callback function. This parameter can be used in error checking.

### `dwFlags` [in]

Type: **DWORD**

The type of file to search. The following values are supported. Note that if *dwFlags* is zero, then the **RESOURCE_ENUM_LN** and **RESOURCE_ENUM_MUI** flags are assumed to be specified.

| Value | Meaning |
| --- | --- |
| **RESOURCE_ENUM_MUI**<br><br>0x0002 | Search for resources in .mui files associated with the LN file specified by *hModule* and with the current language preferences, following the usual Resource Loader strategy (see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management)). Alternately, if *LangId* is nonzero, then only the specified .mui file will be searched. Typically this flag should be used only if *hModule* references an LN file. If *hModule* references an .mui file, then that file is actually covered by the **RESOURCE_ENUM_LN** flag, despite the name of the flag. |
| **RESOURCE_ENUM_LN**<br><br>0x0001 | Searches the file specified by *hModule*, regardless of whether the file is an LN file, another type of LN file, or an .mui file. |
| **RESOURCE_ENUM_VALIDATE**<br><br>0x0008 | Performs extra validation on the resource section and its reference in the PE header while doing the enumeration to ensure that resources are properly formatted. The validation sets a maximum limit of 260 characters for each name that is enumerated. |

### `LangId` [in]

Type: **LANGID**

The localization language used to filter the search in the MUI module. This parameter is used only when the **RESOURCE_ENUM_MUI** flag is set in *dwFlags*. If zero is specified, then all .mui files that match current language preferences are included in the search, following the usual Resource Loader strategy (see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management)). If a nonzero *LangId* is specified, then the only .mui file searched will be the one matching the specified *LangId*.

## Return value

Type: **BOOL**

The function **TRUE** if successful, or **FALSE** if the function does not find a resource of the type specified, or if the function fails for another reason. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-is_intresource)(*lpszType*) is **TRUE**, then *lpszType* specifies the integer identifier of the given resource type. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the

integer identifier of the resource type. For example, the string "#258" represents the identifier 258.

The enumeration search can include both an LN file and its associated .mui files. It can be limited to a single binary module of any type. It can also be limited to the .mui files associated with a single LN file. By specifying an LN file for the *hModule* parameter and a nonzero *LangId* parameter, the search can be limited to the unique .mui file associated with that LN file and language.

For each resource found, **EnumResourceNamesEx** calls an application-defined callback function *lpEnumFunc*, passing the name or the ID of each resource it finds, as well as the various other parameters that were passed to **EnumResourceNamesEx**. The passed name is only valid inside the callback - if the passed name is a string pointer, it points to an internal buffer that is reused for all callback invocations.

If a resource has an ID, the ID is returned to the callback function; otherwise the resource name is returned to the callback function. For more information, see [EnumResNameProc](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumresnameproca).

The **EnumResourceNamesEx** function continues to enumerate resource names until the callback function returns **FALSE** or all resource names for this type have been enumerated.

If *hModule* specifies an LN file, and both flags are selected, the names enumerated correspond to resources residing either in that LN file or the .mui files associated with it. If no .mui files are found, only names from the LN file are returned. After one appropriate .mui file is found the search will not continue further, because all .mui files corresponding to a single LN file have the same resource names.

If *dwFlags* and *LangId* are both zero, then the function behaves like [EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa).

If *LangId* is nonzero, then only the .mui file corresponding to that Language identifier will be searched. Language fallbacks will not be used. If an .mui file for that language does not exist, the enumeration will be empty (unless resources for that language exist in the LN file, and the flag is set to search the LN file as well).

The enumeration never includes duplicates: if resources for a particular language are contained in both the LN file and in an .mui file, the name will only be enumerated once.

## Examples

For an example, see [Creating a Resource List](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-resource-requirements-list).

> [!NOTE]
> The libloaderapi.h header defines EnumResourceNamesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResNameProc](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumresnameproca)

[EnumResourceLanguagesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexa)

[EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa)

[EnumResourceTypesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcetypesexa)

**Reference**

[Resources](https://msdn.microsoft.com/ff321356-c999-4021-a537-fbe863996e24)