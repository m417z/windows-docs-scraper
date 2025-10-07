# FMS\_TOOLBARLOAD structure

Contains information about custom buttons to be added to the File Manager toolbar. The buttons are provided by a File Manager extension DLL.

## Members

**dwSize**

Type: **DWORD**

The size, in bytes, of the structure. File Manager sets the size before calling the extension and checks the size after the extension procedure returns.

**lpButtons**

Type: **LPEXT\_BUTTON**

The address of an array of [**EXT\_BUTTON**](https://learn.microsoft.com/windows/win32/shell/ext-button) structures.

**cButtons**

Type: **WORD**

The number of [**EXT\_BUTTON**](https://learn.microsoft.com/windows/win32/shell/ext-button) structures in the array pointed to by the **lpButtons** member. This number equals the number of buttons and separators to add to the toolbar.

**cBitmaps**

Type: **WORD**

The number of buttons represented by the given bitmap.

**idBitmap**

Type: **WORD**

The identifier of a bitmap resource in the executable file for the extension DLL. The bitmap resource contains images for the number of buttons specified by **cBitmaps**. File Manager loads the bitmap resource and then uses it to display the buttons.

**hBitmap**

Type: **HBITMAP**

A handle to a bitmap that File Manager will use to obtain and display button images if **idBitmap** is 0.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Wfext.h |

## See also

[**FMEVENT\_TOOLBARLOAD**](https://learn.microsoft.com/windows/win32/shell/fmevent-toolbarload)

