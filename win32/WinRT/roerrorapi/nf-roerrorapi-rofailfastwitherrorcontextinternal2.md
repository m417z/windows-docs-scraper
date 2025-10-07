# RoFailFastWithErrorContextInternal2 function

Raises a non-continuable exception in the current process, and also allows you to include additional error context not already captured by the operating system (OS).

## Parameters

`hrError`

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The **HRESULT** associated with the current error. The exception is raised for any value of *hrError*.

`cStowedExceptions`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of elements in the *aStowedExceptionPointers* array.

`aStowedExceptionPointers`

Type: **[PSTOWED_EXCEPTION_INFORMATION_V2](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-v2)\[\]**

An array of pointers to [**STOWED_EXCEPTION_INFORMATION_V2**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-v2) structures. Each structure contains info describing a stowed exception. The info in these structures is then submitted to Windows Error Reporting (WER) along with the stowed exception information that was captured by the platform.

## Return value

This function doesn't return a value.

## Remarks

**RoFailFastWithErrorContextInternal2** isn't associated with an import library nor a header file. You can call it by first using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) function (to load `ComBase.dll`), and then by calling the [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) function to retrieve the address of **RoFailFastWithErrorContextInternal2**.

For more info, see [RoFailFastWithErrorContext function](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext).

## Requirements
|   |   |
| ---- |:---- |
| **Target Platform** | Windows |
| **Header** | N/A |
| **Library** | N/A |
| **DLL** | ComBase.dll |

## See also

* [RoFailFastWithErrorContext function](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rofailfastwitherrorcontext)