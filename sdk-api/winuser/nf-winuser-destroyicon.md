# DestroyIcon function

## Description

Destroys an icon and frees any memory the icon occupied.

## Parameters

### `hIcon` [in]

Type: **HICON**

A handle to the icon to be destroyed. The icon must not be in use.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

It is only necessary to call **DestroyIcon** for icons and cursors created with the following functions: [CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex) (if called without the **LR_SHARED** flag), [CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect), and [CopyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyicon). Do not use this function to destroy a shared icon. A shared icon is valid as long as the module from which it was loaded remains in memory. The following functions obtain a shared icon.

* [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)
* [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) (if you use the **LR_SHARED** flag)
* [CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage) (if you use the **LR_COPYRETURNORG** flag and the *hImage* parameter is a shared icon)
* [CreateIconFromResource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresource)
* [CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex) (if you use the **LR_SHARED** flag)

## See also

**Conceptual**

[CopyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyicon)

[CreateIconFromResource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresource)

[CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex)

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

**Reference**