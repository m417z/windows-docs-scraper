# LoadResource function

## Description

Retrieves a handle that can be used to obtain a pointer to the first byte of the specified resource in memory.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to the module whose executable file contains the resource. If *hModule* is **NULL**, the system loads the resource from the module that was used to create the current process.

### `hResInfo` [in]

Type: **HRSRC**

A handle to the resource to be loaded. This handle is returned by the [FindResource](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea) or [FindResourceEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa) function.

## Return value

Type: **HGLOBAL**

If the function succeeds, the return value is a handle to the data associated with the resource.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The return type of **LoadResource** is **HGLOBAL** for backward compatibility, not because the function returns a handle to a global memory block. Do not pass this handle to the [GlobalLock](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globallock) or [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function. To obtain a pointer to the first byte of the resource data, call the [LockResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-lockresource) function; to obtain the size of the resource, call [SizeofResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-sizeofresource).

[GlobalSize](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalsize) returns 0 for a resource HGLOBAL. As a result, any APIs that depend on GlobalSize to determine the size of the HGLOBAL will not function correctly. For example, use [SHCreateMemStream](https://learn.microsoft.com/windows/win32/api/shlwapi/nf-shlwapi-shcreatememstream) instead of [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-createstreamonhglobal).

To use a resource immediately, an application should use the following resource-specific functions to find and load the resource in one call.

| Function | Action | To remove resource |
|-----------------|------------------------------------------|---------------------------|
| [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) | Loads and formats a message-table entry | No action needed |
| [LoadAccelerators](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadacceleratorsa) | Loads an accelerator table | [DestroyAcceleratorTable](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyacceleratortable) |
| [LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapa) | Loads a bitmap resource | [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) |
| [LoadCursor](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadcursora) | Loads a cursor resource | [DestroyCursor](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroycursor) |
| [LoadIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadicona) | Loads an icon resource | [DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) |
| [LoadMenu](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadmenua) | Loads a menu resource | [DestroyMenu](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroymenu) |
| [LoadString](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadstringa) | Loads a string resource | No action needed |

For example, an application can use the [LoadIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadicona) function to load an icon for display on the screen, followed by [DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) when done.

## Examples

For an example see [Updating Resources](https://learn.microsoft.com/windows/win32/menurc/using-resources#updating-resources).

## See also

[FindResource](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea)

[FindResourceEx](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[LoadModule](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-loadmodule)

[LockResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-lockresource)