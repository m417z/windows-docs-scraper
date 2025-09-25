# PickIconDlg function

## Description

[**PickIconDlg** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Displays a dialog box that allows the user to choose an icon from the selection available embedded in a resource such as an executable or DLL file.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

The handle of the parent window. This value can be **NULL**.

### `pszIconPath` [in, out]

Type: **PWSTR**

A pointer to a string that contains the null-terminated, fully qualified path of the default resource that contains the icons. If the user chooses a different resource in the dialog, this buffer contains the path of that file when the function returns. This buffer should be at least MAX_PATH characters in length, or the returned path may be truncated. You should verify that the path is valid before using it.

### `cchIconPath`

Type: **UINT**

The number of characters in *pszIconPath*, including the terminating **NULL** character.

### `piIconIndex` [in, out, optional]

Type: **int***

A pointer to an integer that on entry specifies the index of the initial selection and, when this function returns successfully, receives the index of the icon that was selected.

## Return value

Type: **int**

Returns 1 if successful; otherwise, 0.