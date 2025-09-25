# EnumResourceTypesW function

## Description

Enumerates resource types within a binary module. Starting with Windows Vista, this is typically a [language-neutral Portable Executable](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) (LN file), and the enumeration also includes resources from one of the corresponding language-specific resource files (.mui files)—if one exists—that contain localizable language resources. It is also possible to use *hModule* to specify a .mui file, in which case only that file is searched for resource types.

Alternately, applications can call [EnumResourceTypesEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-enumresourcetypesexw), which provides more precise control over which resource files to enumerate.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to a module to be searched. This handle must be obtained through [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) or [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa).
See Remarks for more information.

If this parameter is **NULL**, that is equivalent to passing in a handle to the module used to create the current process.

### `lpEnumFunc` [in]

Type: **ENUMRESTYPEPROC**

A pointer to the callback function to be called for each enumerated resource type. For more information, see the [EnumResTypeProc](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nc-libloaderapi-enumrestypeprocw) function.

### `lParam` [in]

Type: **LONG_PTR**

An application-defined value passed to the callback function.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For each resource type found, **EnumResourceTypes** calls an application-defined callback function *lpEnumFunc*, passing each resource type it finds, as well as the various other parameters that were passed to **EnumResourceTypes**.

**EnumResourceTypes** continues to enumerate resource types until the callback function returns **FALSE** or all resource types have been enumerated.

Starting with Windows Vista, if *hModule* specifies an LN file, then the types enumerated correspond to resources that reside in the LN file and in the .mui file associated with it. If no .mui files are found, only types from the LN file are returned. The order in which .mui files are searched is the usual Resource Loader search order; see [User Interface Language Management](https://learn.microsoft.com/windows/desktop/Intl/user-interface-language-management) for details. After one appropriate .mui file is found, the search does not continue further to other .mui files associated with the LN file, because all .mui files that correspond to a single LN file have the same set of resource types.

The enumeration never includes duplicates: if a given resource type is contained in both the LN file and in an .mui file, the type is enumerated only once.

#### Examples

For an example, see [Creating a Resource List](https://learn.microsoft.com/windows/desktop/menurc/using-resources).

> [!NOTE]
> The winbase.h header defines EnumResourceTypes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumResTypeProc](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nc-libloaderapi-enumrestypeprocw)

[EnumResourceLanguages](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enumresourcelanguagesa)

[EnumResourceNames](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-enumresourcenamesa)

[EnumResourceTypesEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-enumresourcetypesexw)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)