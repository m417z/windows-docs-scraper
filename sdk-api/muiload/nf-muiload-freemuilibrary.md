# FreeMUILibrary function

## Description

Releases the handle to a resource module loaded by [LoadMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-loadmuilibrarya).

## Parameters

### `hResModule` [in]

Handle to a resource module loaded by [LoadMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-loadmuilibrarya). The handle indicates either a language-specific resource file or an LN file.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The error code is the same as that returned by [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary).

## Remarks

Once the application has called **FreeMUILibrary**, it should treat the passed module handle as invalid.

Applications using this function can be built on pre-Windows Vista operating systems, but they must link statically with the MUILoad library provided in the Microsoft Windows SDK for Windows Vista.

**FreeMUILibrary** is related to [LoadMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-loadmuilibrarya) in the same way that [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) is related to [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa), and similar considerations need to be applied to its usage. In particular, to support correct reference counting, **FreeMUILibrary** should be called for any handle returned by **LoadMUILibrary**. For more information see the Remarks sections of [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) and [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary).

## See also

[LoadMUILibrary](https://learn.microsoft.com/windows/desktop/api/muiload/nf-muiload-loadmuilibrarya)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface)

[Multilingual User Interface Functions](https://learn.microsoft.com/windows/desktop/Intl/multilingual-user-interface-functions)