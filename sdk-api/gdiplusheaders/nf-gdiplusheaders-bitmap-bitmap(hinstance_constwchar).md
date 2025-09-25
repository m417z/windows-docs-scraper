# Bitmap::Bitmap(IN HINSTANCE,IN const WCHAR)

## Description

Creates a **Bitmap::Bitmap** object based on an application or DLL instance handle and the name of a bitmap resource.

## Parameters

### `hInstance` [in]

Type: **HINSTANCE**

Handle to an instance of a module whose executable file contains a bitmap resource.

### `bitmapName` [in]

Type: **const WCHAR***

Pointer to a null-terminated string that specifies the path name of the bitmap resource to be loaded. Alternatively, this parameter can consist of the resource identifier in the low-order word and zero in the high-order word. You can use the
**MAKEINTRESOURCE** macro to create this value.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::FromResource](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-fromresource)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)