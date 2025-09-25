# Bitmap::FromResource

## Description

The **Bitmap::FromResource** method creates a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object based on an application or DLL instance handle and the name of a bitmap resource.

## Parameters

### `hInstance` [in]

Type: **HINSTANCE**

Handle to an instance of a module whose executable file contains a bitmap resource.

### `bitmapName` [in]

Type: **const WCHAR***

Pointer to a null-terminated string that specifies the path name of the bitmap resource to be loaded. Alternatively, this parameter can consist of the resource identifier in the low-order word and zero in the high-order word. You can use the
[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro to create this value.

## Return value

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)***

This method returns a pointer to the new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)