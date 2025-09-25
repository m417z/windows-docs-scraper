# CopyCursor macro

## Description

Copies the specified cursor.

## Parameters

### `pcur` [in]

Type: **HCURSOR**

A handle to the cursor to be copied.

## Remarks

**CopyCursor** enables an application or DLL to obtain the handle to a cursor shape owned by another module. Then if the other module is freed, the application is still able to use the cursor shape.

Before closing, an application must call the [DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor) function to free any system resources associated with the cursor.

Do not use the **CopyCursor** function for animated cursors. Instead, use the [CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage) function.

**CopyCursor** is implemented as a call to the [CopyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyicon) function.

``` syntax
#define CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))
```

## Return value

Type: **HCURSOR**

If the call succeeds, the return value is a handle to the duplicate cursor.

If the call fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Syntax

```cpp
HCURSOR CopyCursor(
  [in] pcur
);
```

## See also

**Conceptual**

[CopyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyicon)

[CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage)

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor)

[GetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcursor)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)

[ShowCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcursor)