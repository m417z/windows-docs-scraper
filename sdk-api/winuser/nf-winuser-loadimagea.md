# LoadImageA function

## Description

Loads an icon, cursor, animated cursor, or bitmap.

## Parameters

### `hInst` [in, optional]

Type: **HINSTANCE**

A handle to the module of either a DLL or executable (.exe) that contains the image to be loaded. For more information, see [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea). Note that as of 32-bit Windows, an instance handle (**HINSTANCE**), such as the application instance handle exposed by system function call of [WinMain](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-winmain), and a module handle (**HMODULE**) are the same thing.

To load a predefined image or a standalone resource (icon, cursor, or bitmap file), set this parameter to **NULL**.

### `name` [in]

Type: **LPCTSTR**

The image to be loaded.

If the *hInst* parameter is non-**NULL** and the *fuLoad* parameter omits **LR_LOADFROMFILE**, *name* specifies the image resource in the *hInst* module.

If the image resource is to be loaded by name from the module, the *name* parameter is a pointer to a null-terminated string that contains the name of the image resource.

If the image resource is to be loaded by ordinal from the module, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to convert the image ordinal into a form that can be passed to the **LoadImage** function.

If the *hInst* parameter is **NULL** and the *fuLoad* parameter omits the **LR_LOADFROMFILE** value and includes the **LR_SHARED**, the *name* specifies the predefined image to load.

The predefined image identifiers are defined in `Winuser.h` and have the following prefixes:

| Prefix | Meaning |
|---|---|
| **OBM\_** | OEM bitmaps. Use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to pass these. |
| **OIC\_** | OEM icons. Use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to pass these. |
| **OCR\_** | OEM cursors. Use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to pass these. |
| **IDI\_** | [Standard icons](https://learn.microsoft.com/windows/win32/menurc/about-icons) |
| **IDC\_** | [Standard cursors](https://learn.microsoft.com/windows/win32/menurc/about-cursors) |

To pass OEM image identifiers constants to the **LoadImage** function, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. For example, to load the **OCR_NORMAL** cursor, pass `MAKEINTRESOURCE(OCR_NORMAL)` as the *name* parameter, **NULL** as the *hInst* parameter, and **LR_SHARED** as one of the flags to the *fuLoad* parameter.

If the *hInst* parameter is **NULL** and the *fuLoad* parameter includes the **LR_LOADFROMFILE** value, *name* is the name of the file that contains the standalone resource (icon, cursor, or bitmap file), - for example, `c:\myicon.ico`.

For more information, see the Remarks section below.

### `type` [in]

Type: **UINT**

The type of image to be loaded.

This parameter can be one of the following values:

| Value | Meaning |
|---|---|
| **IMAGE\_BITMAP** | Loads a bitmap. |
| **IMAGE\_CURSOR** | Loads a cursor. |
| **IMAGE\_ICON** | Loads an icon. |

### `cx` [in]

Type: **int**

The width, in pixels, of the icon or cursor. If this parameter is zero and the *fuLoad* parameter is **LR_DEFAULTSIZE**, the function uses the **SM_CXICON** or **SM_CXCURSOR** system metric value to set the width. If this parameter is zero and **LR_DEFAULTSIZE** is not used, the function uses the actual resource width.

### `cy` [in]

Type: **int**

The height, in pixels, of the icon or cursor. If this parameter is zero and the *fuLoad* parameter is **LR_DEFAULTSIZE**, the function uses the **SM_CYICON** or **SM_CYCURSOR** system metric value to set the height. If this parameter is zero and **LR_DEFAULTSIZE** is not used, the function uses the actual resource height.

### `fuLoad` [in]

Type: **UINT**

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **LR_CREATEDIBSECTION**<br><br>0x00002000 | When the *uType* parameter specifies **IMAGE_BITMAP**, causes the function to return a DIB section bitmap rather than a compatible bitmap. This flag is useful for loading a bitmap without mapping it to the colors of the display device. |
| **LR_DEFAULTCOLOR**<br><br>0x00000000 | The default flag; it does nothing. All it means is "not **LR_MONOCHROME**". |
| **LR_DEFAULTSIZE**<br><br>0x00000040 | Uses the width or height specified by the system metric values for cursors or icons, if the *cxDesired* or *cyDesired* values are set to zero. If this flag is not specified and *cxDesired* and *cyDesired* are set to zero, the function uses the actual resource size. If the resource contains multiple images, the function uses the size of the first image. |
| **LR_LOADFROMFILE**<br><br>0x00000010 | Loads the standalone image from the file specified by *name* (icon, cursor, or bitmap file). |
| **LR_LOADMAP3DCOLORS**<br><br>0x00001000 | Searches the color table for the image and replaces the following shades of gray with the corresponding 3-D color.<br><br>* Dk Gray, RGB(128,128,128) with **COLOR_3DSHADOW**<br>* Gray, RGB(192,192,192) with **COLOR_3DFACE**<br>* Lt Gray, RGB(223,223,223) with **COLOR_3DLIGHT**<br><br>Do not use this option if you are loading a bitmap with a color depth greater than 8bpp. |
| **LR_LOADTRANSPARENT**<br><br>0x00000020 | Retrieves the color value of the first pixel in the image and replaces the corresponding entry in the color table with the default window color (**COLOR_WINDOW**). All pixels in the image that use that entry become the default window color. This value applies only to images that have corresponding color tables.<br><br>Do not use this option if you are loading a bitmap with a color depth greater than 8bpp.<br><br>If *fuLoad* includes both the **LR_LOADTRANSPARENT** and **LR_LOADMAP3DCOLORS** values, **LR_LOADTRANSPARENT** takes precedence. However, the color table entry is replaced with **COLOR_3DFACE** rather than **COLOR_WINDOW**. |
| **LR_MONOCHROME**<br><br>0x00000001 | Loads the image in black and white. |
| **LR_SHARED**<br><br>0x00008000 | Shares the image handle if the image is loaded multiple times. If **LR_SHARED** is not set, a second call to **LoadImage** for the same resource will load the image again and return a different handle. <br><br>When you use this flag, the system will destroy the resource when it is no longer needed.<br><br>Do not use **LR_SHARED** for images that have non-standard sizes, that may change after loading, or that are loaded from a file.<br><br>When loading a system icon or cursor, you must use **LR_SHARED** or the function will fail to load the resource.<br><br>This function finds the first image in the cache with the requested resource name, regardless of the size requested. |
| **LR_VGACOLOR**<br><br>0x00000080 | Uses true VGA colors. |

## Return value

Type: **HANDLE**

If the function succeeds, the return value is the handle of the newly loaded image.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource)(*name*) is **TRUE**, then *name* specifies the integer identifier of the given resource. Otherwise, it is a pointer to a null-terminated string. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource. For example, the string "#258" represents the identifier 258.

When you are finished using a bitmap, cursor, or icon you loaded without specifying the **LR_SHARED** flag, you can release its associated memory by calling one of the functions in the following table.

| Resource | Release function |
| --- | --- |
| Bitmap | [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) |
| Cursor | [DestroyCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroycursor) |
| Icon | [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) |

The system automatically deletes these resources when the process that created them terminates; however, calling the appropriate function saves memory and decreases the size of the process's working set.

#### Examples

For an example, see [Using Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/using-window-classes).

> [!NOTE]
> The winuser.h header defines LoadImage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CopyImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyimage)

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapa)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

**Other Resources**

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)