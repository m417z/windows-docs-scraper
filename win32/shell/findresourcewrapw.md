# FindResourceWrapW function

\[**FindResourceWrapW** is available for use in Windows XP. It may not be available in subsequent versions. You should use [**FindResourceW**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea) instead.\]

Determines the location of a resource with the specified type and name, in the specified module.

> [!Note]
> **FindResourceWrapW** is a wrapper for the **FindResourceW** function. See [**FindResource**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea) for further usage notes.

## Parameters

*hModule* \[in\]

Type: **HMODULE**

A handle to the module whose executable file contains the resource. A value of **NULL** specifies the module handle associated with the image file that the operating system used to create the current process.

*lpName* \[in\]

Type: **LPCWSTR**

The name of the resource. For more information, see [**FindResource**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea).

*lpType* \[in\]

Type: **LPCWSTR**

A pointer to a string that specifies the resource type. For more information, see [**FindResource**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea).

## Return value

Type: **HRSRC**

If the function succeeds, the return value is a handle to the specified resource's information block. To obtain a handle to the resource, pass this handle to the [**LoadResource**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource) function.

If the function fails, the return value is **NULL**. To get extended error information, call the [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If you need to specify a particular localization, use the [**FindResourceEx**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa) function rather than **FindResourceWrapW**.

**FindResourceWrapW** provides the ability to use Unicode strings in older operating systems. The preferred method is to use [**FindResourceW**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea) in conjunction with the Microsoft Layer for Unicode (MSLU).

**FindResourceWrapW** must be called directly from Shlwapi.dll, using ordinal 66.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | None |
| DLL<br> | Shlwapi.dll (version 5.0 or later) |
| Unicode and ANSI names<br> | **FindResourceWrapW** (Unicode)<br> |

## See also

[**FindResource**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea)

