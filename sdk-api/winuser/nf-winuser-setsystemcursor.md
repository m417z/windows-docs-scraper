# SetSystemCursor function

## Description

Enables an application to customize the system cursors. It replaces the contents of the system cursor specified by the *id* parameter with the contents of the cursor specified by the *hcur* parameter and then destroys *hcur*.

## Parameters

### `hcur` [in]

Type: **HCURSOR**

A handle to the cursor. The function replaces the contents of the system cursor specified by *id* with the contents of the cursor handled by *hcur*.

The system destroys *hcur* by calling the [DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor) function. Therefore, *hcur* cannot be a cursor loaded using the [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora) function. To specify a cursor loaded from a resource, copy the cursor using the [CopyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copycursor) function, then pass the copy to **SetSystemCursor**.

### `id` [in]

Type: **DWORD**

The system cursor to replace with the contents of *hcur*. This parameter can be one of the following values.

| Value | Meaning |
|---|---|
| **OCR\_NORMAL**<br>`32512` | Normal select |
| **OCR\_IBEAM**<br>`32513` | Text select |
| **OCR\_WAIT**<br>`32514` | Busy |
| **OCR\_CROSS**<br>`32515` | Precision select |
| **OCR\_UP**<br>`32516` | Alternate select |
| **OCR\_SIZENWSE**<br>`32642` | Diagonal resize 1 |
| **OCR\_SIZENESW**<br>`32643` | Diagonal resize 2 |
| **OCR\_SIZEWE**<br>`32644` | Horizontal resize |
| **OCR\_SIZENS**<br>`32645` | Vertical resize |
| **OCR\_SIZEALL**<br>`32646` | Move |
| **OCR\_NO**<br>`32648` | Unavailable |
| **OCR\_HAND**<br>`32649` | Link select |
| **OCR\_APPSTARTING**<br>`32650` | Working in background |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For an application to use any of the OCR_ constants, the constant **OEMRESOURCE** must be defined before the Windows.h header file is included.

## See also

**Conceptual**

[Cursors](https://learn.microsoft.com/windows/desktop/menurc/cursors)

[DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadCursorFromFile](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursorfromfilea)

**Reference**

[SetCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setcursor)