# SizeofResource function

## Description

Retrieves the size, in bytes, of the specified resource.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to the module whose executable file contains the resource. Default is the module used to create the current process.

### `hResInfo` [in]

Type: **HRSRC**

A handle to the resource. This handle must be created by using the [FindResource](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea) or [FindResourceEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa) function.

## Return value

Type: **DWORD**

If the function succeeds, the return value is the number of bytes in the resource.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[FindResource](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea)

[FindResourceEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa)

**Reference**

[Resources](https://msdn.microsoft.com/ff321356-c999-4021-a537-fbe863996e24)