# EnumResourceLanguagesA function

## Description

Enumerates language-specific resources, of the specified type and name, associated with a binary module.

## Parameters

### `hModule` [in]

Type: **HMODULE**

The handle to a module to be searched. Starting with Windows Vista, if this is a [language-neutral Portable Executable](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) (LN file), then appropriate .mui files (if any exist) are included in the search. If this is a specific .mui file, only that file is searched for resources.

If this parameter is **NULL**, that is equivalent to passing in a handle to the module used to create the current process.

### `lpType` [in]

Type: **LPCTSTR**

The type of resource for which the language is being enumerated. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is an integer value representing a predefined resource type. For a list of predefined resource types, see [Resource Types](https://learn.microsoft.com/windows/win32/menurc/resource-types). For more information, see the Remarks section below.

### `lpName` [in]

Type: **LPCTSTR**

The name of the resource for which the language is being enumerated. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is the integer identifier of the resource. For more information, see the Remarks section below.

### `lpEnumFunc` [in]

Type: **ENUMRESLANGPROC**

A pointer to the callback function to be called for each enumerated resource language. For more information, see [EnumResLangProcA](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumreslangproca).

### `lParam` [in]

Type: **LONG_PTR**

An application-defined value passed to the callback function. This parameter can be used in error checking.

## Return value

Type: **BOOL**

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource)(*lpType*) is **TRUE**, then *lpType* specifies the integer identifier of the given resource type. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource type. For example, the string "#258" represents the identifier 258.

Similarly, if [IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource)(*lpName*) is **TRUE**, then *lpName* specifies the integer identifier of the given resource. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource.

Starting with Windows Vista, the binary module is typically a [language-neutral Portable Executable](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) (LN file), and the enumeration will also include resources from the corresponding language-specific resource files (.mui files) that contain localizable language resources.

For each resource found, **EnumResourceLanguages** calls an application-defined callback function *lpEnumFunc*, passing the language identifier (see [Language Identifiers](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers)) of the language for which a resource was found, as well as the various other parameters that were passed to **EnumResourceLanguages**.

Alternately, applications can call [EnumResourceLanguagesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexw), which provides more precise control of what resources are enumerated.

The **EnumResourceLanguages** function continues to enumerate resource languages until the callback function returns **FALSE** or all resource languages have been enumerated.

In Windows Vista and later, if *hModule* specifies an LN file, then the resources enumerated can reside either in the LN file or in an .mui file associated with it. If no .mui files are found, only resources from the LN file are returned. Unlike [EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa) and [EnumResourceTypes](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enumresourcetypesa), this search will look at multiple .mui files. The enumeration begins with .mui files in the folders associated with [EnumUILanguages](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumuilanguagesa). These are followed by any other .mui files whose paths conform to the scheme described at [MUI Resource Management](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management). Finally, the file designated by *hModule* is also searched.

The enumeration never includes duplicates: if a resource with the same name, type, and language is contained in both the LN file and in an .mui file, the resource will only be enumerated once.

#### Examples

For an example, see [Creating a Resource List](https://learn.microsoft.com/windows/desktop/menurc/using-resources).

> [!NOTE]
> The winbase.h header defines EnumResourceLanguages as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResLangProc](https://learn.microsoft.com/windows/win32/api/libloaderapi/nc-libloaderapi-enumreslangproca)

[EnumResourceLanguagesEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcelanguagesexw)

[EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa)

[EnumResourceTypes](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enumresourcetypesa)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)