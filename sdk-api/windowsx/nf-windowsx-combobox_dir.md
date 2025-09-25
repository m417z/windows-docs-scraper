# ComboBox_Dir macro

## Syntax

```cpp
int ComboBox_Dir(
   HWND    hwndCtl,
   UINT    attrs,
   LPCTSTR lpszFileSpec
);
```

## Return value

Type: **int**

If the message succeeds, the return value is the zero-based index of the last name added to the list. If an error occurs, the return value is CB_ERR. If there is insufficient space to store the new strings, the return value is CB_ERRSPACE.

## Description

Adds names to the list displayed by a combo box. The macro adds the names of directories and files that match a specified string and set of file attributes. It can also add mapped drive letters to the list in a combo box. You can use this macro or send the [CB_DIR](https://learn.microsoft.com/windows/desktop/Controls/cb-dir) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `attrs`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The attributes of the files or directories to be added to the list in a combo box. For more information, see [CB_DIR](https://learn.microsoft.com/windows/desktop/Controls/cb-dir).

### `lpszFileSpec`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the null-terminated string that specifies an absolute path, relative path, or filename. An absolute path can begin with a drive letter (for example, d:\) or a UNC name (for example, \\ machinename\ sharename).

## Remarks

For more information, see [CB_DIR](https://learn.microsoft.com/windows/desktop/Controls/cb-dir).