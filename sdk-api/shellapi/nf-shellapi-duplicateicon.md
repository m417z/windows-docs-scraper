# DuplicateIcon function

## Description

Creates a duplicate of a specified icon.

## Parameters

### `hInst` [in]

Type: **HINSTANCE**

### `hIcon` [in]

Type: **HICON**

Handle to the icon to be duplicated.

## Return value

Type: **HICON**

If successful, the function returns the handle to the new icon that was created; otherwise, **NULL**.

## Remarks

When it is no longer needed, the caller is responsible for freeing the icon handle returned by **DuplicateIcon** by calling the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.