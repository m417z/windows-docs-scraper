# DROPFILES structure

## Description

Defines the [CF_HDROP](https://learn.microsoft.com/windows/desktop/shell/clipboard) clipboard format. The data that follows is a double null-terminated list of file names.

## Members

### `pFiles`

Type: **DWORD**

The offset of the file list from the beginning of this structure, in bytes.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The drop point. The coordinates depend on **fNC**.

### `fNC`

Type: **BOOL**

A nonclient area flag. If this member is **TRUE**, **pt** specifies the screen coordinates of a point in a window's nonclient area. If it is **FALSE**, **pt** specifies the client coordinates of a point in the client area.

### `fWide`

Type: **BOOL**

A value that indicates whether the file contains ANSI or Unicode characters. If the value is zero, the file contains ANSI characters. Otherwise, it contains Unicode characters.