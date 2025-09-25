# CopyIcon function

## Description

Copies the specified icon from another module to the current module.

## Parameters

### `hIcon` [in]

Type: **HICON**

A handle to the icon to be copied.

## Return value

Type: **HICON**

If the function succeeds, the return value is a handle to the duplicate icon.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CopyIcon** function enables an application or DLL to get its own handle to an icon owned by another module. If the other module is freed, the application icon will still be able to use the icon.

Before closing, an application must call the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function to free any system resources associated with the icon.

## See also

**Conceptual**

[CopyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copycursor)

[DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon)

[DrawIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawicon)

[DrawIconEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawiconex)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

**Reference**