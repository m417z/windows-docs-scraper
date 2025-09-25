# CreateMappedBitmap function

## Description

Creates a bitmap for use in a toolbar.

## Parameters

### `hInstance`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the module instance with the executable file that contains the bitmap resource.

### `idBitmap`

Type: **[INT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Resource identifier of the bitmap resource.

### `wFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bitmap flag. This parameter can be zero or the following value:

| Value | Meaning |
| --- | --- |
| **CMB_MASKED** | Uses a bitmap as a mask. |

### `lpColorMap` [in]

Type: **LPCOLORMAP**

Pointer to a [COLORMAP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-colormap) structure that contains the color information needed to map the bitmaps. If this parameter is **NULL**, the function uses the default color map.

### `iNumMaps`

Type: **int**

Number of color maps pointed to by
*lpColorMap*.

## Return value

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the handle to the bitmap if successful, or **NULL** otherwise. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function creates a new bitmap using the bitmap data and colors specified by the bitmap resource and the color mapping information.

This function is fully supported only for images with color maps; that is, images with 256 or fewer colors.

#### Examples

The following example code creates a bitmap from a resource and makes the color black appear transparent by mapping it to the system color for a button face.

```cpp
DWORD backgroundColor = GetSysColor(COLOR_BTNFACE);
COLORMAP colorMap;
colorMap.from = RGB(0, 0, 0);
colorMap.to = backgroundColor;
HBITMAP hbm = CreateMappedBitmap(g_hInst, IDB_BITMAP1, 0, &colorMap, 1);
```