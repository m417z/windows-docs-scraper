# GetProcAddress function

## Description

Retrieves the address of an exported function (also known as a procedure) or variable from the specified dynamic-link library (DLL).

## Parameters

### `hModule` [in]

A handle to the DLL module that contains the function or variable. The [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya), [LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa), [LoadPackagedLibrary](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-loadpackagedlibrary), or [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function returns this handle.

The **GetProcAddress** function does not retrieve addresses from modules that were loaded using the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa).

### `lpProcName` [in]

The function or variable name, or the function's ordinal value. If this parameter is an ordinal value, it must be in the low-order word; the high-order word must be zero.

## Return value

If the function succeeds, the return value is the address of the exported function or variable.

If the function fails, the return value is NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The spelling and case of a function name pointed to by *lpProcName* must be identical to that in the **EXPORTS** statement of the source DLL's module-definition (.def) file. The exported names of functions may differ from the names you use when calling these functions in your code. This difference is hidden by macros used in the SDK header files. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/Intl/conventions-for-function-prototypes).

The *lpProcName* parameter can identify the DLL function by specifying an ordinal value associated with the function in the **EXPORTS** statement. **GetProcAddress** verifies that the specified ordinal is in the range 1 through the highest ordinal value exported in the .def file. The function then uses the ordinal as an index to read the function's address from a function table.

If the .def file does not number the functions consecutively from 1 to *N* (where *N* is the number of exported functions), an error can occur where **GetProcAddress** returns an invalid, non-NULL address, even though there is no function with the specified ordinal.

If the function might not exist in the DLL module—for example, if the function is available only on Windows Vista but the application might be running on Windows XP—specify the function by name rather than by ordinal value and design your application to handle the case when the function is not available, as shown in the following code fragment.

```cpp
typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);

// Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.

   PGNSI pGNSI;
   SYSTEM_INFO si;

   ZeroMemory(&si, sizeof(SYSTEM_INFO));

   pGNSI = (PGNSI) GetProcAddress(
      GetModuleHandle(TEXT("kernel32.dll")),
      "GetNativeSystemInfo");
   if(NULL != pGNSI)
   {
      pGNSI(&si);
   }
   else
   {
       GetSystemInfo(&si);
   }
```

For the complete example that contains this code fragment, see [Getting the System Version](https://learn.microsoft.com/windows/win32/SysInfo/getting-the-system-version).

#### Examples

For an example, see [Using Run-Time Dynamic Linking](https://learn.microsoft.com/windows/win32/Dlls/using-run-time-dynamic-linking).

## See also

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/win32/Dlls/dynamic-link-library-functions)

[FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary)

[GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea)

[LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa)

[LoadPackagedLibrary](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-loadpackagedlibrary)

[Run-Time Dynamic Linking](https://learn.microsoft.com/windows/win32/Dlls/run-time-dynamic-linking)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)