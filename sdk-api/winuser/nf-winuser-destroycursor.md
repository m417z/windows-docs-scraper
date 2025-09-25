# DestroyCursor function

## Description

Destroys a cursor and frees any memory the cursor occupied. Do not use this function to destroy a shared cursor.

## Parameters

### `hCursor` [in]

Type: **HCURSOR**

A handle to the cursor to be destroyed. The cursor must not be in use.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DestroyCursor** function destroys a nonshared cursor. Do not use this function to destroy a shared cursor. A shared cursor is valid as long as the module from which it was loaded remains in memory. The following functions obtain a shared cursor:

* [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)
* [LoadCursorFromFile](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursorfromfilea)
* [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) (if you use the **LR_SHARED** flag)
* [CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage) (if you use the **LR_COPYRETURNORG** flag and the *hImage* parameter is a shared cursor)

## See also

**Conceptual**

[CopyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copycursor)

[CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage)

[CreateCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createcursor)

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadCursorFromFile](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursorfromfilea)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

**Reference**