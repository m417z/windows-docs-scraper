# LoadBitmapW function

## Description

[**LoadBitmap** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) and [DrawFrameControl](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawframecontrol).]

The **LoadBitmap** function loads the specified bitmap resource from a module's executable file.

## Parameters

### `hInstance` [in]

A handle to the instance of the module whose executable file contains the bitmap to be loaded.

### `lpBitmapName` [in]

A pointer to a null-terminated string that contains the name of the bitmap resource to be loaded. Alternatively, this parameter can consist of the resource identifier in the low-order word and zero in the high-order word. The [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro can be used to create this value.

## Return value

If the function succeeds, the return value is the handle to the specified bitmap.

If the function fails, the return value is **NULL**.

## Remarks

If the bitmap pointed to by the *lpBitmapName* parameter does not exist or there is insufficient memory to load the bitmap, the function fails.

**LoadBitmap** creates a compatible bitmap of the display, which cannot be selected to a printer. To load a bitmap that you can select to a printer, call [LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea) and specify LR_CREATEDIBSECTION to create a DIB section. A DIB section can be selected to any device.

An application can use the **LoadBitmap** function to access predefined bitmaps. To do so, the application must set the *hInstance* parameter to **NULL** and the *lpBitmapName* parameter to one of the following values.

| Bitmap name | Bitmap name |
| --- | --- |
| OBM_BTNCORNERS | OBM_OLD_RESTORE |
| OBM_BTSIZE | OBM_OLD_RGARROW |
| OBM_CHECK | OBM_OLD_UPARROW |
| OBM_CHECKBOXES | OBM_OLD_ZOOM |
| OBM_CLOSE | OBM_REDUCE |
| OBM_COMBO | OBM_REDUCED |
| OBM_DNARROW | OBM_RESTORE |
| OBM_DNARROWD | OBM_RESTORED |
| OBM_DNARROWI | OBM_RGARROW |
| OBM_LFARROW | OBM_RGARROWD |
| OBM_LFARROWD | OBM_RGARROWI |
| OBM_LFARROWI | OBM_SIZE |
| OBM_MNARROW | OBM_UPARROW |
| OBM_OLD_CLOSE | OBM_UPARROWD |
| OBM_OLD_DNARROW | OBM_UPARROWI |
| OBM_OLD_LFARROW | OBM_ZOOM |
| OBM_OLD_REDUCE | OBM_ZOOMD |

Bitmap names that begin with OBM_OLD represent bitmaps used by 16-bit versions of Windows earlier than 3.0.

For an application to use any of the OBM_ constants, the constant OEMRESOURCE must be defined before the Windows.h header file is included.

The application must call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete each bitmap handle returned by the **LoadBitmap** function.

#### Examples

For an example, see Example of Menu-Item Bitmaps in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

> [!NOTE]
> The winuser.h header defines LoadBitmap as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[DrawFrameControl](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawframecontrol)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

[LoadImage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadimagea)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)