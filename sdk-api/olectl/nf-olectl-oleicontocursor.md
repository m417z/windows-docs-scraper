# OleIconToCursor function

## Description

Converts an icon to a cursor.

## Parameters

### `hinstExe` [in]

This parameter is ignored.

### `hIcon` [in]

A handle to the icon to be converted.

## Return value

The function returns a handle to the new cursor object. The caller is responsible for deleting this cursor with the [DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor) function. If the conversion could not be completed, the return value is **NULL**.

## Remarks

This function calls the [CopyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copycursor) function.