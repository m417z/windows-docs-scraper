# ImageList_LoadBitmap macro

## Syntax

```cpp
HIMAGELIST ImageList_LoadBitmap(
   HINSTANCE hi,
   LPCTSTR   lpbmp,
   int       cx,
   int       cGrow,
   COLORREF  crMask
);
```

## Return value

Type: **HIMAGELIST**

Returns the handle to the image list if successful, or **NULL** otherwise.

## Description

Calls the [ImageList_LoadImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_loadimagea) function to create an image list from the specified bitmap resource.

## Parameters

### `hi`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the instance that contains the bitmap resource. This parameter is **NULL** if you are loading an OEM bitmap.

### `lpbmp`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The image to load. If the *hi* parameter is non-**NULL**, *lpbmp* is the address of a null-terminated string that contains the name of the image resource in the *hi* module. If *hi* is **NULL**, the [LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85)) of this parameter must be the identifier of an OEM bitmap to load. To create this value, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro with one of the OEM bitmap identifiers defined in WINUSER.H. These identifiers have the OBM_ prefix.

### `cx`

Type: **int**

The width of each image. The height of each image and the initial number of images are inferred by the dimensions of the specified bitmap.

### `cGrow`

Type: **int**

The number of images by which the image list can grow when the system needs to make room for new images. This parameter represents the number of new images that the resized image list can contain.

### `crMask`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The color used to generate a mask. Each pixel of this color in the specified bitmap is changed to black, and the corresponding bit in the mask is set to 1. If this parameter is the CLR_NONE value, no mask is generated.