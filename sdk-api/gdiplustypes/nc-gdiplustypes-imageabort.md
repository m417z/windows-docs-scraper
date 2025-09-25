## Description

**ImageAbort** is the signature of a callback function that you implement in your application. During the process of creating or retrieving a thumbnail image, or drawing an image, GDI+ calls this function to give you the opportunity to abort the process.

Examples of the callback function in use are the corresponding parameters of the [Image::GetThumbnailImage method](https://learn.microsoft.com/windows/win32/api/gdiplusheaders/nf-gdiplusheaders-image-getthumbnailimage), and the [Graphics::DrawImage method](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(image_constpointf_int_real_real_real_real_unit_constimageattributes_drawimageabort_void).md).

## Parameters

### `unnamedParam1`

Type: **[VOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The callback data.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Return **TRUE** to abort; otherwise **FALSE**.

## Remarks

## See also

[Image::GetThumbnailImage method](https://learn.microsoft.com/windows/win32/api/gdiplusheaders/nf-gdiplusheaders-image-getthumbnailimage)

[Graphics::DrawImage method](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(image_constpointf_int_real_real_real_real_unit_constimageattributes_drawimageabort_void).md)