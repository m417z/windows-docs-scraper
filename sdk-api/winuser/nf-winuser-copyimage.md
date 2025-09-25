# CopyImage function

## Description

Creates a new image (icon, cursor, or bitmap) and copies the attributes of the specified image to the new one. If necessary, the function stretches the bits to fit the desired size of the new image.

## Parameters

### `h` [in]

Type: **HANDLE**

A handle to the image to be copied.

### `type` [in]

Type: **UINT**

The type of image to be copied. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IMAGE_BITMAP**<br><br>0 | Copies a bitmap. |
| **IMAGE_CURSOR**<br><br>2 | Copies a cursor. |
| **IMAGE_ICON**<br><br>1 | Copies an icon. |

### `cx` [in]

Type: **int**

The desired width, in pixels, of the image. If this is zero, then the returned image will have the same width as the original *hImage*.

### `cy` [in]

Type: **int**

The desired height, in pixels, of the image. If this is zero, then the returned image will have the same height as the original *hImage*.

### `flags` [in]

Type: **UINT**

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LR_COPYDELETEORG**<br><br>0x00000008 | Deletes the original image after creating the copy. |
| **LR_COPYFROMRESOURCE**<br><br>0x00004000 | Tries to reload an icon or cursor resource from the original resource file rather than simply copying the current image. This is useful for creating a different-sized copy when the resource file contains multiple sizes of the resource. Without this flag, **CopyImage** stretches the original image to the new size. If this flag is set, **CopyImage** uses the size in the resource file closest to the desired size. This will succeed only if *hImage* was loaded by [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) or [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora), or by [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) with the LR_SHARED flag. |
| **LR_COPYRETURNORG**<br><br>0x00000004 | Returns the original *hImage* if it satisfies the criteria for the copy—that is, correct dimensions and color depth—in which case the **LR_COPYDELETEORG** flag is ignored. If this flag is not specified, a new object is always created. |
| **LR_CREATEDIBSECTION**<br><br>0x00002000 | If this is set and a new bitmap is created, the bitmap is created as a DIB section. Otherwise, the bitmap image is created as a device-dependent bitmap. This flag is only valid if *uType* is **IMAGE_BITMAP**. |
| **LR_DEFAULTCOLOR**<br><br>0x00000000 | Uses the default color format. |
| **LR_DEFAULTSIZE**<br><br>0x00000040 | Uses the width or height specified by the system metric values for cursors or icons, if the *cxDesired* or *cyDesired* values are set to zero. If this flag is not specified and *cxDesired* and *cyDesired* are set to zero, the function uses the actual resource size. If the resource contains multiple images, the function uses the size of the first image. |
| **LR_MONOCHROME**<br><br>0x00000001 | Creates a new monochrome image. |

## Return value

Type: **HANDLE**

If the function succeeds, the return value is the handle to the newly created image.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When you are finished using the resource, you can release its associated memory by calling one of the functions in the following table.

| Resource | Release function |
| --- | --- |
| Bitmap | [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) |
| Cursor | [DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor) |
| Icon | [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) |

The system automatically deletes the resource when its process terminates, however, calling the appropriate function saves memory and decreases the size of the process's working set.

## See also

**Conceptual**

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)